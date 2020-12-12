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

char c[2010][2010];
int rightmost[2010][2010];
int bottommost[2010][2010];
int t,n;
int lst[10];
int res[10];
int fst_row[10], lst_row[10], fst_col[10], lst_col[10];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        cin>>c[i][j];
    memset(fst_row, -1, sizeof fst_row);
    memset(lst_row, -1, sizeof lst_row);
    memset(fst_col, -1, sizeof fst_col);
    memset(lst_col, -1, sizeof lst_col);
    memset(res, 0, sizeof res);
    for(int i=1;i<=n;i++){
      memset(lst, -1, sizeof lst);
      for(int j=1;j<=n;j++){
        if(fst_row[c[i][j]-'0']==-1)
          fst_row[c[i][j]-'0']=i;
        lst_row[c[i][j]-'0']=i;
        if(lst[c[i][j]-'0']!=-1){
          rightmost[i][j]=lst[c[i][j]-'0'];
          res[c[i][j]-'0']=max(res[c[i][j]-'0'], (j- rightmost[i][j])*max(i-1,n-i));
        }
        else
          lst[c[i][j]-'0']=j;
      }
    }
    for(int j=1;j<=n;j++){

      memset(lst, -1, sizeof lst);
      for(int i=1;i<=n;i++){
        if(fst_col[c[i][j]-'0']==-1)
          fst_col[c[i][j]-'0']=j;
        lst_col[c[i][j]-'0']=j;
        if(lst[c[i][j]-'0']!=-1){
          bottommost[i][j]=lst[c[i][j]-'0'];
          res[c[i][j]-'0']=max(res[c[i][j]-'0'], (i-bottommost[i][j])*max(j-1,n-j));
        }
        else
          lst[c[i][j]-'0']=i;
      }
    }
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++){
        res[c[i][j]-'0']=max(res[c[i][j]-'0'], (i-fst_row[c[i][j]-'0'])*max(n-j,j-1));
        res[c[i][j]-'0']=max(res[c[i][j]-'0'], (j-fst_col[c[i][j]-'0'])*max(n-i,i-1));
        res[c[i][j]-'0']=max(res[c[i][j]-'0'], (lst_row[c[i][j]-'0'] - i)*max(n-j,j-1));
        res[c[i][j]-'0']=max(res[c[i][j]-'0'], (lst_col[c[i][j]-'0']-j)*max(n-i,i-1));
      }
    for(int i=0;i<10;i++)
      cout<<res[i]<<" ";
    cout<<endl;


  }

  return 0;
}
