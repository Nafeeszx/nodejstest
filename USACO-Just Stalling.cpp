#include <bits/stdc++.h>
using namespace std;
#define trav(a, x) for(auto& a : x)
#define vi vector<int> 
typedef long long ll;

const int mod = 1e9 + 7, MOD = 998244353;

const int MAXN = 1e6;

int main()
{	
    int n;
    cin >> n;
    vector<int> cows(n), stall(n);
    for(int i = 0; i < n; ++i) cin >> cows[i];
    for(int i = 0; i < n; ++i) cin >> stall[i];
    sort(cows.begin(), cows.end());
    sort(stall.begin(), stall.end());
    ll res = 1;
    for(int i = n-1; i >= 0; --i) {
        ll p = 0;
        int j = i;
        while(stall[j] >= cows[i] && j >= 0) {
            p++;
            j--;
        }
        res *= p;
    }
    cout << res;
    return 0;
}



