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
int val[2*100*1001];
char c[2*100*1001];

vector<int> v;
vector<int> res;
int main(){
  cin>>n;
  for(int i=1;i<=2*n;i++){
    cin>>c[i];
    if(c[i]=='-')
      cin>>val[i];
  }
  for(int i=2*n;i>=1;i--){
    if(c[i]=='+'){
      if(v.size()==0){
        cout<<"NO"<<endl;
        return 0;
      }
      else{
        res.push_back(v[v.size()-1]);
        v.pop_back();
      }
    }
    if(c[i]=='-'){
      if(v.size()!=0 && v[v.size()-1]<val[i]){
        cout<<"NO"<<endl;
        return 0;
      }
      else
        v.push_back(val[i]);
    }
  }
  cout<<"YES"<<endl;
  for(int i=res.size()-1;i>=0;i--)
    cout<<res[i]<<" ";
  cout<<endl;


  return 0;
}
