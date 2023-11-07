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
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
#endif
}


int32_t main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
    int n,k;
    cin >> k >> n;
    vector<vector<int>> v(n+1,vector<int> (k));
    for(int i = 0 ; i < k ; i++){
      for(int j = 0 ; j < n ; j++){
        int x;
        cin >> x;
        v[x][i] = j;
      }
    }
    // for(int i = 1 ; i <= n ; i++){
    //     for(int j = 0 ; j < k ; j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int count = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(j!=i){
           bool pres = true;
           for(int m = 0 ; m < k ; m++){
              if(v[i][m]<v[j][m]) pres = false;
           }
           if(pres) count++;
           }
        }
    }
    cout<<count<<endl;
    }
    return 0;
      }
