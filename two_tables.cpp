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
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
#endif
}
int interse(int a1,int b1,int a2,int b2,int c1,int d1,int c2,int d2){
   return (max(min(b2,d2)-max(b1,d1),(int)0))*(max(min(a2,c2)-max(a1,c1),(int)0));
}
signed main()
{   
    c_p_c();
    int t = 1;
    cin >> t;
    while(t--){
       int w1,h1;
       cin >> w1 >> h1;
       int a,b,c,d;
       cin >> a >> b >> c >> d;
       int w2,h2;
       cin >> w2 >> h2;
       // cout<<w2+(c-a)<<endl;
       // cout<<h2+(d-b)<<endl;
       if(((w2+(c-a))>w1) and((h2+(d-b))>h1)){
          cout<<-1<<endl;
          continue;
       }
       if(interse(0,0,w2,h2,a,b,c,d)==0){
        cout<<setprecision(6)<<0<<endl;
        continue;
       }
       int x = INT_MAX;
       if((w2+(c-a))<=w1){
        x = w2-a;
        x = min(x,max((int)0,w2-(w1-c)));
       }
       int y = INT_MAX;
       if((h2+(d-b))<=h1){
         y = h2-b;
         y = min(y,max((int)0,h2-(h1-d)));
       }
       cout<<setprecision(6)<<min(x,y)<<endl;
      }
      
    return 0;
      }
