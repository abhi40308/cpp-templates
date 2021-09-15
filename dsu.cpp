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

void initialize(int Arr[], int size[], int N)
{
    for (int i = 0; i < N; i++)
    {
        Arr[i] = i;
        size[i] = 1;
    }
}

int root(int Arr[], int i)
{
    while (Arr[i] != i)
    {
        i = Arr[i];
    }
    return i;
}

bool find(int Arr[], int A, int B)
{
    if (root(Arr, A) == root(Arr, B))
        return true;
    else
        return false;
}

void wunion(int Arr[], int size[], int A, int B)
{
    int root_A = root(Arr, A);
    int root_B = root(Arr, B);
    if (root_A == root_B)
        return;
    if (size[root_A] < size[root_B])
    {
        Arr[root_A] = Arr[root_B];
        size[root_B] += size[root_A];
    }
    else
    {
        Arr[root_B] = Arr[root_A];
        size[root_A] += size[root_B];
    }
}

int main()
{
    run();
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    int Arr1[n], Arr2[n], size1[n], size2[n];
    initialize(Arr1, size1, n);
    initialize(Arr2, size2, n);

    int x, y;
    for (int i = 0; i < m1; i++)
    {
        cin >> x >> y;
        wunion(Arr1, size1, x - 1, y - 1);
    }
    for (int i = 0; i < m2; i++)
    {
        cin >> x >> y;
        wunion(Arr2, size2, x - 1, y - 1);
    }

    int m = max(m1, m2);
    if (n - 1 > m)
    {
        m = n - 1 - m;
    }
    else
    {
        cout << 0;
        return 0;
    }

    cout << m << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (!find(Arr1, i, j) && !find(Arr2, i, j))
            {
                wunion(Arr1, size1, i, j);
                wunion(Arr2, size2, i, j);
                cout << i + 1 << " " << j + 1 << endl;
                m--;
            }
            if (m <= 0)
                break;
        }
        if (m <= 0)
            break;
    }

    return 0;
}