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
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
void cpc()
{
#ifndef ONLINE_JUDGE
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
#endif
}
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
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
    bool unite(int x, int y) { 
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
    v.resize(4*n,inf);
 }
 void buildTree(int node,int l,int r,vector<int> &a){
   if(l == r){
    (v[node] = a[l]);
    return;
   }
   int mid = (l+r)/2;
   buildTree(2*node,l,mid,a);
   buildTree(2*node+1,mid+1,r,a);
   v[node] = min(v[2*node],v[2*node+1]);
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
   v[node] = min(v[2*node],v[2*node+1]);
 }
 int query(int node,int l,int r,int x,int y,int p){
       if(x > r or y < l) return 0;
       if(v[node] > p) return 0;
       if(l == r){
          v[node] = inf;
          return 1;
       }
       int mid = (l+r)/2;
       int s1,s2;
       s1 = query(2*node,l,mid,x,y,p);
       s2 = query(2*node+1,mid+1,r,x,y,p);
       v[node] = min(v[2*node],v[2*node+1]);
       return s1+s2;
 }
};
struct val{
    int a,b,p,money;
};
signed main()
{  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int> v(101,0);
        for(int i = 0; i < n; i++){
            int a,b,c;
            cin >> a >> b >> c;
            for(int j = a; j <= b; j++) v[j] += c;
        }
        vector<val> v2(m);
        int ans = 0;
        for(int i = 0; i < m; i++){
            cin >> v2[i].a >> v2[i].b >> v2[i].p >> v2[i].money;
            ans += v2[i].money;
        }
        for(int mask = 1; mask < (1<<m); mask++){
            vector<int> cur(101,0);
            int cur_money = 0;
            for(int j = 0; j < m; j++){
                if(mask&(1<<j)){
                    cur_money += v2[j].money;
                    for(int i = v2[j].a; i <= v2[j].b; i++){
                        cur[i] += v2[j].p;
                    }
                }
            }
            bool pres = true;
            for(int i = 1; i <= 100; i++){
                if(cur[i] < v[i]) pres = false;
            }
            if(pres) ans = min(ans,cur_money);
        }
        cout<<ans<<endl;

    }
    return 0;
}
