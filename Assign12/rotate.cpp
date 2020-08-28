#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int N,M,K, table[51][51], r[7],c[7],s[7], temp[51][51], ans = 987654321;

void rotate(int idx)
{
    
    int rr = r[idx], cc = c[idx], ss = s[idx];
    for(int i=1;i<=ss;i++)
    {
        int ul = temp[rr - i + 1][cc - i], ur = temp[rr - i][cc + i - 1], dl = temp[rr + i][cc - i + 1], dr = temp[rr + i - 1][cc + i];
        for(int j=1;j<2*i;j++)    //위
            temp[rr - i][cc + i - j] = temp[rr - i][cc + i - j - 1];
        for(int j=1;j<2*i;j++)      //오른쪽
            temp[rr + i - j][cc + i] = temp[rr + i - j - 1][cc + i];
        for(int j=1;j<2*i;j++)      //아래쪽
            temp[rr + i][cc - i + j] = temp[rr + i][cc - i + j + 1];
        for(int j=1;j<2*i;j++)      //왼쪽
            temp[rr - i + j][cc - i] = temp[rr - i + j + 1][cc - i];
        temp[rr - i][cc - i] = ul;
        temp[rr + i][cc + i] = dr;
        temp[rr + i][cc - i] = dl;
        temp[rr - i][cc + i] = ur;
    }
}

void solve()
{
    vector<int> intVec;
    for(int i=1;i<=K;i++)
        intVec.push_back(i);
    do {
        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++)
                temp[i][j] = table[i][j];
    
        for (int i=0;i<K;i++)
            rotate(intVec[i]);
        for(int i=1;i<=N;i++)
        {
            int sum = 0;
            for(int j=1;j<=M;j++)
                sum += temp[i][j];
            if (sum < ans) ans = sum;
        }            
    } while (next_permutation(intVec.begin(), intVec.end()));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin>>table[i][j];
    for(int i=1;i<=K;i++)
        cin>>r[i]>>c[i]>>s[i];
    solve();
    cout<<ans;
    return 0;
}
