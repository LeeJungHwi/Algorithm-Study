#include <bits/stdc++.h>
using namespace std;

#define home 0

#ifdef ONLINE_JUDGE
#define init ios_base::sync_with_stdio(home); cin.tie(home)
#else
#define init ios_base::sync_with_stdio(home); cin.tie(home); ifstream cin("input.txt")
#endif

#define ll long long
#define ld long double

#define pii pair<int, int>
#define pll pair<ll, ll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define tvec(t, v) vector<t> v
#define vec(t, v, r) vector<t> v((r))
#define gmat(t, v, r) vector<vector<t> > v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))

#define dir vector<pii> cd = { {1, 2}, {1, -2}, {-1, 2 }, { -1, -2 }, { 2, 1 }, { 2, -1 }, { -2, 1 }, { -2, -1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// Zajac
int main()
{
	init;

	int n, m; cin >> n >> m;
	mat(char, graph, n, m);
	mat(int, dis, n, m);
	queue<pii> cp; dir;
	loop(i, home, n) loop(j, home, m)
	{
		cin >> graph[i][j];
		if (graph[i][j] == 'z')
		{
			cp.push({ i, j });
			dis[i][j] = 1;
		}
	}
	while (!cp.empty())
	{
		pii s = cp.front(); cp.pop();
		if (graph[s.lhs][s.rhs] == 'n')
		{
			elp(--dis[s.lhs][s.rhs]);
			return home;
		}
		loop(i, home, 8)
		{
			int ci = s.lhs + cd[i].lhs;
			int cj = s.rhs + cd[i].rhs;
			if (ci < home || cj < home || ci >= n || cj >= m) continue;
			if (dis[ci][cj] > home) continue;
			if (graph[ci][cj] == 'x') continue;
			cp.push({ ci, cj });
			dis[ci][cj] = dis[s.lhs][s.rhs] + 1;
		}
	}
	elp("NIE");

	return home;
}