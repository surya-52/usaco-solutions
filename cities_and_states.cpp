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
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
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
    vector<pair<string,string>> v(n);
    map<string,multiset<string>> m2;
    for(int i = 0 ; i < n; i++){
      cin >> v[i].first >> v[i].second;
       string temp = "";
       temp += v[i].first[0];
       temp += v[i].first[1];
       m2[v[i].second].insert(temp);
    }
    int ans = 0;
    // for(auto x:m2){
    //     cout<<x.first<<endl;
    //     for(auto it:x.second){
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i = 0 ; i < n; i++){
        string temp = "";
        temp += v[i].first[0];
        temp += v[i].first[1];
        // cout<<temp<<" "<<v[i].second<<" ";
            if(temp != v[i].second) ans+=m2[temp].count(v[i].second);
    }
    cout<<ans/2<<endl;


   }
    return 0;
      }
