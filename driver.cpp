#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include <math.h>
using namespace std;

int lcs(string a, string b, int i, int j){
	if(i < 0 ||  j < 0) return 0;
	if(a[i] == b[j]) return lcs(a,b, i-1, j-1);
	else {
		return min(lcs(a, b, i-1, j), lcs(a,b,i-1,j-1) + 1, lcs(a,b, i, j-1) );
	}
}

int driver(string a, string b) {
	if(a.size() == 0) return b.size();
	if(b.size() == 0) return a.size();
	return lcs(a,b,a.size()-1,b.size()-1);
}

int main(){
	string a = "sunday";
	string b = "saturday";
	cout<<driver(a,b)<<endl;
	return 0;
}