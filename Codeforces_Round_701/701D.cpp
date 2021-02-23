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


int n, m;
int a[501][501];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
      cin>>a[i][j];
      if((i+j)%2==0)
        a[i][j]=720720;
      else
        a[i][j]= (a[i][j]*a[i][j]*a[i][j]*a[i][j]) + 720720;
    }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++)
      cout<<a[i][j]<<" ";
    cout<<endl;
  }

  return 0;
}
