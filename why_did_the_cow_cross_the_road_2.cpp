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
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
#endif
}


int32_t main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
      string s;
      cin >> s;
      vector<int> v[26];
      for(int i = 0 ; i < 52 ; i++){
         v[s[i]-'A'].push_back(i);
      }
      set<pair<int,int>> se;
      for(int i = 0 ; i < 26 ; i++){
        int x = v[i][0];
        int y = v[i][1];
         for(int j = 0 ; j < 26 ; j++){
            if(j!=i){
               if((v[j][0] > x) and (y > v[j][0]) and (v[j][1] > y)) {se.insert({min(i,j),max(i,j)});}
            }
         }
      }
     cout<<se.size()<<endl;

    }
    return 0;
      }
