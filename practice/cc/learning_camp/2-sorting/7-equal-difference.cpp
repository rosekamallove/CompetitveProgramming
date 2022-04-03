#include "bits/stdc++.h"
using namespace std; template <typename... T> void read(T &...args) { ((cin >> args), ...); } template <typename T> void readContainer(T &t) { for (auto &e : t) { read(e); } } template<typename T> void _print(T n) { cerr << n; } template<typename T> void _print(vector<T> v) { cerr << "[ "; for (auto val : v) { cerr << val; cerr << ' '; } cerr << "]"; } template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}"; } template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; } template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; } template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }

#define int long long
#define endl "\n"

#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ins insert

#ifndef ONLINE_JUDGE
#define deb(x) cerr<<#x<<" -> "; _print(x); cerr<<endl;
#else
#define deb(x)
#endif


int T(1);

void testCase() {
    int n; cin>>n;
    vector<int> v(n), temp;
    readContainer(v); temp = v;
    map<int, int> mp;

    sort(all(v));

    for(int i=0; i<n; i++) {
        mp[v[i]]++;
    }

    if(n <= 2) {
        cout<<0<<endl;
        return;
    }

    int mx = INT_MIN;
    for(auto x : mp)
        mx = max(x.second, mx);

    if(mx == 1) {
        cout<<n-2<<endl;
    } else {
        cout<<n - mx<<endl;
    }

}

void testCase1() {
    int n; cin>>n;
    vector<int> v(n), temp;
    readContainer(v); temp = v;
    map<int, int> mp;

    sort(all(v));

    for(int i=0; i<n; i++) {
        mp[v[i]]++;
    }

    auto pr = 
        max_element(mp.begin(), mp.end(), [](const auto &x, const auto &y) {
                    return x.second < y.second;
                });
    int mx = pr->first, ans(0);

    if(n <= 2) {
        cout<<0<<endl;
        return;
    }

    if(mx == 1) {
        cout<<n-2<<endl;
    } else {
        cout<<n-mx<<endl;
    }
}


signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

#ifndef ONLINE_JUDGE
    freopen(".deb.txt", "w", stderr);
#endif

    cin >> T;
    while (T--) {
        testCase();
        cerr<<endl;
    }
}
