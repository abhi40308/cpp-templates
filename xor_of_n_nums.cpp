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

int computeXOR(int n)
{
   
  // If n is a multiple of 4
  if (n % 4 == 0)
    return n;
 
  // If n%4 gives remainder 1
  if (n % 4 == 1)
    return 1;
 
  // If n%4 gives remainder 2
  if (n % 4 == 2)
    return n + 1;
 
  // If n%4 gives remainder 3
  return 0;
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
        int c = computeXOR(n-1);
        if(c == k) cout<<n<<endl;
        else {
            int p = c ^ k;
            if(p != n){
                cout<<n+1<<endl;
            }
            else cout<<n+2<<endl;
        }
	}
	return 0;
}