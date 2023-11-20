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
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
#endif
}

signed main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n,0);
        for(int i = 0 ; i < n ; i++) {cin >> v[i];}
        int mi = 0;
        int ma = 0;
        bool pres = true;
        for(int i = n - 1 ; i >= 0 and pres ; i--){
            if(v[i] > i){
                pres = false;
                break;
            }
            if(v[i] >= 0){
                mi++;
                ma++;
                int x = 1;
                for(int j = i - 1 ; j >= (i-v[i]); j--){
                   if(v[j]!=-1 and v[j]!=(v[i]-x)){
                    pres = false;
                    break;
                   }
                   x++;
                }
            i -= v[i];
            }
            else{
                if(i == 0) mi++;
                ma++;
            }
        }
        if(pres){
            cout<<mi<<" "<<ma<<endl;
            continue;
        }
        cout<<-1<<endl;
        
    }
    return 0;
      }
