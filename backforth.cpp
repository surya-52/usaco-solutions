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
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
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
void back_track(vector<int> a,vector<int> b,set<int> &ans,int ct,int total,int total2){
    // cout<<ct<<endl;
    if(ct == 4){
        // cout<<total<<endl;
        ans.insert(total);
        return;
    }
    if(ct%2){
        for(int i = 0; i < b.size(); i++){
            vector<int> new_a(a),new_b(b);
            new_a.pb(b[i]);
            new_b.erase(new_b.begin()+i);
            back_track(new_a,new_b,ans,ct+1,total+b[i],total2-b[i]);

        }
    }
    else{
        for(int i = 0; i < a.size(); i++){
            vector<int> new_a(a),new_b(b);
            new_b.pb(a[i]);
            new_a.erase(new_a.begin()+i);
            back_track(new_a,new_b,ans,ct+1,total-a[i],total2+a[i]);
        }
    }
}
signed main()
{  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    cpc();
    while(t--){
        vector<int> a(10),b(10);
        for(auto &x: a) cin >> x;
        for(auto &x: b) cin >> x;
        set<int> ans;
        int ct = 0,total = 1000,total2 = 1000;
        back_track(a,b,ans,ct,total,total2);
        cout<<ans.size()<<endl;

    }
    return 0;
}
