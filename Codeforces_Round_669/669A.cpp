#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <deque>

using namespace std;

int cnt[3];
int n, t;

int a[1001];
int main(){
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>n;
    cnt[0]=0;
    cnt[1]=0;
    for(int i=1;i<=n;i++){
      cin>>a[i];
      cnt[a[i]]++;
    }
    if(cnt[0]>=n/2){
      cout<<cnt[0]<<endl;
      for(int i=1;i<=cnt[0];i++)
        cout<<0<<" ";
      cout<<endl;
      continue;
    }
    int k = n/2;
    if(k%2==1)
      k++;
    cout<<k<<endl;
    for(int i=1;i<=k;i++)
      cout<<1<<" ";
    cout<<endl;
  }


  return 0;
}
