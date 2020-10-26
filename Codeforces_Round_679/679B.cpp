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

int p[510], n, m, t, v[510];

int a[510][510];
int main(){
  scanf("%d", &t);
  for(int l=0;l<t;l++){
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        scanf("%d", &a[i][j]);
    for(int i=1;i<=n;i++)
      scanf("%d", &v[i]);
    int jnk;
    for(int i=2;i<=m;i++)
      for(int j=1;j<=n;j++){
        scanf("%d", &jnk);
      }
    int row, col;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        if(v[i]==a[1][j]){
          row=i;
          col=j;
          p[i]=1;
        }
      for(int j=2;j<=n;j++)
        for(int i=1;i<=n;i++)
          if(v[i]==a[j][col]){
            p[i]=j;
            break;
          }
      for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
          printf("%d ", a[p[i]][j]);
        printf("\n");
      }
  }



  return 0;
}
