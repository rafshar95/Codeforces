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

int t, n, a[2*100*1001];

int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    sort(a+1, a+n+1, greater<int>());
    long long s_Alice = 0;
    long long s_Bob = 0;
    for(int i=1;i<=n;i++){
      if(i%2==1 && a[i]%2==0)
        s_Alice +=a[i];
      if(i%2==0 && a[i]%2==1)
        s_Bob +=a[i];
    }
    if(s_Alice == s_Bob)
      cout<<"Tie"<<endl;
    else if(s_Alice > s_Bob)
      cout<<"Alice"<<endl;
    else
      cout<<"Bob"<<endl;
  }


  return 0;
}
