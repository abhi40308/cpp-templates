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
void run()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// srand(time(NULL));
}
int min(int x, int y, int z) { return min(min(x, y), z); }
void sieve(int n)
{
	int prime[n]; // make global
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i < n; i++)
	{
		prime[i] = true;
		for (int j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				prime[i] = false;
			}
		}
	}
}

int main()
{
	run();
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
	}
	return 0;
}