#include <iostream>
#include <algorithm>
using namespace std;


pair<int,int> a[2*100*1001];
pair<int,int> b[2*100*1001];

int t,n, m;
int main(){
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n>>m;
    for(int i=1;i<=m;i++)
      cin>>a[i].second>>a[i].first;
    int cnt = 0;
    sort(a+1,a+m+1);
    //if(l==8)
      //cout<<m<<endl;
    for(int i=1;i<=m;i++){
      if(a[i].first==a[i-1].first){
        b[++cnt] = make_pair(a[i].first, 3);
        continue;
      }
      if(a[i].first==a[i+1].first && i<m)
        continue;
      b[++cnt]=a[i];
    }
    //if(l==8)
      //cout<<cnt<<endl;
    //if(l==8)
      //for(int i=0;i<=cnt;i++)
        //cout<<b[i].first<<" "<<b[i].second<<endl;
    int state = 3;
    int col = -1;
    int pos = 1;
    int result = -1;
    while(pos<=cnt){
      //if(l==8)
        //cout<<b[pos].second<<endl;
      if(b[pos].second==3){
        if(state!=0 && state!=3){
          result = 0;
          break;
        }
        state = 3;
        pos++;
        continue;
      }
      else{
        if(state==b[pos].second){
          if(b[pos].first%2==col){
            result =0;
            break;
          }
          else{
            state=3;
          }
        }
        else if(state==3-b[pos].second){
          if(b[pos].first%2!=col){
            result = 0;
            break;
          }
          else
            state = 3;
        }
        else if(state==3){
          state =b[pos].second;
          col = b[pos].first%2;
        }
        pos++;
      }
    }
    //if(l==8)
      //cout<<result<<" "<<state<<endl;
    if(result ==0 || state !=3)
      cout<<"NO"<<endl;
    else
      cout<<"YES"<<endl;
  }

  return 0;
}
