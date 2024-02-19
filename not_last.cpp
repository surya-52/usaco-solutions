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
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
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
      map<string,int> m;
      m["Bessie"]=0; m["Elsie"]=0; m["Daisy"]=0; m["Gertie"]=0; m["Annabelle"]=0; m["Maggie"]=0; m["Henrietta"]=0;
      for(int i = 0 ; i < n; i++){
        string s;
        int x;
        cin >> s >> x;
        m[s] += x;
      }
      int mi = LLONG_MAX;
      for(auto x:m){
        mi = min(x.second,mi);
      }
      string ans = "";
      int mil = LLONG_MAX;
      for(auto x:m){
        if(x.second!=mi){
            if(x.second < mil){
                ans = x.first;
                mil = x.second;
            }
        }
      }
      int ct = 0;
      for(auto x:m){
        if(mil == x.second) ct++;
      }
      if(mil == LLONG_MAX or ct==2) {
        cout<<"Tie"<<endl;
        continue;
      }
      cout<<ans<<endl;

   }
    return 0;
      }
