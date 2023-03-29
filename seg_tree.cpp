// #include <bits/stdc++.h>
#include <math.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// #define endl "\n"
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
const int INF = 1e9;
const int MOD = 1e9 + 7;
// g++ -DXOX --std=c++14 main.cpp && ./a.out
// ./a.out < input_file > output_file

/** debug starts **/
vector<string> vec_splitter(string s) {
    s += ',';
    vector<string> res;
    while (!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) int idx,
               __attribute__((unused)) int LINE_NUM) {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if (idx > 0)
        cerr << ", ";
    else
        cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss;
    ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
// #ifndef ONLINE_JUDGE // dangerous for other platforms, might print debug
// lines. Change to #ifdef XOX and use -DXOX compiler flag
#ifdef XOX
#define debug(...) \
    debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

#ifdef XOX
#define debug(...) \
    debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

// std::bitset<32>(2).to_string() = 00000000000000000000000000000010 (convert 10 to binary string)
// bitset<32>(binary).to_ulong(); = convert binary string to decimal

template <class F>
void print(vector<F> &v) {
    cout << "\nvector : ";
    for (F i : v) {
        cout << i << " ";
    }
    cout << endl;
}

void print(vector<pi> &v) {
    cout << "\nvector : ";
    for (pi i : v) {
        cout << "<" << i.first << ", " << i.second << "> ";
    }
    cout << endl;
}

template <class F>
void print(vector<vector<F> > &v) {
    cout << "\n2-D vector :\n";
    for (vector<F> i : v) {
        for (F j : i) cout << j << " ";
        cout << endl;
    }
    cout << endl;
}

/** debug ends **/

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // srand(time(NULL));
}

ll gcd(ll n1, ll n2) {
    if (n2 != 0)
        return gcd(n2, n1 % n2);
    else
        return n1;
}

ll power(ll a, ll b, ll mod) {
    if (b == 0) {
        return 1;
    }
    ll ans = power(a, b / 2, mod);
    ans *= ans;
    ans %= mod;
    if (b % 2) {
        ans *= a;
    }
    return ans % mod;
}

void buildtr(vector<int> &t, vector<int> &nums, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = nums[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    buildtr(t, nums, 2 * v, tl, tm);
    buildtr(t, nums, 2 * v + 1, tm + 1, tr);
    t[v] = t[2 * v] + t[2 * v + 1];
    // t[i] = max(t[2*v], t[2*v + 1]);  // for finding maximum
}

int query(vector<int> &t, int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return query(t, 2 * v, tl, tm, l, min(r, tm)) + query(t, 2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
    // return max(query(t, 2*v, tl, tm, l, min(r, tm)),query(t, 2*v+1, tm+1, tr, max(tm+1, l), r));
}

void update(vector<int> &t, int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        update(t, 2 * v, tl, tm, pos, new_val);
    else
        update(t, 2 * v + 1, tm + 1, tr, pos, new_val);

    t[v] = t[v * 2] + t[v * 2 + 1];
    // t[v] = max(t[2*v], t[2*v + 1]);
}

int main() {
    fastIO();
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> tr(4 * n + 1, 0);
    buildtr(tr, v, 1, 0, n - 1);

    for (int i = 0; i < 4 * n; i++) {
        cout << i << ": " << tr[i] << endl;
    }

    int x, y, type;
    while (q--) {
        cin >> type;
        cin >> x >> y;
        if (type == 0)
            cout << query(tr, 1, 0, n - 1, x - 1, y - 1) << endl;
        else
            update(tr, 1, 0, n - 1, x - 1, y);
    }

    return 0;
}