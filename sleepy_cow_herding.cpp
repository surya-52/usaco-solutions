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
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
#endif
}


int32_t main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
      vector<int> v(3);
      for(auto &x:v) cin >> x;
      sort(v.begin(),v.end());
      int x = min(v[2]-v[1],v[1]-v[0])-1;
      int y = max(v[1]-v[0],v[2]-v[1])-1;
      if(x==0 and y==0){
        cout<<0<<endl<<0<<endl;
        continue;
      }
      if(x==0 and y>0){
        x = y;
      }
      if(x>2){
        x = 2;
      }
      cout<<x<<endl<<y<<endl;

    }
    return 0;
      }
