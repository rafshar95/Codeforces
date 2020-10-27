#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <deque>

using namespace std;

int t, l, r;
int main(){
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>l>>r;
    if(l>r/2)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }


  return 0;
}
