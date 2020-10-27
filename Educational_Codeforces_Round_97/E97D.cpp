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

const int maxn = 2*100*1001;

int t, n;

int q[maxn], h[maxn];
int main(){
  scanf("%d", &t);
  for(int l=0;l<t;l++){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
      scanf("%d", &q[i]);
    }
    memset(h, 0, sizeof h);
    int head=1, tail=2;
    h[head]=0;
    int ans= 1;
    while(tail<=n){
      h[tail]= h[head]+1;
      ans=max(ans, h[tail]);
      while(tail<n){
        if(q[tail]<q[tail+1]){
          tail++;
          h[tail] = h[head]+1;
          ans=max(ans, h[tail]);
        }
        else
          break;
      }
      tail++;
      head++;
    }
    cout<<ans<<endl;
  }


  return 0;
}
