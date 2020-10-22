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

int t, a, b;

int main(){
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>a>>b;
    int x=0;
    for(int j=0;j<30;j++){
      if((a & (1<<j)) && (b & (1<<j))){
        x = x + (1<<j);
      }
    }
    cout<<(a^x)+(b^x)<<endl;
  }
  return 0;
}
