#include <iostream>
#include <string>
using namespace std;

int t,n;

string a[1010];
string b[1010];
int comp[2010];

void dfs(int v, int c){
  comp[v]= c;
  if(v<n){
    for(int i=0;i<n;i++){
      if(comp[i+n]==-1){
        if(a[v][i]==b[v][i])
          dfs(i+n, c);
        else
          dfs(i+n, !c);
      }
    }
  }
  else{
    for(int i=0;i<n;i++){
      if(comp[i+n]==-1){
        if(a[i][v-n]==b[i][v-n])
          dfs(i, c);
        else
          dfs(i, !c);
      }
    }
  }
}
int main(){
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>a[i];
    for(int i=0;i<n;i++)
      cin>>b[i];
    for(int i=0;i<2*n;i++)
      comp[i]=-1;
    dfs(0, 0 );
    bool printed = false;
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++){
        if(!printed && a[i][j]!=b[i][j] && comp[i]==comp[j+n]){
          printed= true;
          cout<<"NO"<<endl;
        }
        else if(!printed && a[i][j]==b[i][j] && comp[i]!=comp[j+n]){
          printed = true;
          cout<<"NO"<<endl;
        }
      }
    if(!printed)
        cout<<"YES"<<endl;
  }


}
