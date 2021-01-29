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

int n;

pair<pair<long long, long long>, int> p[5010];

long long disSq(int pos1, int pos2){
  return (p[pos1].first.first-p[pos2].first.first)*(p[pos1].first.first-p[pos2].first.first)+(p[pos1].first.second-p[pos2].first.second)*(p[pos1].first.second-p[pos2].first.second);
}
int main(){
  std::ios::sync_with_stdio(false);
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>p[i].first.first>>p[i].first.second;
    p[i].second = i;
  }
  for(int i=3;i<=n;i++){
    for(int j=i-1;j>=2;j--){
      if(disSq(j+1, j-1)<disSq(j,j+1))
        break;
      if(disSq(j+1, j-1)<disSq(j,j-1))
        break;
      if(disSq(j,j+1) - disSq(j+1, j-1) + disSq(j,j-1) >0)
        break;
      swap(p[j],p[j+1]);
    }
  }
  for(int i=1;i<=n;i++)
    cout<<p[i].second<<" ";
  cout<<endl;

  return 0;
}
