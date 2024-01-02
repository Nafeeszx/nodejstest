#include <bits/stdc++.h>
using namespace std;
#define trav(a, x) for(auto& a : x)
#define vi vector<int>
#define vvl vector<vector<ll>>
#define all(v) (v).begin(),(v).end()
typedef long long ll;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

const int mod = 1e9 + 7, MOD = 998244353;

ll inc_exc [] = {-1, +1, -1, +1, -1, +1};

struct s5 {
    int n;
    int v[5];
};

bool operator< (const s5 &a, const s5 &b) {
    for(int j = 0; j < 5; ++j) {
        if(a.v[j] < b.v[j]) return true;
        if(a.v[j] > b.v[j]) return false;
    }
    return false;
} // ei comparator ta map er jonno crucial

s5 get_subset(s5 &a, int x) {
    s5 result = {0, {0, 0, 0, 0, 0}};
    for(int j = 0; j < 5; ++j) 
        if((1 << j) & x) 
            result.v[result.n++] = a.v[j]; 
    return result;
}

map<s5, int> subsets;

s5 A[50000];

int main() 
{	
    setIO("cowpatibility");
    ll n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        A[i].n = 5;
        for(int j = 0; j < 5; ++j) {
            cin >> A[i].v[j];
        }
        sort(A[i].v, A[i].v+5);
        for(int x = 1; x < 32; ++x) subsets[get_subset(A[i],x)]++;
    }

    ll res = n * (n-1) / 2;
    trav(p, subsets) {
        res -= inc_exc[p.first.n] * p.second * (p.second - 1) / 2;
    }
    cout << res;

    return 0;
}

