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

const int maxn = 5*1000*101;

int dp[maxn], n;
long long ans = 0;
long long suf_ans = 0;

char c[maxn];
int main(){
  scanf("%d", &n);
  for(int i=0;i<=n;i++)
    scanf("%c", &c[i]);
  int cur = 0;
  for(int i=1;i<=n;i++){
    if(c[i]=='1'){
      cur++;
      suf_ans+=i-dp[cur];
    }
    else{
      for(int j=1;j<=cur;j++)
        dp[j]=i-j;
      cur=0;
    }
    ans+=suf_ans;
  }

  printf("%lld\n", ans);
  return 0;
}
