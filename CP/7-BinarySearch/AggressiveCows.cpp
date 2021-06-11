#include "bits/stdc++.h" 
using namespace std;

#define int long long
#define endl "\n"

#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x << " ++> "; _print(x); cerr << endl;
#else
#define deb(x)
#endif

template<typename T>        void _print(T n);
template <class T, class V> void _print(pair <T, V> p);
template <class T>          void _print(vector <T> v);
template <class T>          void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T>          void _print(multiset <T> v);
template<typename... T>     void read(T&... args);
template<typename... T>     void write(string delimiter, T &&...args);
template<typename T>        void readContainer(T &t);
template<typename T>        void writeContainer(string delimiter, T &t);
//----------------------------------------------------------------------------------------------------//

bool canBePlaced(vector<int> &stallLocation, int dist, int c){
    int lastPosition = -1;
    int cws = c;
    for(int i=0; i<stallLocation.size(); ++i){
        if(stallLocation[i] - lastPosition >= dist or lastPosition == -1){
            cws--;
            lastPosition = stallLocation[i];
        }
        if(cws == 0) 
            break;
    }
    return cws == 0;
}

void solve(){
    int n,c; read(n,c);
    vector<int> stallLocation(n);
    readContainer(stallLocation);
    sort(stallLocation.begin(), stallLocation.end());
    int lo(0), hi(1e9);
    while(hi - lo > 1){
        int mid = (lo + hi)/2;
        if(canBePlaced(stallLocation, mid, c)){
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    if(canBePlaced(stallLocation, hi, c)){
        cout<<hi<<endl;
    } else {
        cout<<lo<<endl;
    }
}

signed main(){
/**************************************/
#ifndef ONLINE_JUDGE
	freopen(".deb.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
/**************************************/
    int T;
    cin >> T;
    while (T--){
        solve();
    }
}


//----------------------------------------------------------------------------------------------------//
template <typename... T>
void read(T &...args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(string delimiter, T &&...args) {
    ((cout << args << delimiter), ...);
}

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) {
        read(e);
    }
}

template <typename T>
void writeContainer(string delimiter, T &t) {
    for (const auto &e : t) {
        write(delimiter, e);
    }
    write("\n");
}

template<typename T> 
void _print(T n) {
    cerr << n;
}

template<typename T> 
void _print(vector<T> v) {
    cerr << '[';
    for (auto val : v) {
        cerr << val;
        cerr << ' ';
    }
    cerr << ']';
}
template <class T, class V> 
void _print(pair <T, V> p) {
    cerr << "{"; 
    _print(p.first); 
    cerr << ","; 
    _print(p.second); 
    cerr << "}";
}

template <class T> 
void _print(set <T> v) {
    cerr << "[ "; 
    for (T i : v) {
        _print(i); 
        cerr << " ";
    } 
    cerr << "]";
}
template <class T> void _print(multiset <T> v) {
    cerr << "[ "; 
    for (T i : v) {
        _print(i); 
        cerr << " ";
    } cerr << "]";}

template <class T, class V> void _print(map <T, V> v){
    cerr << "[ "; 
    for (auto i : v) {
        _print(i); 
        cerr << " ";
    } 
    cerr << "]";
}

