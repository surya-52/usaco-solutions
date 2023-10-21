#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#include <numeric>
#define ff              first
#define ss              second
// #define int             long long
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
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
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
      vector<pair<char,int>> v(n);
      for(int i = 0 ; i < n ; i++){
        cin >> v[i].first >> v[i].second;
      }
      int t = 1;
      vector<vector<set<int>>> a(2010,vector<set<int>> (2010));
      int x = 1000, y = 1000;
      int ti = 0;
      bool ans = false;
      for(int i = 0 ; i < n ; i++){
         if(v[i].first == 'N'){
            for(int j = 0 ; j < v[i].second ; j++){
                ti++;
                y++;
                a[x][y].insert(ti);
                if(a[x][y].size()>1) ans = true;
            }
         }
         else if(v[i].first == 'S'){
            for(int j = 0 ; j < v[i].second ; j++){
                ti++;
                y--;
                a[x][y].insert(ti);
                if(a[x][y].size()>1) ans = true;
            }
         }
         else if(v[i].first == 'E'){
            for(int j = 0 ; j < v[i].second ; j++){
                ti++;
                x++;
                a[x][y].insert(ti);
                if(a[x][y].size()>1) ans = true;
            }
         }
         else {
            for(int j = 0 ; j < v[i].second ; j++){
                ti++;
                x--;
                a[x][y].insert(ti);
                if(a[x][y].size()>1) ans = true;
            }
         }
      }
      // for(int i = 90 ; i < 120 ; i++){
      //   for(int j = 90 ; j < 120 ; j++){
      //       if(a[i][j].size()>1){
      //       cout<<i<<" "<<j<<endl;
      //       for(auto x:a[i][j]){
      //           cout<<x<<" ";
      //       }
      //       cout<<endl;
      //   }
      //   }
      // }
      int ma = INT_MAX;
      if(!ans) cout<<-1<<endl;
      else{
      for(int i = 0 ; i < 2010 ; i++){
        for(int j = 0 ; j < 2010 ; j++){
            if(a[i][j].size()>1){
               auto it = a[i][j].begin();
               auto it2 = it;
               it2++;
               while(it2!=a[i][j].end()){
                int a = *(it);
                int b = *(it2);
                ma = min(ma,b-a);
                it++;
                it2++;
               }
            }
        }
      }
      cout<<ma<<endl;
     }

      }
      
    return 0;
      }
