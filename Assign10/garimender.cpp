#include <bits/stdc++.h>

using namespace std;


int N,MAP[20][20],ans=999999999, color[5], area[20][20], mx[] = {0,1,0,-1}, my[] = {1,0,-1,0};
queue<pair<int, int> >q;
void bfs(int x, int y, int n)
{
    q.push({x,y});
    area[x][y] = n;
    while(!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = a + mx[i];
            int ny = b + my[i];

            if(nx<0||ny<0||nx>=N||ny>=N || area[nx][ny] !=0) continue;

            area[nx][ny] = n;
            q.push({nx,ny});
        }

    }

}
void draw(int x, int y, int dx, int dy, int dep)
{
    if (dep == 0) return;
    area[x][y] = 5;
    draw(x + dx, y + dy, dx, dy, dep -1);


}
int divide(int x, int y, int d1, int d2)
{
    draw(x, y, -1 ,1, d1);
    draw(x - d1, y + d1, 1, 1, d2);
    draw(x - d1 + d2, y + d1 + d2, 1, -1, d1);
    draw(x + d2, y + d2, -1, -1, d2);

    for(int i=0;i<x - d1; i++)
        area[i][y+d1] = 1;
    for(int i=y+d1+d2+1;i<N;i++)
        area[x-d1+d2][i] = 2;
    for(int i=0;i<y;i++)
        area[x][i] = 3;
    for(int i=x+d2+1;i<N;i++)
        area[i][y+d2] = 4;

    bfs(0,0,1);
    bfs(0,N-1,2);
    bfs(N-1,0,3);
    bfs(N-1,N-1,4);
    bfs(x,y,5);

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(area[i][j] == 0) area[i][j] = 5;

    memset(color, 0, sizeof(color));

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            color[area[i][j] - 1] += MAP[i][j];

    int MAX = color[0], MIN = color[0];

    for(int i=1;i<5;i++)
    {
        if(color[i] > MAX) MAX = color[i];
        if(color[i] < MIN) MIN = color[i];
    }

    return MAX - MIN;
}

int solve()
{
    for(int x=1;x<N;x++)
    {
        for(int y=0;y<N-2;y++)
        {
            for(int d1=1;d1<=x;d1++)
            {
                for(int d2=1; d2<N-x;d2++)
                {
                    if (y + d1 + d2 < N)
                    {
                        memset(area, 0, sizeof(area));
                        int dif = divide(x, y, d1, d2);
                        ans = min(ans,dif);
                    }
                }
            }
        }

    }

    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>MAP[i][j];
    cout<<solve();


    return 0;
}
