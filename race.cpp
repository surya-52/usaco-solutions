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
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
#endif
}
int power(int A, int B)
{
    if (B == 0)
        return 1;
 
    int res = power(A, B / 2);
 
    if (B % 2)
        return res * res * A;
    else
        return res * res;
}
signed main()
{   
    c_p_c();
    int t = 1;
    // cin >> t;
    while(t--){
     int k,n;
     cin >> k >> n;
     int y = sqrtl(4*k+1);
     int mm = (y-2)/2;
     while((mm*(mm+1))/2<k) mm++;
     for(int i = 0 ; i < n; i++){
        int x;
        cin >> x;
        if((x *(x+1))/2>=k){
          cout<<mm<<endl;
          continue;
        }
        int sum = 0;
        int ans = LLONG_MAX;
        int l = 0;
        while(true){
         l++;
         sum += l;
         int y = k-sum;
         int z = max((int)0,(l*(l-1))/2-(x*(x-1))/2);
         if(y >= z){
          int s = y-z;
          ans = min(ans,l+max((int)0,l-x)+(s/l)+((s%l)>0));
          // cout<<l<<" "<<s<<" "<<l+max((int)0,l-x)+(s/l)+((s%l)>0)<<endl;
         }
         else{
            break;
         }
        }
        cout<<ans<<endl;
     }

   }
    return 0;
}
