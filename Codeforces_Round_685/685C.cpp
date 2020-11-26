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


int t, n, k;
string a, b;

int cnt1[26], cnt2[26];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>n>>k;
    cin>>a;
    cin>>b;
    memset(cnt1, 0, sizeof cnt1);
    memset(cnt2, 0, sizeof cnt2);
    for(int i=0;i<a.size();i++)
      cnt1[a[i]-'a']++;
    for(int i=0;i<b.size();i++)
      cnt2[b[i]-'a']++;
    bool n_possible = false;
    for(int i=0;i<26;i++){
      if(cnt2[i]>cnt1[i] || (cnt1[i]%k)!=(cnt2[i]%k)){
        n_possible=true;
        break;
      }
      if(i==25)
        break;
      cnt1[i+1]+=(cnt1[i]-cnt2[i]);

    }
    if(n_possible)
      cout<<"No"<<endl;
    else
      cout<<"Yes"<<endl;
  }

  return 0;
}
