#include <bits/stdc++.h>

using namespace std;

class Robot{
public:
    int x, y, dir;
};
int A,B,N,M;
int mx[] ={0,1,0,-1}, my[] = {1,0,-1,0};
Robot robot[101];


bool operate(int idx, char opt)
{
    switch(opt)
    {
    case 'L':
        robot[idx].dir = (robot[idx].dir + 4 - 1 ) % 4;
        break;
    case 'R':
        robot[idx].dir = (robot[idx].dir + 1 ) % 4;
        break;
    case 'F':
        robot[idx].x += mx[robot[idx].dir];
        robot[idx].y += my[robot[idx].dir];
        if(robot[idx].x < 1 || robot[idx].x > A || robot[idx].y < 1 || robot[idx].y > B)
        {
            cout<<"Robot "<<idx<<" crashes into the wall\n";
            return false;
        }
        for(int i=1;i<=N;i++)
        {
            if(i == idx) continue;

            if(robot[i].x == robot[idx].x && robot[i].y == robot[idx].y)
            {
                cout<<"Robot "<<idx<<" crashes into robot "<<i;
                return false;
            }
        }
        break;
    }

    return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>A>>B;
    cin>>N>>M;
    char dir, opt;
    for(int i=1;i<=N;i++)
    {
        cin>>robot[i].x>>robot[i].y>>dir;
        switch(dir)
        {
        case 'D':
            robot[i].dir = 0;
            break;
        case 'E':
            robot[i].dir = 1;
            break;
        case 'S':
            robot[i].dir = 2;
            break;
        case 'W':
            robot[i].dir = 3;
            break;
        }
    }
    int idx,repeat;
    for(int i=0;i<M;i++)
    {
        cin>>idx>>opt>>repeat;
        while(repeat--)
        {
            if(!operate(idx, opt)) return 0;
        }

    }
    cout<<"OK";
	return 0;
}
