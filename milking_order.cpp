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
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
#endif
}


int32_t main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
      int n,m,k;
      cin >> n >> m >> k;
      vector<int> v(m);
      bool pres = false;
      for(int i = 0 ; i < m ; i++){
        cin >> v[i];
        if(v[i]==1) pres = true;
      }
      vector<int> order(n+1,0);
      set<int> s;
      map<int,int> ma;
      for(int i = 0 ; i < k ; i++){
        int a,b;
        cin >> a >> b;
        s.insert(a);
        order[b] = a;
        ma[a] = b;
      }
      if(ma[1]!=0){
         cout<<ma[1];
         continue;
      }
      if(pres){
        int j = 1;
        int i = 0;
        while(v[i]!=1){
          if(s.find(v[i])!=s.end()){
            j = ma[v[i]];
            i++;
          }
          else{
            if(order[j]!=0){
                j++;
            }
            else{
                order[j] = v[i];
                ma[v[i]] = j;
                i++;
                j++;
            }
          }
        }
        int l;
        if(i==0) l = 1;
        else{
            l = ma[v[i-1]];
        }
        for(int k = l ; k <= n ; k++){
        if(order[k]==0) {
            cout<<k;
            break;
        }
      }
     }
     else{
      int j = n;
      int i = m-1;
      while(i>=0){
        if(s.find(v[i])!=s.end()){
            j = ma[v[i]];
            i--;
        }
        else{
            if(order[j]!=0){
                j--;
            }
            else{
            order[j] = v[i];
            ma[v[i]] = j;
            i--;
            j--;
          }
        }
      }
     for(int i = 1 ; i <= n ; i++){
        if(order[i]==0) {
            cout<<i;
            break;
        }
       }
      }
    }
    return 0;
      }
