#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using std::mt19937_64;
using std::random_device;
using std::uniform_int_distribution;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18+1
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
void cpc()
{
#ifndef ONLINE_JUDGE
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
#endif
}
int dx[] = {-1, 0, 1, 0,1,1,-1,-1};
int dy[] = {0, 1, 0, -1,1,-1,1,-1};
int exponent(int x, int n, int m) {
    if(x == 0 and n == 0) return 1;
    x %= m; 
    int res = 1;
    while (n > 0) {
        if (n % 2 == 1) { res = res * x % m; }
        x = x * x % m;
        n /= 2;
    }
    return res;
}
int gcd(int a,int b){
    if(a == 0) return b;
    return gcd(b%a,a);
}
struct edge{
  int dist,node,par;
};
struct DSU {
    vi e; 
    void init(int N) { 
        e = vi(N+1,-1); 
    }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) { // union by size
        x = get(x), y = get(y); if (x == y) return 0;
        if (e[x] > e[y]) swap(x,y);
        e[x] += e[y];
        e[y] = x; return 1;
    }
};
const int maxN = 2e5+5;
int fact[maxN+1];
int inverse_fact[maxN+1];
void factorial(){
    fact[0] = 1;
    for(int i = 1 ; i <= maxN; i++){
      fact[i] = (fact[i-1]*i)%mod;
    }
}
void inverse(){
  inverse_fact[maxN] = exponent(fact[maxN],mod-2,mod);
  for(int i = maxN; i >= 0; i--){
    inverse_fact[i-1] = (inverse_fact[i] * i) % mod;
  }
}
int ncr(int n,int r){
   return (((fact[n] * inverse_fact[r]) % mod) * inverse_fact[n-r])%mod;
}
struct segTree{
 int n;
 vector<int> v;
 segTree(int n) : n(n){
    v.resize(4*n,0);
 }
 void buildTree(int node,int l,int r,vector<int> &a){
   if(l == r){
    (v[node] = a[l]);
    return;
   }
   int mid = (l+r)/2;
   buildTree(2*node,l,mid,a);
   buildTree(2*node+1,mid+1,r,a);
   v[node] = v[2*node]+v[2*node+1];
 }
 void update(int node,int l,int r,int idx,int value){
   if(l == r){
    v[node] = value;
    return;
   }
   int mid = (l+r)/2;
   if(idx <= mid){
    update(2*node,l,mid,idx,value);
   }
   else {
    update(2*node+1,mid+1,r,idx,value);
   }
   v[node] = v[2*node]+v[2*node+1];
 }
 int query(int node,int l,int r,int x,int y){
     if(x <= l and r <= y){
        return v[node];
     }
     int mid = (l+r)/2;
     int ans = 0;
     if(x <= mid){
        ans += query(2*node,l,mid,x,y);
     }
     if(y > mid){
        ans += query(2*node+1,mid+1,r,x,y);
     }
     return ans;
 }
};
bool check(int x,int y,int n,int m){
    if(x >= n or y >= m or x < 0 or y < 0) return false;
    return true;
}

signed main()
{  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cpc();
    int t=1;
    // cin >> t;
    while(t--){
        int n,m,d,s;
        cin >> n >> m >> d >> s;
        vector<vector<pii>> v(n+1);
        for(int i = 0; i < d; i++){
            int p;
            cin >> p;
            int milk,ti;
            cin >> milk >> ti;
            v[p].pb({milk,ti});
        }
        vector<int> sick(n+1);
        for(int i = 0; i < s; i++){
            int p,ti;
            cin >> p >> ti;
            sick[p] = ti;
        }
        set<int> st;
        for(int i = 1; i <= n; i++){
            if(sick[i]){
                for(int j = 0; j < v[i].size(); j++){
                    if(v[i][j].ss < sick[i]){
                        st.insert(v[i][j].ff);
                    }
                }
            }
        }
        set<int> st2;
        st2 = st;
        for(auto &x: st){
            for(int i = 1; i <= n; i++){
                if(sick[i]){
                    bool pres = false;
                    for(int j = 0; j < v[i].size(); j++){
                        if(v[i][j].ss < sick[i] and v[i][j].ff == x){
                            pres = true;
                            break;
                        }
                    }
                    if(!pres) {st2.erase(x);break;}
                }
            }
        }
        int ans = 0;
        for(auto &x: st2){
            int ct = 0;
            for(int i = 1; i <= n; i++){
                bool pres = false;
                for(int j = 0; j < v[i].size(); j++){
                    if(v[i][j].ff == x) pres = true;
                }
                if(pres) ct++;
            }
            ans = max(ans,ct);
        }
        cout<<ans<<endl;


    }
    return 0;
}
