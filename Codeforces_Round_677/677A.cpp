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

int t;
int n;

int find_ans(int a){
  int ret=0;
  for(int i=1;i<=9;i++){
    int res=0;
    for(int j=1;j<=4;j++){
      ret+=j;
      res = res*10 + i;
      if(res==a)
        return ret;
    }
  }
  return -1;
}
int main(){
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>n;
    cout<<find_ans(n)<<endl;
  }
  return 0;
}
