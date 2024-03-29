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
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
#endif
}

bool check(vector<bool> &a,vector<bool> &b){
    bool pres = false;
    for(int i = 0 ; i < 3 ; i++){
        if(a[i]!=b[i]) pres = true;
    }
    return pres;
}
vector<bool> check2(int a,int b,int c){
    vector<bool> v(3,0);
    if(a>b and a>c){
        v[0] = 1;
    }
    else if(b>a and b>c){
        v[1] = 1;
    }
    else if(c>a and c>b){
        v[2] = 1;
    }
    else if(a==b and a>c){
        v[0] = 1;
        v[1] = 1;
    }
    else if(a==c and a>b){
        v[0] = 1;
        v[2] = 1;
    }
    else if(b==c and b>a){
        v[1] = 1;
        v[2] = 1;
    }
    else{
        v[0] = 1;
        v[1] = 1;
        v[2] = 1;
    }
    return v;
}
signed main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
      int n;
      cin >> n;
      vector<pair<int,pair<string,int>>> v(n);
      for(int i = 0 ; i < n; i++){
        cin >> v[i].first >> v[i].second.first >> v[i].second.second;
      }
      sort(v.begin(),v.end());
      vector<bool> a;
      vector<int> c(3,7);
      int ans = 1;
      if(v[0].second.first == "Bessie") c[0] += v[0].second.second;
      else if(v[0].second.first == "Elsie") c[1] += v[0].second.second;
      else c[2] += v[0].second.second;
      a = check2(c[0],c[1],c[2]);
      for(int i = 1 ; i < n ; i++){
        if(v[i].second.first == "Bessie") c[0] += v[i].second.second;
        else if(v[i].second.first == "Elsie") c[1] += v[i].second.second;
        else c[2] += v[i].second.second;
        vector<bool> temp = check2(c[0],c[1],c[2]);
        ans += check(a,temp);
        a = temp;
      }
      cout<<ans<<endl;
      }
      
    return 0;
      }
