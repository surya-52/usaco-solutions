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
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
#endif
}


int32_t main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
      int n;
      cin >> n;
      vector<pair<int,int>> v(n);
      for(int i = 0 ; i < n ; i++){
        cin >> v[i].first >> v[i].second;
        v[i].first += 10000;
        v[i].second += 10000;
      }
      int ans = INT_MIN;
      for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < n ; k++){
                if(v[i].second == v[j].second and v[i].first == v[k].first){
                   ans = max(ans,abs(v[j].first-v[i].first)*abs(v[i].second-v[k].second));
                }
            }
        }
      }
      cout<<ans<<endl;

    }
    return 0;
      }
