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


const int maxn = 1001*100;
int n, a[maxn];
vector<int> v[maxn];

vector<pair<int,int> > one;
vector<pair<int,int> > ans;
vector<pair<int, int> > twoorthree;
pair<int, int> last= make_pair(-1, -1);
int pos;
int match =0;
int match2 =0;
bool impossible;
int main(){
  cin>>n;
  pos= n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  for(int i=n;i>=1;i--){
    if(a[i]==1){
      one.push_back(make_pair(pos, i));
      ans.push_back(make_pair(pos, i));
      pos--;
    }
    if(a[i]==2){
      if(match>=one.size()){
        impossible=true;
        break;
      }
      pair<int, int> temp = one[match];
      ans.push_back(make_pair(temp.first, i));
      twoorthree.push_back(make_pair(temp.first, i));
      match++;
    }
    if(a[i]==3){
      if(match2>=twoorthree.size() && match>=one.size()){
        impossible=true;
        break;
      }
      if(match2<twoorthree.size()){
        pair<int, int> tmp = twoorthree[match2];
        ans.push_back(make_pair(pos, tmp.second));
        ans.push_back(make_pair(pos, i));
        match2++;
        twoorthree.push_back(make_pair(pos, i));
        pos--;
      }
      else{
        pair<int, int> tmp = one[match];
        ans.push_back(make_pair(pos, tmp.second));
        ans.push_back(make_pair(pos, i));
        match++;
        twoorthree.push_back(make_pair(pos, i));
        pos--;
      }
    }
  }
  if(impossible){
    cout<<"-1"<<endl;
    return 0;
  }
  cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();i++)
    cout<<ans[i].first<<" "<<ans[i].second<<endl;


  return 0;
}
