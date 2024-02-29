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
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);
#endif
}
int dir_mother(map<string,vector<string>> &m,string &s,string &target){
   int ct = 0;
   string temp = s;
   while(!m[temp].empty()){
     vector<string> temp2 = m[temp];
     if(temp2[0] == target) return ct;
     ct++;
     temp = temp2[0];
   }
   return -1;
}
int aunt(map<string,vector<string>> &m,string &s,string &target,map<string,vector<string>> &m2){
   int ct = 0;
   string temp = s;
   while(!m[temp].empty()){
     vector<string> temp2 = m[temp];
     vector<string> temp3 = m2[temp2[0]];
     if(temp3.size() > 1){
     if(temp3[0] == target or temp3[1] == target) return ct;}
     if(temp3.size() > 2){
        if(temp3[2] == target) return ct;
     }
     ct++;
     temp = temp2[0];
   }
   return -1;
}
signed main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
     int n;
     cin >> n;
     string a,b;
     cin >> a >> b;
     map<string,vector<string>> m1;
     map<string,vector<string>> m2;
     map<string,vector<string>> m3;
     for(int i = 0 ; i < n; i++){
        string s1,s2;
        cin >> s1 >> s2;
        m1[s1].pb(s2);
        m1[s2].pb(s1);
        m2[s2].pb(s1);
        m3[s1].pb(s2);
     }
     bool pres = false;
     map<string,int> m;
     queue<string> q;
     q.push(a);
     while(!q.empty()){
        string temp = q.front();
        // cout<<temp<<endl;
        m[temp] = 1;
        if(temp == b) {
            pres = true;
            break;
        }
        q.pop();
        for(auto x:m1[temp]){
          if(!m[x]){
            q.push(x);
          }
        }
     }
     // cout<<pres<<endl;
     if(!pres){
        cout<<"NOT RELATED"<<endl;
        continue;
     }
    if(!m2[a].empty() and m3[m2[a][0]].size() > 1){
      if(b == m3[m2[a][0]][0] or b==m3[m2[a][0]][1]){
         cout<<"SIBLINGS"<<endl;
         continue;
      }
    }
    int x;
    x = dir_mother(m2,a,b);
    if(x!=-1){
        string ans = b;
        ans += " is the ";
        for(int i = 1; i < x; i++){
            ans += "great-";
        }
        if(x > 0) ans +="grand-";
        ans +="mother of ";
        ans += a;
        cout<<ans<<endl;
        continue;
    }
    x = aunt(m2,a,b,m1);
    if(x!=-1){
        string ans = b;
        ans += " is the ";
        for(int i = 1; i < x; i++){
            ans += "great-";
        }
        ans +="aunt of ";
        ans += a;
        cout<<ans<<endl;
        continue;
    }
    x = dir_mother(m2,b,a);
    if(x!=-1){
        string ans = a;
        ans += " is the ";
        for(int i = 1; i < x; i++){
            ans += "great-";
        }
        if(x > 0) ans += "grand-";
        ans +="mother of ";
        ans += b;
        cout<<ans<<endl;
        continue;
    }
    x = aunt(m2,b,a,m1);
    if(x!=-1){
        string ans = a;
        ans += " is the ";
        for(int i = 1; i < x; i++){
            ans += "great-";
        }
        ans +="aunt of ";
        ans += b;
        cout<<ans<<endl;
        continue;
    }
    cout<<"COUSINS"<<endl;
   }
    return 0;
      }
