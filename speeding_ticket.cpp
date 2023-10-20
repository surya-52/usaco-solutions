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
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
#endif
}


signed main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
      int n,m;
      cin >> n >> m;
      vector<pair<int,int>> v(n);
      for(int i = 0 ; i < n ; i++){
        cin >> v[i].first >> v[i].second;
      }
      vector<pair<int,int>> a(m);
      for(int i = 0 ; i < m ; i++){
        cin >> a[i].first >> a[i].second;
      }
      int sum1 = v[0].first;
      int sum2 = a[0].first;
      int ma = 0;
      int i = 0,j=0;
      while(j<m || i<n){
        ma = max(ma,a[j].second-v[i].second);
        if(sum1 > sum2){
            j++;
            sum2 += a[j].first;
        }
        else if(sum2 > sum1){
            i++;
            sum1 += v[i].first;
        }
        else{
            i++;
            sum1 += v[i].first;
            j++;
            sum2 += a[j].first;
        }
      }

    cout<<ma<<endl;
    }
    return 0;
      }
