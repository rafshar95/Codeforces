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

int t, a, b, c, d;
int main(){
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>a>>b>>c>>d;
    if(a>c)
      swap(a,c);
    if(b>d)
      swap(b,d);
    if(a!=c && b!=d){
      long long sum = (d-b);
      sum+=2;
      sum+=c-a;
      cout<<sum<<endl;
    }
    else{
      cout<<(d-b)+(c-a)<<endl;
    }
  }


  return 0;
}
