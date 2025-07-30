//Kahn's Algo (BFS method)
// pick zero degree updae its adjacent node then pick next nodes with zero degree
vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        queue<int> q;
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
        }
        
        for(int i=0;i<V;++i){
            for(auto &x : adj[i]){
                indegree[x]++;
            }
        }
        for(int i=0;i<V;++i){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();q.pop();
            topo.push_back(node);
            
            for(int child : adj[node]){
                indegree[child]--;
                
                if(indegree[child]==0) q.push(child);
            }
        }
        
        return topo;
    }
