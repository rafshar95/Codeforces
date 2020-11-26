#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <numeric>

using namespace std;

const int maxn = 201 * 1000;

set< pair<int,int> > st;

int t, n;
int a[maxn];

int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>n;
    st.clear();
    for(int i=1;i<=n;i++){
      cin>>a[i];
      if(i!=1 && i!=n)
        st.insert(make_pair(a[i],i));
    }
    int p1 = 1;
    int p2 = n+1;
    int l_mx = a[1];
    int r_mx= 0, cnt =0;
    bool printed = false;
    while(p1<=n-2){
      while(p2-1 > p1 && a[p2-1]<=l_mx){
        p2--;
        st.erase(make_pair(a[p2],p2));
        if(a[p2]==l_mx)
          cnt++;
        r_mx = max(r_mx, a[p2]);
      }
      if(st.size()){
        int pos = st.begin() -> second;
        if(a[pos]==l_mx && r_mx == l_mx && !printed){
          printed = true;
          cout<<"YES"<<endl;
          cout<<p1<<" "<<p2-p1-1<<" "<<n-p2+1<<endl;
        }
        else if(a[pos]>l_mx && cnt>=2 && a[p2]== l_mx && !printed){
          printed = true;
          cout<<"YES"<<endl;
          cout<<p1<<" "<<p2-p1<<" "<<n-p2<<endl;
        }
      }
      else{
        if(cnt>=2 && a[p2]==l_mx && !printed){
          printed = true;
          cout<<"YES"<<endl;
          cout<<p1<<" "<<1<<" "<<n - p1 - 1<<endl;
          break;
        }
      }
      if(p2==p1+1){
        if(a[p2]==l_mx)
          cnt--;
        if(cnt==0)
          break;
        p2++;
      }
      p1++;
      if(a[p1]>l_mx){
        cnt=0;
        l_mx=a[p1];
      }
      st.erase(make_pair(a[p1], p1));
    }
    if(!printed)
      cout<<"NO"<<endl;
  }

  return 0;
}
