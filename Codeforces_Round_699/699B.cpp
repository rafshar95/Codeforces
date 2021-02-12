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
#include <numeric>

using namespace std;


int n, k, t;
int h[110];
int main(){
  std::ios_base::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n>>k;
    int mx = 0;
    for(int i=1;i<=n;i++){
      cin>>h[i];
      mx= max(mx, h[i]);
    }
    if(k>mx * n || n==1){
      cout<<"-1"<<endl;
      continue;
    }
    bool found =false;
    int id = -1;
    for(int i=1;i<=k;i++){
      found=false;
      for(int j=1;j<=n-1;j++)
        if(h[j]<h[j+1]){
          found =true;
          h[j]++;
          id = j;
          break;
        }
      if(!found)
        break;
    }
    if(!found)
      cout<<"-1"<<endl;
    else
      cout<<id<<endl;
  }

  return 0;
}
