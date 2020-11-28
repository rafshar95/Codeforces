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
struct res{
  int x1;
  int y1;
  int x2;
  int y2;
  int x3;
  int y3;
  res(int xx1,int yy1, int xx2, int yy2, int xx3, int yy3){
    x1 = xx1;
    y1 = yy1;
    x2 = xx2;
    y2 = yy2;
    x3 = xx3;
    y3 = yy3;
  }
};


int n, m, t;

int c[101][101];
vector<res> ans;

void modify(int a1, int b1, int a2, int b2, int a3, int b3){
  c[a1][b1]^=1;
  c[a2][b2]^=1;
  c[a3][b3]^=1;
  ans.push_back(res(a1,b1,a2,b2,a3,b3));
}

void handle(int i, int j){
  int cnt =0;
  if(c[i][j])
    cnt++;
  if(c[i][j+1])
    cnt++;
  if(c[i+1][j])
    cnt++;
  if(c[i+1][j+1])
    cnt++;
  if(cnt==4){
    modify(i,j, i, j+1, i+1, j);
    cnt =1;
  }
  if(cnt==1){
    if(c[i+1][j+1]==0)
      modify(i,j,i,j+1,i+1,j);
    else
      modify(i+1,j+1,i,j+1,i+1,j);
    cnt=2;
  }
  if(cnt==2){
    if(c[i][j] && c[i+1][j+1]){
      modify(i,j,i,j+1,i+1,j);
    }
    else if(c[i][j] && c[i][j+1]){
      modify(i,j,i+1,j+1,i+1,j);
    }
    else if(c[i][j] && c[i+1][j]){
      modify(i,j,i,j+1,i+1,j+1);
    }
    else if(c[i+1][j] && c[i+1][j+1]){
      modify(i,j,i,j+1,i+1,j);
    }
    else if(c[i+1][j] && c[i][j+1]){
      modify(i,j,i+1,j+1,i+1,j);
    }
    else if(c[i][j+1] && c[i+1][j+1]){
      modify(i,j,i,j+1,i+1,j);
    }
    cnt=3;
  }
  if(cnt==3){
    if(c[i][j]==0)
      modify(i+1, j, i, j+1, i+1, j+1);
    else if(c[i+1][j]==0)
      modify(i, j, i, j+1, i+1, j+1);
    else if(c[i][j+1]==0)
      modify(i, j, i+1, j, i+1, j+1);
    else
      modify(i, j, i+1, j, i, j+1);
    cnt=0;
  }
  if(cnt==0){
    return;
  }
}

int main(){
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++){
        char tmp;
        cin>>tmp;
        c[i][j]=tmp-'0';
      }
    ans.clear();
    if(n%2==1 && m%2==1 && c[n][m]==1){
      modify(n,m,n-1,m,n,m-1);
    }
    if(n%2==1)
      for(int j=1;j<m;j+=2){
        if(c[n][j]==1 && c[n][j+1]==1){
          modify(n,j,n,j+1,n-1,j);
        }
        else if(c[n][j]==1){
          modify(n,j,n-1,j+1,n-1,j);
        }
        else if(c[n][j+1]==1){
          modify(n,j+1,n-1,j+1,n-1,j);
        }
      }
    if(m%2==1){
      for(int i=1;i<n;i+=2){
        if(c[i][m]==1 && c[i+1][m]==1){
          modify(i, m, i+1, m, i, m-1);
        }
        else if(c[i][m]==1){
          modify(i, m, i+1, m-1, i, m-1);
        }
        else if(c[i+1][m]==1)
          modify(i+1, m, i+1, m-1, i, m-1);
      }
    }
    for(int i=1;i<n;i+=2)
      for(int j=1;j<m;j+=2)
        handle(i,j);
    /*for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++)
        cout<<c[i][j];
      cout<<endl;
    }*/
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
      cout<<ans[i].x1<<" "<<ans[i].y1<<" "<<ans[i].x2<<" "<<ans[i].y2<<" "<<ans[i].x3<<" "<<ans[i].y3<<endl;
  }

  return 0;
}
