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

using namespace std;

int xor_res = 0;
int n,a[101*1000];
int main(){
  std::ios_base::sync_with_stdio(false);
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    xor_res^=a[i];
  }
  if(n%2==0 && xor_res!=0){
    cout<<"NO"<<endl;
    return 0;
  }
  cout<<"YES"<<endl;
  if(n%2==0){
    cout<<n-3<<endl;
    for(int i=1;i<n-2;i+=2){
      cout<<i<<" "<<i+1<<" "<<i+2<<endl;
    }
    for(int i=1;i<n-4;i+=2){
      cout<<i<<" "<<i+1<<" "<<n-1<<endl;
    }
  }
  else{
    cout<<n-2<<endl;
    for(int i=1;i<n;i+=2){
      cout<<i<<" "<<i+1<<" "<<i+2<<endl;
    }
    for(int i=1;i<n-2;i+=2){
      cout<<i<<" "<<i+1<<" "<<n<<endl;
    }
  }


  return 0;
}
