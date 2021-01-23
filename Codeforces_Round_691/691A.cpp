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
string s, m;
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    cin>>s>>m;
    int cnt1 =0;
    int cnt2 = 0;
    for(int i=0;i<n;i++){
      if(s[i]-'0' > m[i]-'0')
        cnt1++;
      if(s[i]-'0' < m[i]-'0')
        cnt2++;
    }
    if(cnt1==cnt2)
      cout<<"EQUAL"<<endl;
    else if(cnt1>cnt2)
      cout<<"RED"<<endl;
    else
      cout<<"BLUE"<<endl;
  }

  return 0;
}
