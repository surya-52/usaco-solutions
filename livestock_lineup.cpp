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
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
#endif
}

signed main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
    map<string,int> m;
    m["Bessie"]=0; m["Buttercup"]=0; m["Belinda"]=0; 
    m["Beatrice"]=0; m["Bella"]=0; m["Blue"]=0; m["Betsy"]=0; m["Sue"]=0;
    map<string,vector<string>> m2;
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        vector<string> v(6);
        for(int j = 0 ; j < 6; j++){
            cin >> v[j];
        }
        m2[v[0]].pb(v[5]);
        m2[v[5]].pb(v[0]);
        m[v[0]]++;
        m[v[5]]++;
    }
    map<string,bool> m3;
    m3["Bessie"]=0; m3["Buttercup"]=0; m3["Belinda"]=0; 
    m3["Beatrice"]=0; m3["Bella"]=0; m3["Blue"]=0; m3["Betsy"]=0; m3["Sue"]=0;
    vector<string> ans;
    for(auto x:m){
     if(!m3[x.first] and m2[x.first].size() <=1){
        m3[x.first] = 1;
        ans.pb(x.first);
        if(m2[x.first].size() == 1){
            string temp = m2[x.first][0];
            while(m2[temp].size() == 2){
               m3[temp] = 1;
               ans.pb(temp);
               string s1 = m2[temp][0];
               string s2 = m2[temp][1];
               temp = m3[s1]?s2:s1;
            }
            m3[temp] = 1;
            ans.pb(temp);
        }
     }
    }
    for(auto x:ans) cout<<x<<endl;
    


   }
    return 0;
      }
