// https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-ii/
// great learnig curve in the Q a must to revise to apply this idea
// Idea : to find distance btw any two nodes in a tree then  if dist is n then ways is: nC1 + nC3 + nC5+....+nCn/n-1 :-> 2^(n-1)
// dist(u, v) = dist(u, root) + dist(v, root) - 2* dist(lca(u,v), root)
class Solution {
public:
// resource to learn Binary lifting -> https://www.youtube.com/watch?v=02zM-QoKoPg
#define LGN 20
#define MOD 1000000007
int lvl[100001];
int dp[100001][LGN+1];

long long expo(long long a,long long b){
    if(b<0) return 0;
    long long res=1;
    while(b){
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        b=b>>1;
    }
    return res;
}

vector<vector<int>> adj;
void dfs(int u,int p){
    lvl[u] =lvl[p]+1;
    dp[u][0]=p; // ancestor of u at distance of 2^0 (1)
    /*
        x
       /  2^(i-1)
      v
     /  2^(i-1)
    u
    */


    for(int i=1;i<LGN;++i){
        dp[u][i] = dp[dp[u][i-1]][i-1];
    }
    
    for(int child : adj[u]){
        if(child!=p){
            dfs(child,u);
        }
    }
}

int lca(int u,int v){
    // assume u deeper than v
    if(lvl[u] < lvl[v]) swap(u,v);
    int diff=lvl[u] -lvl[v];
    for(int i=0;i<LGN;++i){
        if(diff&(1<<i)){
            u=dp[u][i];
        }
    }
    if(u==v) return u;
    /*
    < >
    uplifting part
    Final config
         LCA
        /   \
       u     v
  
    */
    for(int i=LGN-1;i>=0;--i){
        if(dp[u][i]!=dp[v][i]){
            u=dp[u][i];
            v=dp[v][i];
        }
    }
    return dp[u][0];
}
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size() + 2;
        
        adj.resize(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(1,0);
        // for(int i=1;i<n;++i){
        // cout << lvl[i] << '\n';
        // }
        vector<int> ans;
        // cout << expo(2,100) << '\n';
        for(auto &q : queries){
            int u=q[0];
            int v=q[1];
            int d = lvl[u] + lvl[v] - 2*lvl[lca(u,v)];
            ans.push_back(expo(2,d-1));
        }
        return ans;
    }
};
