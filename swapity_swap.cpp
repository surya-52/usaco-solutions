#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using std::mt19937_64;
using std::random_device;
using std::uniform_int_distribution;
#include <numeric>
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
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("swap.out", "w", stdout);
    freopen("swap.in", "r", stdin);
#endif
}

signed main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
     int n,k;
     cin >> n >> k;
     int a1,a2;
     cin >> a1 >> a2;
     int b1,b2;
     cin >> b1 >> b2;
     vector<int> a(n+1),b(n+1);
     for(int i = 1 ; i <= n; i++) {
        a[i] = i;
        b[i] = i;
     }
     a2++;
     b2++;
     int ct = 0;
     while(true){
        reverse(a.begin()+a1,a.begin()+a2);
        reverse(a.begin()+b1,a.begin()+b2);
        ct++;
        if(a == b) break;
     }
     // cout<<ct<<endl;
     int x = (k%ct);
     // cout<<x<<endl;
     for(int i = 0 ; i < x; i++){
        reverse(b.begin()+a1,b.begin()+a2);
        reverse(b.begin()+b1,b.begin()+b2);
     }
     for(int i = 1; i <= n; i++) cout<<b[i]<<endl;

   }
    return 0;
      }
