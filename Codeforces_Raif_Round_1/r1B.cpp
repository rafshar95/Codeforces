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

const int maxn = 300*1001;

int t, n;

char c[maxn];

int main(){
  scanf("%d", &t);
  for(int l=0;l<t;l++){
    scanf("%d", &n);
    scanf("%c", &c[0]);
    for(int i=0;i<n;i++)
      scanf("%c", &c[i]);
    int ans=-1;
    for(int i=0;i<n;i++){
      if(c[i]!='>' && c[i]!='-')
        break;
      if(i==n-1)
        ans=n;
    }
    if(ans==-1){
      for(int i=0;i<n;i++){
        if(c[i]!='<' && c[i]!='-')
          break;
        if(i==n-1)
          ans=n;
      }
    }
    if(ans==-1){
      ans=0;
      for(int i=0;i<n;i++)
        if(c[i]=='-'){
          ans++;
        }
        else if(c[(i+n-1)%n]=='-'){
          ans++;
        }
    }
    cout<<ans<<endl;
  }
  return 0;
}
