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
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
#endif
}

signed main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> v(n,vector<int> (n));
        for(int i = 0 ; i < n ; i++){
           string s;
           cin >> s;
           for(int j = 0 ; j < n ; j++){
            v[i][j] = s[j] - '0';
           }
        }
        //  for(int i = 0 ; i < n ; i++){
        //     for(int j = 0 ; j < n; j++){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<pair<int,int>> valuesi(10);
        vector<pair<int,int>> valuesj(10);
        for(int i = 1 ; i <= 9 ; i++){
            valuesj[i] = {20,-1};
            valuesi[i] = {20,-1};
        }
        for(int color = 1 ; color <= 9 ; color++){
            int l = -1;
         for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(v[i][j] == color){
                   valuesi[color].first = min(valuesi[color].first,i);
                   valuesi[color].second = max(valuesi[color].second,i);
                   valuesj[color].first = min(valuesj[color].first,j);
                   valuesj[color].second = max(valuesj[color].second,j);
                 }
            }
         }
     }
    set<int> s;     
    for(int i = 1 ; i <= 9 ; i++){
            // cout<<i<<endl;
            // cout<<valuesi[i].first<<" "<<valuesi[i].second<<endl;
            // cout<<valuesj[i].first<<" "<<valuesj[i].second<<endl;
            if(valuesj[i].second != -1) s.insert(i);
         }   
    for(int color = 1 ; color <= 9 ; color++){
        if(valuesi[color].second !=-1){
        for(int i = valuesi[color].first ; i <= valuesi[color].second ; i++){
            for(int j = valuesj[color].first ; j <= valuesj[color].second ; j++){
               if(v[i][j]!=color) s.erase(v[i][j]);
            }
        }
      }
    }
    cout<<s.size()<<endl;    
    }   
    return 0;
      }
