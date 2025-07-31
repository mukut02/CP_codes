 #include<iostream>
using namespace std;
#define int long long
#define MOD 1000000007
 
void BinExp(){
	int a,b;cin >> a >> b;
	int result=1;
	while(b){
        if(b&1){
        	result*=a;
        	result%=MOD;
        }
        a*=a;a%=MOD;
        b=b>>1;
	}
    cout << result << endl;
}
// Recusrive Implementation 
long long binExp(int a, int b){
	if(b==0) return 1;
	if(b&1){
		return a*binExp(a,b/2)*binExp(a,b/2);
	}
	else{
		return binExp(a,b/2)*binExp(a,b/2);
	}
}
 
signed main(){
	int t;cin >> t;
	while(t--){
		BinExp();
	}
    
}
