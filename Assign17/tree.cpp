#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class tree{
    public :
    int x, y, age;
};
vector<int> MAP[11][11];
queue<tree> dead;
queue<int> temp;
int N, M, K, Nut[11][11], robot[11][11];
void spring()
{
    tree t;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int len = MAP[i][j].size();
            if(len == 0) continue;
            sort(MAP[i][j].begin(), MAP[i][j].end());
            for(int k=0;k<len;k++){
                if(MAP[i][j][k] > Nut[i][j]){
                    t.x = i, t.y = j, t.age = MAP[i][j][k];
                    dead.push(t);
                }else{
                    Nut[i][j] -= MAP[i][j][k];
                    temp.push(MAP[i][j][k] + 1);
                }
            }
            MAP[i][j].clear();
            while(!temp.empty()){
                MAP[i][j].push_back(temp.front());
                temp.pop();
            }
        }
    }
}
void summer()
{
    while (!dead.empty()){
        int x = dead.front().x, y = dead.front().y, age = dead.front().age;
        Nut[x][y] += age/2;
        dead.pop();
    }
}
void autumn()
{
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int len = MAP[i][j].size();
            if(len == 0) continue;
            for(int k=0;k<len;k++){
                if(MAP[i][j][k] % 5 == 0){
                    for(int p=0;p<8;p++){
                        int nx = i + "00011222"[p] - '1';
                        int ny = j + "01202012"[p] - '1';
                        if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
                        MAP[nx][ny].push_back(1);
                    }
                }
            }
        }
    }
}
void winter()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            Nut[i][j] += robot[i][j];
}

int solve()
{
    int check = 0;
    for (int i = 0; i < K; i++)
    {
        check = 0;
        spring();
        summer();
        autumn();
        winter();
    }
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            check += MAP[i][j].size();
    return check;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++){
            cin >> robot[i][j];
            Nut[i][j] = 5;
        }
    int x, y, age;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> age;
        MAP[x][y].push_back(age);
    }
    cout << solve()<<'\n';
    return 0;
}
