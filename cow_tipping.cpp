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
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
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
            v[i][j] = s[j]-'0';
           }
        }

       int count = 0;
       int x = n - 1;
       while(x>=0){
        int pr = -1;
            for(int i = 0 ; i <= x ; i++){
                if(v[x][i] == 1){
                   pr = i;
                }
            }
            // cout<<pr<<" "<<x<<endl;
            if(pr != -1){
                count++;
                for(int i = 0 ; i <= x ; i++){
                    for(int j = 0 ; j <= pr ; j++){
                        v[i][j] = !(v[i][j]);
                    }
                }
                continue;
            }
            int pz = -1;
            for(int i = 0 ; i <= x; i++){
              if(v[i][x] == 1){
                pz = i;
              }
            }
            // cout<<pz<<" "<<x<<" "<<"z"<<endl;
            if(pz != -1){
                count++;
                for(int i = 0 ; i <= pz ; i++){
                    for(int j = 0 ; j <= x ; j++){
                        v[i][j] = !(v[i][j]);
                    }
                }
                continue;
            }
            if(pr == -1 and pz == -1){
                x--;
            }
       }
       cout<<count<<endl;
    }   
    return 0;
      }
