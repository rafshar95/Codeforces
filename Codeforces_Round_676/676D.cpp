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


int t, x, y;

long long c1, c2, c3, c4, c5, c6;
long long find_ans(long long cor, long long v1, long long v2, long long v3){
  long long ret=0;
  if(v1<v2+v3)
    return cor * v1;
  return cor * (v2+ v3);
}
int main(){
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>x>>y;
    cin>>c1>>c2>>c3>>c4>>c5>>c6;
    long long res=0;
    if(x>0 && y>0){
      res+=find_ans(min(x,y), c1, c2, c6);
      int tmp = min(x,y);
      x-=tmp;
      y-=tmp;
    }
    if(x<0 && y<0){
      res+=find_ans(min(-x, -y), c4, c5, c3);
      int tmp = min(-x, -y);
      x+=tmp;
      y+=tmp;
    }
    if(x>0){
      res+=find_ans(x, c6, c1, c5);
    }
    else if(x<0){
      res+=find_ans(-x, c3, c2, c4);
    }
    if(y>0){
      res+=find_ans(y, c2, c1, c3);
    }
    else if(y<0){
      res+=find_ans(-y, c5, c6, c4);
    }
    cout<<res<<endl;
  }

  return 0;
}
