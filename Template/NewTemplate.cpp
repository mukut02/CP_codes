#pragma GCC optimize("O3,unroll-loops")
 
 #include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; 
// find_by_order, order_of_key

 
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
typedef pair<int,int> P;
typedef pair<int, pair<int,int>> PP;

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
void Meta(int t) {cout << "Case #" << t << ": ";}
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

vector<int> SPF(int N){
   vector<int> spf(N+1,1);

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
   
   return spf;
}

class SegTree{
private:
   vector<int> sgt,arr;
    int n;
public:
   // SegTree contructor
   SegTree(vector<int> arr){
        this->arr=arr;
        n=arr.size();
        sgt.resize(4*n);
        build(0,0,n-1);
   }

   void build(int i,int l,int r){
      if(l==r){
         // leaf node reached
         sgt[i]=arr[l];
         return;
      }
      int mid=(l+r)/2;
      build(2*i+1, l ,mid);
      build(2*i+2, mid+1, r);

      sgt[i]=sgt[2*i+1] + sgt[2*i+2];
   }

   void update(int i,int val,int j,int l,int r){
      if(l==r){
         sgt[j]=val;
         arr[i]=val;
         return;
      }
        int mid=(l+r)/2;
      if(i<=mid){
         // i in left
         update(i,val,2*j+1,l,mid);
      }
      else{
         //i in right
         update(i,val,2*j+2,mid+1,r);
      }
      sgt[j] = sgt[2*j+1] + sgt[2*j+2];
   }

   int query(int start,int end,int i,int l,int r){
      if(r<start || l>end){
         return 0; // out of bound
      }
      else if(l>=start && r<=end){
         return sgt[i]; // range contained
      }
      else{
         int mid=(l+r)/2; // contribution in both left and right so find from left and right
         return query(start,end,2*i+1,l,mid) + query(start,end,2*i+2,mid+1,r);
      }
   }
   // TC:
   // build -> O(n), update->O(logn), query-> O(logn)
};



void solve(){
   //EKHANE LEKH
}
  
signed main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
 
   int t;cin >> t;
   while(t--){
      solve();
   }
}
