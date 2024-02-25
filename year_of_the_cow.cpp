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
    // c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
     map<string,int> m;
     m["Ox"]=1;
     m["Tiger"]=2;
     m["Rabbit"]=3;
     m["Dragon"]=4;
     m["Snake"]=5;
     m["Horse"]=6;
     m["Goat"]=7;
     m["Monkey"]=8;
     m["Rooster"]=9;
     m["Dog"]=10;
     m["Pig"]=11;
     m["Rat"]=12;
     int n;
     cin >> n;
     map<string,int> m2;
     m2["Bessie"] = 0;
     map<string,string> m3;
     m3["Bessie"] = "Ox";
     for(int i = 0 ; i < n; i++){
        vector<string> v(8);
        for(int j = 0 ; j < 8; j++){
            cin >> v[j];
        }
        int x = m[v[4]];
        int y = m[m3[v[7]]];
        if(v[3] == "previous"){
            if(x >= y){
              m2[v[0]] = m2[v[7]]-(12-x+y);
            }
            else{
              m2[v[0]] = m2[v[7]]-(y-x);
            }
        }
        else{
            if(x > y){
               m2[v[0]] = m2[v[7]] + (x-y);
            }
            else{
               m2[v[0]] = m2[v[7]] + (12-y+x);
            }
        }
        m3[v[0]] = v[4];
     }
     // for(auto x:m2){
     //    cout<<x.first<<" "<<x.second<<endl;
     // }
     cout<<abs(m2["Elsie"])<<endl;


   }
    return 0;
      }
