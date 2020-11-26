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
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int i=1;i<=t;i++){
    cin>>n;
    if(n==1)
      cout<<"0"<<endl;
    else if(n==2)
      cout<<"1"<<endl;
    else if(n==3)
      cout<<"2"<<endl;
    else if(n%2==0)
      cout<<"2"<<endl;
    else
      cout<<"3"<<endl;
  }

  return 0;
}
