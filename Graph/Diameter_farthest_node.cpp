//Qlink: https://atcoder.jp/contests/abc428/tasks/abc428_e
#pragma GCC optimize("O3,unroll-loops")
 
 #include<bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

using namespace std;
 
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vpi vector<pair<int,int>> 
 
#define int long long
/*---------------------------------------------------------------------------------------------------------------------------*/
//Maths & NT
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a,ll b){return (a/gcd(a,b))*b;} 
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
 
/*--------------------------------------------------------------------------------------------------------------------------*/

class DSU{
private:
   vector<int> par,size;

public:
   DSU(int n){
      par.resize(n);
      size.resize(n,1);

      for(int i=0;i<n;++i){
         par[i]=i;
      }
   }

   int find(int u){
      if(par[u]==u) return u;
      return par[u] = find(par[u]);
   }

   void merge(int u,int v){
      int U = find(u);
      int V = find(v);

      if(U==V) return;
      if(size[U] < size[V]) swap(U,V);

      size[U]+=size[V];
      par[V]=U;
   }
};

void ans(bool val){
    if(val) cout << "YES\n";
    else cout << "NO\n";
}


void solve(){
   int n;cin >> n;
   vector<vector<int>> adj(n);
   for(int i=0;i<n-1;++i){
      int u,v;cin >> u >> v;
      u--;
      v--;
      adj[u].pb(v);
      adj[v].pb(u);
   }
   auto bfs = [&](int root){
       vector<int> dist(n, -1);
       queue<int> q;
       q.push(root); dist[root]=0;

       while(!q.empty()){
         int node = q.front();
         q.pop();
         for(int nxt : adj[node]){
            if(dist[nxt]==-1){
               // not vis
               q.push(nxt);
               dist[nxt] = dist[node]+1;
            }
               
         }
       }
      return dist;
   };
   auto d0 = bfs(0);
   int u =n-1; // start from last node for max val
   for(int i=n-2;i>=0;--i){
      if(d0[i] > d0[u]){
         // furthest node from 0 
         // one end of diameter take max so 
         //hence start from last node
         u=i;
      }
   }
   // u is furthest node from 0
   auto du= bfs(u);
   int v=n-1;
   for(int i=n-2;i>=0;--i){
      if(du[i] > du[v]){
         // furthest node from v
         // other end of diameter 
         // hence startv from last node n-1  
         v=i;
      }
   }
   auto dv = bfs(v);
   // v is furthest node from u
   // cout << u << ' ' << v << nl;
   for(int i=0;i<n;++i){
      if(du[i]>dv[i]){
         cout << u+1 << nl;
      }
      else if(du[i]<dv[i]){
         cout << v+1 << nl;
      }
      else{
         cout << max(u,v)+1 << nl;
      }
   }
   
}
  
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t=1;
    while(t--){
        solve();
     }
}
