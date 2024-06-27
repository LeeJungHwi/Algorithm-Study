#include <bits/stdc++.h>
using namespace std;

#define home 0

#define ll long long
#define ld long double

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
#define dir vector<pii> cd = { {-1, 0}, {1, 0}, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 출석체크
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n, m, k, l;
	cin >> n >> m >> k >> l;
	map<int, int> sMap;
	int num;
	loop(i, home, m) { cin >> num; sMap[num]++; }
	vec(int, v, k);
	loop(i, home, k) cin >> v[i];
	map<int, int> cMap;
	loop(i, home, k)
	{
		if (sMap[v[i]]) continue;
		int t = v[i];
		while (t <= n + 2 && t >= 3)
		{
			if (!sMap[t]) cMap[t]++;
			t += v[i];
		}
	}
	vec(int, dp, n + 3);
	loop(i, 3, n + 3) dp[i] = dp[i - 1] + cond(cMap[i], home, 1);
	loop(i, home, l)
	{
		int n1, n2;
		cin >> n1 >> n2;
		elp(dp[n2] - dp[n1 - 1]);
	}

	return home;
}