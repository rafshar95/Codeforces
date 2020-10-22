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

int t, n;


string s[210];


int main(){
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>s[i];
    int cnt = 0;
    if(s[0][1]==s[1][0]){
      if(s[n-1][n-2]==s[0][1])
        cnt++;
      if(s[n-2][n-1]==s[0][1])
        cnt++;
      cout<<cnt<<endl;
      if(s[n-1][n-2]==s[0][1])
        cout<<n<<" "<<n-1<<endl;
      if(s[n-2][n-1]==s[0][1])
        cout<<n-1<<" "<<n<<endl;
    }
    else{
      if(s[n-1][n-2]==s[n-2][n-1]){
        cout<<1<<endl;
        if(s[n-1][n-2]==s[0][1])
          cout<<"1 2"<<endl;
        if(s[n-2][n-1]==s[1][0])
          cout<<"2 1"<<endl;
      }
      else{
        cout<<2<<endl;
        if(s[0][1]=='0')
          cout<<"1 2"<<endl;
        else
          cout<<"2 1"<<endl;
        if(s[n-1][n-2]=='1')
          cout<<n<<" "<<n-1<<endl;
        else
          cout<<n-1<<" "<<n<<endl;
      }
    }
  }

  return 0;
}
