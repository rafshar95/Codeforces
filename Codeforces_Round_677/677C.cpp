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
int a[3000*101];
int main(){
  scanf("%d", &t);
  for(int l=0;l<t;l++){
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
      scanf("%d", &a[i]);
    int mx = 0;
    bool no_dom = true;
    for(int i=1;i<=n;i++){
      mx=max(mx, a[i]);
      if(i>1 && a[i]!=a[i-1])
        no_dom = false;
    }
    if(no_dom){
      cout<<"-1"<<endl;
      continue;
    }
    for(int i=1;i<=n;i++){
      if(a[i]==mx){
        if(i>1 && a[i]!=a[i-1]){
          cout<<i<<endl;
          break;
        }
        if(i<n && a[i]!=a[i+1]){
          cout<<i<<endl;
          break;
        }
      }
    }
  }

  return 0;
}
