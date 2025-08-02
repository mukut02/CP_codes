/*
Q link : 
https://leetcode.com/problems/count-ways-to-make-array-with-product/description/
CONCEPTS
----------------------------------------------------------
Ball & stick in PnC
x1+x2+...+xn = r -> 
no of non-negative soln -> n+r-1 C r

How to Calculate nCr -> (n!)* (r!)^-1 * (n-r !)^-1 

find all the inverses using Fermat's Liitle theorem -> 
a^p-1 congruent to 1 mod p implies
a^p-2 congruent to a^-1 mod p

to calc a^p-2 % mod p use Binary Exponentiation with MOD
----------------------------------------------------------
*/
class Solution {
public:

typedef long long ll;
const int N=20005;
#define MOD 1000000007

ll expo(ll a, ll b, ll mod) {
    ll res = 1; 
    while(b > 0){
    if(b & 1)res = (res * a) % mod; 
     a = (a*a) % mod; 
     b = b>>1;
    } 
    return res;
}

ll mminvprime(ll a, ll b) {
    return expo(a, b - 2, b);
}

ll nCr(ll n, ll r, ll m, ll *fact, ll *ifact) {
    ll val1 = fact[n]; 
    ll val2 = ifact[n - r]; 
    ll val3 = ifact[r]; 
    return (((val1 * val2) % m) * val3) % m;
}


    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        ll fact[20005];
        ll ifact[20005];
        
        fact[0]=1;
        ifact[0]=1;
    
    for(int i=1;i<N;++i){
    	fact[i]=(fact[i-1]*i)%MOD;
    	ifact[i]=ifact[i-1]*mminvprime(i,MOD);
    	ifact[i]%=MOD;
    }
    vector<int> fans;
     for(auto &v : queries){
        ll n=v[0];
        ll x=v[1];
        ll temp=x;
        map<ll,ll> mpp;
        for(int i=2;i*i<=x;++i){
            while(temp%i==0){
                mpp[i]++;
                temp=temp/i;
            }
        }
        if(temp>1) mpp[temp]++;

        ll ans=1;
        for(auto &p : mpp){
            int r=p.second;
            ans*=nCr(n+r-1,r,MOD,fact,ifact);
            ans%=MOD;
        }
        fans.push_back(ans);
     }
     return fans;
    }
};
