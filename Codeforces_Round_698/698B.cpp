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

bool mark[10][100];
int t,n, q;
int a[20000];
void fill_in(int val, int step){
  for(int i=val;i<=99;i+=step)
    mark[step][i]=true;
}
int main(){

  std::ios::sync_with_stdio(false);
  for(int i=1;i<=9;i++){
    fill_in(i,i);
    for(int j=0;j<=9;j++)
      fill_in(i*10+j, i);
    for(int j=1;j<=9;j++)
      fill_in(i+j*10, i);
  }
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
      cin>>a[i];
      if(a[i]>=100 || mark[q][a[i]])
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;
    }

  }


  return 0;
}
