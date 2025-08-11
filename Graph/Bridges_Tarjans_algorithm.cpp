// Q link : https://leetcode.com/problems/critical-connections-in-a-network/
// two vectors -> tin : time in , low -> lowest time to enter the node apart from its parent 
// if( !par with child) -> check compare low time of node with child
// EDGE IS BRIDGE if :-> low time of child > time in of node i.e., no other way to enter child apart from parent
class Solution {
public:
vector<int> low,tin;
vector<bool> vis;
vector<vector<int>> bridges;
int timer;

void dfs(int node,int par,vector<vector<int>> & adj){
    tin[node]=timer;
    low[node]=timer;
    vis[node]=1;
    timer++;

    for(int child : adj[node]){
        if(child==par) continue;
        if(!vis[child]){
            dfs(child, node, adj);
            low[node]=min(low[child], low[node]);
            if(low[child] > tin[node]){
                bridges.push_back({child, node});
            }
        }
        else{
            low[node] = min(low[child], low[node]);
        }

    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        low.resize(n);
        tin.resize(n);
        vis.resize(n,false);
        timer=1;
        for(auto &e : connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0,-1,adj);
        
        return bridges;
    }
};
