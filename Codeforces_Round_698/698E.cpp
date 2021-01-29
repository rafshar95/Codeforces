#include <iostream>


using namespace std;

const int maxn = 2*1001*100;


int t, n, q;

string s, f;

int a[maxn], b[maxn];

int sum[maxn*4], flag[maxn*4];

void push_down(int node, int low, int high){
  int mid = (low + high)/2;
  if(flag[node]!=-1){
    flag[(node<<1)+1]=flag[node];
    sum[(node<<1)+1] = flag[node]*(mid - low +1);
    flag[(node<<1)+2]=flag[node];
    sum[(node<<1)+2]=flag[node]*(high -mid);
    flag[node]=-1;
  }
}

int find_sum(int node, int low, int high, int l, int r){
//  cout<<"a "<<node<<" "<<low<<" "<<high<<" "<<l<<" "<<r<<endl;
  if(l > high || r<low || low>high)
    return 0;
  if(l<=low && high<=r)
    return sum[node];
  int mid = (low + high)/2;
  push_down(node, low, high);
  return find_sum((node<<1)+1, low, mid, l, r)+ find_sum((node<<1)+2, mid+1, high, l, r);
}

void assign(int node, int low, int high, int l, int r, int val){
  //cout<<"b "<<node<<" "<<low<<" "<<high<<" "<<l<<" "<<r<<endl;
  if(l > high || r<low || low>high)
    return;
  if(l<=low && high<=r){
    flag[node]=val;
    sum[node]=val*(high-low+1);
    return;
  }
  int mid = (low+high)/2;
  push_down(node, low, high);
  assign((node<<1)+1, low, mid, l, r, val);
  assign((node<<1)+2, mid+1, high, l, r, val);
  sum[node] = sum[(node<<1)+1]+sum[(node<<1)+2];


}


void resSeg(int m){
  for(int i=0;i<=m*4;i++){
    sum[i]=0;
    flag[i]=-1;
  }
}

int main(){
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n>>q;
    cin>>s>>f;
    for(int i=1;i<=q;i++){
      cin>>a[i]>>b[i];
      a[i]--;
      b[i]--;
    }
    resSeg(n);
    for(int i=0;i<f.size();i++){
      if(f[i]=='1')
        assign(0, 0, n-1, i, i, 1);
    }
    bool poss =true;
    for(int i=q;i>=1;i--){
      int val = find_sum(0, 0, n-1, a[i], b[i]);
      if((b[i]-a[i]+1)%2==0){
        if((b[i]-a[i]+1)/2==val){
          poss=false;
          break;
        }
      }
      if(val>(b[i]-a[i]+1)/2)
        assign(0, 0, n-1, a[i], b[i], 1);
      else
        assign(0, 0, n-1, a[i], b[i], 0);
    }
    if(poss==false)
      cout<<"NO"<<endl;
    else{
      for(int i=0;i<s.size();i++){
        int val = find_sum(0, 0, n-1, i, i);
        if(val!=s[i]-'0')
          poss=false;
      }
      if(!poss)
        cout<<"NO"<<endl;
      else
        cout<<"YES"<<endl;
    }
  }

  return 0;
}
