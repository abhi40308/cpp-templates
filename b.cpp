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
	string s;
	cin>>s;
	unique(s.begin(), s.end());
	cout<<s<<endl;
	// int n = unique(s.begin(), s.end()) - s.begin();
	// int count = 0;
	// int n = s.size();
	// int total_z = 0;
	// for(int i = 0; i < n ; i++){
	// 	count=0;
	// 	while(s[i] == '0'){
	// 		count++;
	// 		i++;
	// 	}
	// 	total_z += count;
	// }
	// cout<<total_z<<" ";
	// cout<<endl;
	return 0;
}