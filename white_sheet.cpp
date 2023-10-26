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
pair<pii,pii> intersect_cordinates(int a1,int b1,int a2,int b2,int c1,int d1,int c2,int d2){
   int l = max(min(a1,a2),min(c1,c2));
   int d = max(min(b1,b2),min(d1,d2));
   int r = min(max(a1,a2),max(c1,c2));
   int u = min(max(b1,b2),max(d1,d2));
   if(l>=r or u<=d){
        return {{0,0},{0,0}};
   }
   return {{l,d},{r,u}};
}
signed main()
{   
    // c_p_c();
    int t = 1;
    cin >> t;
    while(t--){
       int a1,b1,a2,b2;
       cin >> a1 >> b1 >> a2 >> b2;
       int c1,d1,c2,d2;
       cin >> c1 >> d1 >> c2 >> d2;
       int x1,y1,x2,y2;
       cin >> x1 >> y1 >> x2 >> y2;
       int area = ((b2-b1)*(a2-a1));
       // cout<<area<<endl;
       int inters = interse(a1,b1,a2,b2,c1,d1,c2,d2)+interse(a1,b1,a2,b2,x1,y1,x2,y2);
       // cout<<inters<<endl;
       pair<pii,pii> p1 = intersect_cordinates(a1,b1,a2,b2,c1,d1,c2,d2);
       pair<pii,pii> p2 = intersect_cordinates(a1,b1,a2,b2,x1,y1,x2,y2);
       pair<pii,pii> p3 = intersect_cordinates(p1.first.first,p1.first.second,p1.second.first,p1.second.second,p2.first.first,p2.first.second,p2.second.first,p2.second.second);
       int common = (p3.second.first-p3.first.first)*(p3.second.second-p3.first.second);
       // cout<<common<<endl;
       // cout<<p1.first.first<<" "<<p1.first.second<<" "<<p1.second.first<<" "<<p1.second.second<<endl;
       // cout<<p2.first.first<<" "<<p2.first.second<<" "<<p2.second.first<<" "<<p2.second.second<<endl;
       // cout<<p3.first.first<<" "<<p3.first.second<<" "<<p3.second.first<<" "<<p3.second.second<<endl;

       if(area - inters+common >0 ) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
      }
      
    return 0;
      }
