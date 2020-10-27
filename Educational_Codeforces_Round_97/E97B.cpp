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

string s;

int main(){
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>n;
    cin>>s;
    int x= 1;
    for(int i=1;i<n;i++){
      if(s[i]!=s[i-1])
        x++;
    }
    cout<<(n-x+1)/2<<endl;
  }

  return 0;
}
