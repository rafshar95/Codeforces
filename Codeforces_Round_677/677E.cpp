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

int n;

long long ans = 1;
int main(){
  cin>>n;
  for(int i=1;i<=n-1;i++)
    if(i!=n/2)
      ans = ans * i;
  cout<<ans<<endl;
  return 0;
}
