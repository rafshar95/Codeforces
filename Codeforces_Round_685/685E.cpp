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

const int maxn = 1000* 100;

int n;

int a[maxn];
int b[maxn];
int x, y, z;
int main(){
  std::ios::sync_with_stdio(false);
  cin>>n;
  for(int i=1;i<n;i++){
    cout<<"XOR"<<" "<<i<<" "<<i+1<<endl;
    fflush(stdout);
    cin>>b[i];
  }
  cout<<"AND"<<" "<<1<<" "<<2<<endl;
  fflush(stdout);
  cin>>x;
  cout<<"AND"<<" "<<2<<" "<<3<<endl;
  fflush(stdout);
  cin>>y;
  cout<<"AND"<<" "<<1<<" "<<3<<endl;
  fflush(stdout);
  cin>>z;
  for(int i=0;(1<<i)<n;i++){
    //cout<<i<<endl;
    if((b[1]&(1<<i))==0){
      //cout<<"a"<<" "<<i<<endl;
      //cout<<x<<endl;
      if((x&(1<<i))!=0)
        a[1]+=((1<<i));
    }
    else if((b[2]&(1<<i))==0){
      //cout<<"b"<<" "<<i<<endl;
      if((y&(1<<i))==0)
        a[1]+=((1<<i));
    }
    else{
      //cout<<"c"<<" "<<i<<endl;
      if((z&(1<<i))!=0)
        a[1]+=((1<<i));
    }
  }
  for(int i=2;i<=n;i++)
    a[i]=a[i-1]^b[i-1];
  cout<<"! ";
  for(int i=1;i<=n;i++)
    cout<<a[i]<<" ";
  cout<<endl;


  return 0;
}
