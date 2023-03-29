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
using namespace std;
#define endl "\n"
typedef long double ld;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
// g++ --std=c++11 main.cpp
// ./a.out < input_file > output_file
void run()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // srand(time(NULL));
}
int btod(string bin) { return stoi(bin, nullptr, 2); }
// string dtob(int n) { return bitset<8>(n).to_string(); }

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

void pusht(vector<int> &t, int v){
    
}

void buildtr(vector<int> &t, vector<int> &nums, int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = nums[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    buildtr(t, nums, 2 * v, tl, tm);
    buildtr(t, nums, 2 * v + 1, tm + 1, tr);
    t[v] = min(t[2*v], t[2*v+1]);
}

int query(vector<int> &t, int v, int tl, int tr, int pos)
{
    debug(v, tl, tr, pos);
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + query(t, 2 * v, tl, tm, pos);
    else
        return t[v] + query(t, 2 * v + 1, tm + 1, tr, pos);
}

void update(vector<int> &t, int v, int tl, int tr, int l, int r, int add)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[v] += add;
        return;
    }
    pusht(t, v);
    int tm = (tl + tr) / 2;
    update(t, 2 * v, tl, tm, l, min(r, tm), add);
    update(t, 2 * v + 1, tm + 1, tr, max(tm + 1, l), r, add);
}

int main()
{
    run();
    int n, q;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> tr(4 * n + 1, 0);
    buildtr(tr, v, 1, 0, n - 1);

    for (int i = 0; i < 4 * n; i++)
    {
        cout << i << ": " << tr[i] << endl;
    }

    cin >> q;
    int x,y,z;
    while (q--)
    {
        cin>>x>>y>>z;
    }

    return 0;
}