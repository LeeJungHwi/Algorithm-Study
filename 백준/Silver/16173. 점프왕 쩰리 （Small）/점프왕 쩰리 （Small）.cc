#include <bits/stdc++.h>
using namespace std;

#define home 0

#define ll long long

#define pii pair<int, int>
#define pll pair<ll, ll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)
#define aloop(t, v, s, c, e, i) for(t v = (s); v c (e); i)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define vec(t, v, r) vector<t> v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define gmat(t, v, r) vector<vector<t> > v((r))
#define dir vector<pii> cd = { {1, 0}, { 0, 1 } }

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 점프왕 쩰리 (Small)
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n;
	cin >> n;
	mat(int, graph, n, n);
	mat(bool, vis, n, n);
	queue<pii> cp;
	dir;
	loop(i, home, n) loop(j, home, n) cin >> graph[i][j];
	cp.push({ home, home });
	vis[home][home] = true;
	while (!cp.empty())
	{
		pii s = cp.front();
		cp.pop();
		if (graph[s.lhs][s.rhs] == -1) { elp("HaruHaru"); return home; }
		loop(i, home, 2)
		{
			int ci = s.lhs + cd[i].lhs * graph[s.lhs][s.rhs];
			int cj = s.rhs + cd[i].rhs * graph[s.lhs][s.rhs];
			if (ci < home || cj < home || ci >= n || cj >= n) continue;
			if (vis[ci][cj]) continue;
			cp.push({ ci, cj });
			vis[ci][cj] = true;
		}
	}
	elp("Hing");

	return home;
}