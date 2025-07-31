 #include<bits/stdc++.h>
using namespce std;
#define int long long

typedef vector<vector<int>> mat;
 
mat mult(mat &A,mat &B){
	mat C(2,vector<int>(2));
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
           for(int k=0;k<2;++k){
           	 C[i][j]=(C[i][j]+ mod_mul(A[i][k],B[k][j],MOD))%MOD;
           }
		}
	}
	return C;
}
 
 
mat binexp(mat a,int b){
	mat result={{1,0},{0,1}};
    
	while(b){
		if(b&1) result=mult(result,a);
		a=mult(a,a);
		b=b>>1;
	}
	return result;
}
 
void solve(){
	int n;cin>> n;
	if(n==0){
		cout << 0;return;
	}
	mat M={{1,1},{1,0}}; // base matrix 
	
	mat mat_pow=binexp(M,n-1);
    
    int ans=mat_pow[0][0];
    cout << ans<< "\n";
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
