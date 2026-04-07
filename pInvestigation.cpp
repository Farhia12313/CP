#include<bits/stdc++.h>
using namespace std;
long long k;
string s;
long long dp[12][2][100][100];
long long func(int pos,bool isTight,int remNum,int remSum){
    if(pos == s.size()){
        return (remNum == 0 && remSum == 0);
    }
    if(dp[pos][isTight][remNum][remSum] != -1){
        return dp[pos][isTight][remNum][remSum];
    }
    long long count = 0;
    int limit = isTight ? (s[pos] - '0') : 9;
    for(int d=0;d <= limit ; d++){
        count += func(
            pos + 1,
            isTight && (d == limit),
            (remNum * 10 + d ) % k,
            (remSum + d) % k
        );
    }
    return dp[pos][isTight][remNum][remSum] = count;
}
long long solve(long long n){
    if(n < 0 || k > 90) return 0;
    s = to_string(n);
    memset(dp,-1,sizeof(dp));
    return func(0,true,0,0);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int j=1;j <= t;j++){
        long long a,b;
        cin >> a >> b >> k;
        if(k > 90) {
            cout << "Case " << j <<": 0" << endl;
            continue;
        }
        long long result = solve(b) - solve(a - 1);
        cout << "Case " << j << ": " << result << endl;
    }
    return 0;
}