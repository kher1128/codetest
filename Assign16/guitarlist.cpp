#include <iostream>

using namespace std;

int N,S,M, vol[101], dp[101][1001];


void calc(int cur) {
    int i, changeVol = vol[cur], prev = cur-1;
    for(i=0;i<=M;i++)
        if(dp[prev][i]==1) {
            if(i + changeVol <= M) dp[cur][i+changeVol] = 1;
            if(i - changeVol >= 0) dp[cur][i-changeVol] = 1;
        }
}

int solve(){
    int ret = 0;
    if(S + vol[0] <= M) dp[0][S+vol[0]] = 1;
    if(S - vol[0] >= 0) dp[0][S-vol[0]] = 1;

    for(int i=1;i<N;i++) 
        calc(i);
    for(int i=M;i>=0;i--)
        if(dp[N-1][i]==1) return i;
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>N>>S>>M;
    for(int i=0;i<N;i++)
        cin>>vol[i];

    cout<<solve();

}
