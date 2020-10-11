#include <iostream>

using namespace std;

int n,k, W[101], V[101], ans[100001];
int solve()
{
    for(int i=0;i<n;i++)
    {
        for(int j=k;j>1;j--)
        {
            if(W[i] <= j){
                ans[j] = max(ans[j], ans[j-W[i]] + V[i]);
            }
        }
    }

    return ans[k];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;

    for(int i=0;i<n;i++)
        cin>>W[i]>>V[i];

    cout<<solve();
    return 0;
}
