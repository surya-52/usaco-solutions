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
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
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
       vector<int> v(n);
       vector<int> orig(n);
       for(int i = 0 ; i < n; i++){
        cin >> v[i];
        orig[i] = v[i];
       }
       sort(v.begin(),v.end());
       int a = -1;
       for(int i = 0 ; i < n; i++){
         if(v[i]!=orig[i]) {a = i;break;}
       }
       if(a==-1){
        cout<<0<<endl;
        continue;
       }
       int x = -1;
       for(int i = 0 ; i < n ; i++){
        vector<int> temp1,temp2;
        for(int j = 0 ; j < n; j++){
           if(i!=j){
            temp1.push_back(orig[j]);
            temp2.push_back(orig[j]);
           }
        }
        sort(temp1.begin(),temp1.end());
        if(temp1 == temp2){
            x = orig[i];
            a = i;
        }
       }
       // cout<<x<<endl;
       int b = -1;
       for(int i = 0 ; i < n ; i++){
        if(x == v[i]) b = i;
       }
       int c = -1;
       for(int i = 0 ; i < n ; i++){
          if(x==v[i]){
            c = i;
            break;
          }
       }
       // cout<<a<<" "<<b<<" "<<c<<endl;
       set<int> s;
       s.insert(x);
       for(int i = min(a,b); i <= max(a,b) ; i++){
        s.insert(orig[i]);
       }
       set<int> s2;
       s2.insert(x);
       for(int i = min(a,c); i <= max(a,c) ; i++){
        s2.insert(orig[i]);
       }
       cout<<min(s.size(),s2.size())-1<<endl;
       
    }   
    return 0;
      }
