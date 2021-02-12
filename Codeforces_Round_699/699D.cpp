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


int n, m, t;
string s[1010];


void print_ans(int x, int y, int z, int sz){
  cout<<"YES"<<endl;
  if(m%4==2){
    cout<<x<<" ";
    for(int i=1;i<=sz;i++){
      if(i%2==1)
        cout<<y<<" ";
      else if(i%4==2)
        cout<<z<<" ";
      else
        cout<<x<<" ";
    }
  }
  if(m%4==0){
    cout<<y<<" ";
    for(int i=1;i<=sz;i++){
      if(i%2==0)
        cout<<y<<" ";
      else if(i%4==1)
        cout<<z<<" ";
      else
        cout<<x<<" ";
    }
  }
  cout<<endl;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n>>m;
    for(int i=0;i<n;i++)
      cin>>s[i];
    bool found_symmetric = false;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++)
        if(s[i][j]==s[j][i]){
          found_symmetric = true;
          cout<<"YES"<<endl;
          for(int k=1;k<=m+1;k++){
            if(k%2==0)
              cout<<i+1<<" ";
            else
              cout<<j+1<<" ";
          }
          cout<<endl;
          break;
        }
      if(found_symmetric)
        break;
    }
    if(found_symmetric)
      continue;
    if(m%2==0){
      if(n==2){
        cout<<"NO"<<endl;
        continue;
      }
      if(s[0][1]==s[1][2]){
        print_ans(1, 2, 3, m);
      }
      else if(s[1][2]==s[2][0]){
        print_ans(2, 3, 1, m);
      }
      else{
        print_ans(3, 1, 2, m);
      }
      continue;

    }
    cout<<"YES"<<endl;
    for(int i=1;i<=m+1;i++){
      if(i%2==0)
        cout<<1<<" ";
      else
        cout<<2<<" ";
    }
    cout<<endl;
  }

  return 0;
}
