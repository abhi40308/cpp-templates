// #include <bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <math.h>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <sstream>
#include<numeric>
using namespace std;
#define endl "\n"
typedef long double ld;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
// g++ -DXOX --std=c++14 main.cpp && ./a.out
// ./a.out < input_file > output_file

/** debug starts **/
vector<string> vec_splitter(string s)
{
	s += ',';
	vector<string> res;
	while (!s.empty())
	{
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
	vector<string> __attribute__((unused)) args,
	__attribute__((unused)) int idx,
	__attribute__((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T)
{
	if (idx > 0)
		cerr << ", ";
	else
		cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss;
	ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
// #ifndef ONLINE_JUDGE // dangerous for other platforms, might print debug lines. Change to #ifdef XOX and use -DXOX compiler flag
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
/** debug ends **/

void run()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// srand(time(NULL));
}
int btod(string bin) { return stoi(bin, nullptr, 2); }
// string dtob(int n) { return bitset<8>(n).to_string(); }

const int N = 300500;
const int mod = 1000000007;
ll fact[N+1];
ll invFact[N+1];

// smart stuff to calculate inv factorial
ll fast_pow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p % 2 == 0) {
            a = (a * a) % mod;
            p /= 2;
        } else {
            res = (res * a) % mod;
            p--;
        }
    }
    return res;
}

// calculate nCr = n! * (1/ n!) * (1 / (n-r)!)
ll C(int n, int k) {
    if (k > n) {
        return 0;
    }
    return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> v(n);
    for (ll &e : v) {
        cin >> e;
    }
    sort(v.begin(), v.end());
    for(auto i : v)
        cout<<i<<" ";
    cout<<endl;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i + 1;
        int r = upper_bound(v.begin(), v.end(), v[i] + k) - v.begin();
        debug(l,r, r - l, m - 1);
        ans = (ans + C(r - l, m - 1)) % mod;
    }
    cout << ans << "\n";
}

int main() {
    fact[0] = invFact[0] = 1;
    for (ll i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        // fermat's little theorem https://codeforces.com/blog/entry/72527
        // in general: a^(-1) = a^(m-2) mod m when m is prime
        invFact[i] = fast_pow(fact[i], mod - 2);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}