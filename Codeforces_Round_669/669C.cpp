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


int p[10010];
int n, mx_id;
int main(){
  cin>>n;
  int mx_id = 1;
  int a, b;
  for(int i=2;i<=n;i++){
    cout<<"? "<<mx_id<<" "<<i<<endl;
    fflush(stdout);
    cin>>a;
    cout<<"? "<<i<<" "<<mx_id<<endl;
    fflush(stdout);
    cin>>b;
    if(a<b){
      p[i]=b;
    }
    else{
      p[mx_id]=a;
      mx_id=i;
    }
  }
  p[mx_id]=n;
  cout<<"! ";
  for(int i=1;i<=n;i++)
    cout<<p[i]<<" ";
  cout<<endl;

  return 0;
}
