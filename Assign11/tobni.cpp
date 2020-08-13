#include <bits/stdc++.h>

using namespace std;

bool tob[4][8],visit[4];
int ans;


void turn(int num, int dir)
{
    visit[num] = true;
    bool left = tob[num][6], right = tob[num][2];

    if(dir == -1)
    {
        bool temp = tob[num][0];
        for(int i=0;i<7;i++)
            tob[num][i] = tob[num][i+1];
        tob[num][7] = temp;
    }
    else
    {
        bool temp = tob[num][7];
        for(int i=7;i>0;i--)
            tob[num][i] = tob[num][i-1];
        tob[num][0] = temp;
    }

    if( num - 1 >= 0 && !visit[num - 1] && left != tob[num - 1][2])
        turn(num - 1, -dir);

    if ( num + 1 < 4 && !visit[num + 1] && right != tob[num+1][6])
        turn(num + 1, -dir);

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    int K,num,dir,temp;

    for(int i=0;i<4;i++)
    {
        cin>>temp;
        int idx = 7;
        while(temp){
            tob[i][idx--] = temp%10;
            temp/=10;
        }
    }

    cin>>K;
    for(int i=0;i<K;i++)
    {
        cin>>num>>dir;
        memset(visit, false, sizeof(visit));
        turn(num - 1, dir);
    }

    int mul = 1;
    for(int i=0;i<4;i++)
    {
        if (tob[i][0])
            ans += mul;
        mul *= 2;
    }
    cout<<ans;
	return 0;
}
