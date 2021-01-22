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

int t, n, a[101];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    int sum = 0;
    int cnt_1=0;
    int cnt_2=0;
    for(int i=1;i<=n;i++){
      cin>>a[i];
      sum+=a[i];
      if(a[i]==1)
        cnt_1++;
      else
        cnt_2++;
    }
    if(sum%2==1)
      cout<<"NO"<<endl;
    else if(sum%4==2 && cnt_1==0)
      cout<<"NO"<<endl;
    else
      cout<<"YES"<<endl;
  }

  return 0;
}
