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

int t, n;

vector<int> v;

pair<int,int> a[110];
int b[110];
int main(){
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>n;
    v.clear();
    for(int i=1;i<=n;i++){
      cin>>a[i].first;
      v.push_back(a[i].first);
      a[i].second=i;
    }
    sort(v.begin(), v.end(), greater<int>());

    sort(a+1, a+n+1);
    for(int i=1;i<=n;i++){
      if(i%2==1)
        b[a[i].second] = v[i-1];
      else
        b[a[i].second] = -v[i-1];
    }
    for(int i=1;i<=n;i++)
      cout<<b[i]<<" ";
    cout<<endl;

  }
  return 0;
}
