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
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
#endif
}


signed main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
      vector<vector<char>> v(3,vector<char>(3));
      for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            cin >> v[i][j];
        }
      }
      set<char>ans;
      set<pair<char,char>> ans2;
      int x = 0,y = 0;
      for(int i = 0 ; i < 3 ; i++){
        set<char> s;
        for(int j = 0 ; j < 3 ; j++){
            s.insert(v[i][j]);
        }
        if(s.size()==1) {ans.insert(*(s.begin()));}
        if(s.size()==2) {auto it = s.begin();auto it2 = it;it2++;ans2.insert(make_pair(*(it),*(it2)));}
      }
      for(int i = 0 ; i < 3 ; i++){
        set<char> s;
        for(int j = 0 ; j < 3 ; j++){
            s.insert(v[j][i]);
        }
        if(s.size()==1) {ans.insert(*(s.begin()));}
        if(s.size()==2) {auto it = s.begin();auto it2 = it;it2++;ans2.insert(make_pair(*(it),*(it2)));}
      }
      set<char> s1;
      s1.insert(v[0][0]);
      s1.insert(v[1][1]);
      s1.insert(v[2][2]);
       if(s1.size()==1) {ans.insert(*(s1.begin()));}
       if(s1.size()==2) {auto it = s1.begin();auto it2 = it;it2++;ans2.insert(make_pair(*(it),*(it2)));}
      set<char> s2;
      s2.insert(v[0][2]);
      s2.insert(v[1][1]);
      s2.insert(v[2][0]); 
      if(s2.size()==1) {ans.insert(*(s2.begin()));}
      if(s2.size()==2) {auto it = s2.begin();auto it2 = it;it2++;ans2.insert(make_pair(*(it),*(it2)));}
      cout<<ans.size()<<endl<<ans2.size()<<endl;
      }
      
    return 0;
      }
