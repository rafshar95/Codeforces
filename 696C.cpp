#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <cstring>
#include <random>
#include <map>
#include <cmath>
#include <numeric>

using namespace std;


int t, n;

int a[2010];
bool mark[2010];

vector<pair<int, int> > ans;

set <pair<int,int>> st;

bool find_ans(int scnd){
  mark[1]= true;
  mark[scnd]= true;
  set<pair<int,int> >::iterator it;
  ans.push_back(make_pair(a[1], a[scnd]));
  int sum = a[1];
  for(int i=1;i<=n;i++)
    if(!mark[i])
      st.insert(make_pair(-a[i], i));
  int pos =1;
  while(true){
    while(mark[pos] && pos<=n)
      pos++;
    if(pos>n)
      return true;
      mark[pos]=true;
      st.erase(make_pair(-a[pos], pos));
      it = st.lower_bound(make_pair(a[pos]-sum, 0));
      //cout<<scnd<<" "<<sum<<" "<<a[pos]<<endl;
      if(it==st.end())
        return false;
      //cout<<scnd<<" "<<sum<<" "<<a[pos]<<" "<<-(it->first)<<endl;
      if(it->first - a[pos] != -sum)
        return false;
      mark[it -> second]=true;
      sum = a[pos];
      ans.push_back(make_pair(a[pos], -(it->first)));
      st.erase(it);
  }

  return true;
}


int main(){
  std::ios_base::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    n*=2;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    sort(a+1,a+n+1, greater<int>());
    bool found = false;
    for(int i=2;i<=n;i++){
      ans.clear();
      memset(mark, 0, sizeof mark);
      st.clear();
      if(find_ans(i)){
        cout<<"YES"<<endl;
        cout<<ans.front().first+ans.front().second<<endl;
        for(int i=0;i<ans.size();i++)
          cout<<ans[i].first<<" "<<ans[i].second<<endl;
        found =true;
        break;
      }
    }
    if(!found)
      cout<<"NO"<<endl;

  }


  return 0;
}
