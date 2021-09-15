// #include <bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <cstring>
#include <math.h>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
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
int min(int x, int y, int z) { return min(min(x, y), z); }

int main()
{
	run();
	int t;
	cin >> t;
	while (t--)
	{
		ll n, a, b;
		cin>>n>>a>>b;
		string s;
		cin>>s;
		ll ans = a * n;
		if(b >= 0){
			ans += b*n;
		}
		else {
			int u = unique(s.begin(), s.end()) - s.begin();
			ans += b * (u/2 + 1);
		}
		cout<<ans<<endl;
	}
	return 0;
}