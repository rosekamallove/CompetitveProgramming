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
    vector<int> a(n), b(n-1);
    readContainer(a); readContainer(b);

    sort(all(a)); sort(all(b));

    int ans = b[0] - a[1];

    set<int> s;
    for(int &x : a) {
        s.insert(x);
    }

    for(int x : b) {
        if(s.count(x - ans) == 0) {
            ans = b[0] - a[0];
            break;
        }
    }

    if(ans <= 0) ans = b[0] - a[0];

    cout<<ans<<endl;
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

