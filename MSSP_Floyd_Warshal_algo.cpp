#include<bits/stdc++.h>
using namespace std;
#define int long long
// Floyd Warshal Algorithm
// TC-> O(|v|^3)
signed main(){
	int n,m,q;cin >> n >> m >> q;

    vector<vector<int>> dist(n+1,vector<int>(n+1,1e18));
    
    for(int i=0;i<m;++i){
        int a,b,c;cin >> a >> b >> c;
        dist[a][b]=min(c, dist[a][b]);
        dist[b][a]=min(c, dist[b][a]); 
        // bidirection , undirected graph and min for multiple same edge possible in input
    }
    for(int i=1;i<=n;++i){
    	dist[i][i]=0;
    }
    for(int k=1;k<=n;++k){
    	for(int i=1;i<=n;++i){
    		for(int j=1;j<=n;++j){
    			// edge relax
    			dist[i][j]=min(dist[i][j], dist[i][k] + dist[k][j]);
    		}
    	}
    }
    
    for(int i=1;i<=n;++i){
    	for(int j=1;j<=n;++j){
    		if(dist[i][j]==1e18) dist[i][j]=-1;
    	}
    }   
    while(q--){
    	int a,b;cin >> a >> b;
    	cout << dist[a][b] << '\n';
    }
}
