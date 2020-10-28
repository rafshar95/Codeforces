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
int a[52];
int main(){
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>n;
    int fst= -1, lst= -1;
    for(int i=1;i<=n;i++){
      cin>>a[i];
      if(fst==-1 && a[i]==1)
        fst=i;
      if(a[i]==1)
        lst=i;
    }
    int res = 0;
    for(int i=fst;i<=lst;i++)
      if(a[i]==0)
        res++;
    cout<<res<<endl;
  }
  return 0;
}
