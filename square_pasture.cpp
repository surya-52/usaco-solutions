#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
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
#define mod             1000000007
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
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
#endif
}
int interse(int a1,int b1,int a2,int b2,int c1,int d1,int c2,int d2){
   return (max(min(b2,d2)-max(b1,d1),(int)0))*(max(min(a2,c2)-max(a1,c1),(int)0));
}
signed main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
       int a1,b1,a2,b2;
       cin >> a1 >> b1 >> a2 >> b2;
       int x1,y1,x2,y2;
       cin >> x1 >> y1 >> x2 >> y2;
       int c1 = min(a1,x1);
       int c2 = min(b1,y1);
       int c3 = max(a2,x2);
       int c4 = max(b2,y2);
       int z = max(c3-c1,c4-c2);
       cout<<(z*z)<<endl;
      }
      
    return 0;
      }
