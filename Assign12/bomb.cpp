#include <iostream>
#include <queue>

using namespace std;

char BOMB[201][201];
int R,C,N,mx[] = {0,1,0,-1}, my[] = {1,0,-1,0};
queue<pair<int, int> > q;

void queueing()
{
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            if(BOMB[i][j] == 'O')
                q.push(make_pair(i,j));
}
void fill()
{
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            if(BOMB[i][j] != 'O')
                BOMB[i][j] = 'O';

}

void boom()
{
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        BOMB[x][y] = '.';
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x + mx[i];
            int ny = y + my[i];

            if(nx<0||ny<0||nx>=R||ny>=C) continue;

            BOMB[nx][ny] = '.';
        }

    }

}
void solve()
{
    for(int time=0;time<N;)
    {
        queueing();
        time++;
        if (time == N)
            return;
        fill();
        time++;
        if (time == N)
            return;
        boom();
    }


}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>R>>C>>N;
    string s;
    for(int i=0;i<R;i++)
    {
        cin>>s;
        for(int j=0;j<C;j++)
            BOMB[i][j] = s[j];
    }


    if (N % 2 == 0)
    {
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
                cout<<'O';
            cout<<'\n';
        }
        return 0;
    }
    else
    {
        solve();
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                cout<<BOMB[i][j];
            }
            cout<<'\n';
        }
    }
    
    return 0;
}
