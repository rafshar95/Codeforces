#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <cstring>
#include <random>
#include <map>
#include <cmath>

using namespace std;


int t, n, m;


int a[110][110];

int main(){
  std::ios_base::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        cin>>a[i][j];
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++){
        if((i+j)%2==0){
          if(a[i][j]%2==0)
            a[i][j]++;
        }
        else{
          if(a[i][j]%2==1)
            a[i][j]++;
        }
      }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++)
        cout<<a[i][j]<<" ";
      cout<<endl;
    }
  }
  return 0;
}
