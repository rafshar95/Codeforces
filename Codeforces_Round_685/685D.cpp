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
int t;

long long d, k;

int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>d>>k;
    double p2 = 1.0 * d / (sqrt(2)*k);
    long long p = int(p2);
    if(k*k*p*p+(p+1)*(p+1)*k*k>d*d)
      cout<<"Utkarsh"<<endl;
    else
      cout<<"Ashish"<<endl;

  }

  return 0;
}
