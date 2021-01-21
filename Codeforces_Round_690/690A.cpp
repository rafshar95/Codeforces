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


int main(){
  std::ios::sync_with_stdio(false);
  int t, n;
  int a[300];
  cin>>t;
  for(int i=1;i<=t;i++){
    cin>>n;
    for(int j=1;j<=n;j++)
      cin>>a[j];
    for(int j=1;j<=n;j++){
      if(j%2==1)
        cout<<a[j/2+1]<<" ";
      else
        cout<<a[n-j/2+1]<<" ";
    }
    cout<<endl;
  }

  return 0;
}
