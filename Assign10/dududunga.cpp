#include <iostream>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;

int N, child[300001];
ll g_cnt, d_cnt;
vector<int>info[300001];

ll ncr(ll n, ll r) {
	if (n < r) {
		return 0;
	}
	if (r == 2LL) {
		return n * (n - 1) / 2LL;
	}
	if (r == 3LL) {
		return n * (n - 1) * (n - 2) / 6LL;
	}
	return 0;
}


void dfs(int node, int parent)
{
	for (auto next : info[node]) {
		if (next != parent) {
			child[node] += 1;
			dfs(next, node);
		}
	}
	if (~parent) {
		g_cnt += ncr(child[node], 2LL);
		for (auto next : info[node]) {
			if (next != parent) {
				d_cnt += child[next];
			}
		}
	}

	g_cnt += ncr(child[node], 3LL);
	for (auto next : info[node]) {
		if (next != parent) {
			d_cnt += child[next] * (child[node] - 1);
		}
	}
	return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int U,V;
    cin>>N;
	for(int i=0;i<N-1;i++)
	{
		cin>>U>>V;
		info[U].push_back(V);
		info[V].push_back(U);
	}
	
	dfs(1,-1);

	if (d_cnt == g_cnt * 3) {
		cout << "DUDUDUNGA";
	}
	else {
		if (d_cnt > g_cnt*3) {
			cout << "D";
		}
		else {
			cout << "G";
		}
	}
    return 0;
}
