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

int t, n;
string s;
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    s="";
    if(n==1)
      cout<<"9"<<endl;
    else if (n==2)
      cout<<"98"<<endl;
    else{
    s="989";
    for(int i=0;i<n-3;i++){
      s+=char('0'+((i)%10));
    }
    cout<<s<<endl;
    }
  }

  return 0;
}
