// Q link : https://codeforces.com/contest/2154/problem/C1
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

      size[V]+=size[V];
      par[V]=U;
   }
};

void ans(bool val){
    if(val) cout << "YES\n";
    else cout << "NO\n";
}
int N=200005;
vector<int> spf(N+1,1);

void compute(){
   for(int i=2;i<=N;++i){
      spf[i]=i;
   }
    for(int i=2;i<=N;++i){
   if(spf[i]==i){
      for(int j=i*i;j<=N;j+=i){
         if(spf[j]==j){
            spf[j]=i;
         }
      }
   }
}
}


void solve(){
   
   int n;cin >> n;
   vector<int> a(n),b(n);
   for(auto &x : a) cin >> x;
   for(auto &x : b) cin >> x;
   
   // ans 2,1,0 ermodhe hobe
   // hoe gele to 0 -> then 1 die dekho then 2
   map<int,int> m0, m1;
   for(auto &val : a){
      int x=val;
      set<int> st;
      while(x!=1){
         st.insert(spf[x]);
         x=x/spf[x];
      }
      x=val+1;
      for(auto &x : st){
         m0[x]++;
      }
      st.clear();
      while(x!=1){
         st.insert(spf[x]);
         
         x=x/spf[x];
      }
      for(auto &x : st){
         m1[x]++;
      }
   }
   
   for(auto &p : m0){
      if(p.first!=1){
         if(p.second>1){
            cout << 0 << nl;
            return;
         }
      }
   }

   for(auto &p : m1){
      if(p.first!=1){
         if(m0[p.first]){
            cout << 1 << nl;
            return;
         }
      }
   }
   cout << 2 << nl;
   return;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    compute();
    int t;cin >> t;
    while(t--){
        solve();
     }
}
