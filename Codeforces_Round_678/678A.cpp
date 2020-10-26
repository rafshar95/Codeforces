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

int t, n, m;

int a[110];
int main(){
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>n>>m;
    int s=0;
    for(int i=0;i<n;i++){
      cin>>a[i];
      s+=a[i];
    }
    if(s==m)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}
