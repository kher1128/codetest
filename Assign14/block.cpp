#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(int x, int y, vector<string> &board)
{
    char cmp = board[x][y];
    if (cmp == '0') return false;
    
    for(int i=x;i<=x+1;i++)
        for(int j=y;j<=y+1;j++)
            if (board[i][j] != cmp) return false;
    
    return true;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool keep = true;
    stack<pair<int, int> >s;
    stack<char> c;
    while(keep)
    {
        keep = false;
        for(int i=0;i<m - 1;i++)
            for(int j=0;j<n - 1;j++)
                if(check(i,j, board))
                {
                    s.push({i,j});
                    keep = true;
                }
        
        while(!s.empty())
        {
            int x = s.top().first;
            int y = s.top().second;
            s.pop();
            
            for(int i=x;i<=x+1;i++)
                for(int j=y;j<=y+1;j++)
                    if(board[i][j] != '0')
                    {
                        board[i][j] = '0';
                        answer++;
                    } 
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if (board[j][i] == '0') continue;
                c.push(board[j][i]);
                board[j][i] = '0';
            }
            int idx = m - 1;
            while(!c.empty())
            {
                board[idx--][i] = c.top();
                c.pop();
            }
        }
    }
    return answer;
}
