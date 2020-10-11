#include <iostream>

using namespace std;  

int N,M, MAP[501][501], dp[501][501];

int solve(int x, int y){
    if(x == N - 1  && y == M - 1){
        return 1;
    }

    if(dp[y][x] == -1){
        dp[y][x] = 0;
        for (int i = 0; i < 4; i++){
            int nx = x + "2101"[i] - '1';
            int ny = y + "1210"[i] - '1';

            if ( nx<0 || ny<0 || nx >= N || ny>= M || MAP[ny][nx] >= MAP[y][x]) continue;
            dp[y][x] += solve(nx,ny);
        } 
    }
    return dp[y][x];

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>M>>N;


    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)  {
            dp[i][j] = -1;
            MAP[i][j] = 10001;
        }
    }
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            cin>>MAP[i][j];

    cout<<solve(0,0);

}
