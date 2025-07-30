vector<vector<int>> adj;
  vector<int> vis;
  stack<int> st;
  
  void dfs(int node){
      vis[node]=1;
      
      for(int child : adj[node]){
          if(!vis[child]){
              dfs(child);
          }
      }
      st.push(node);
  }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        adj.resize(V);
        vis.resize(V);
        
        for(auto &x : edges){
            adj[x[0]].push_back(x[1]);
        }
        
        for(int i=0;i<V;++i){
            if(!vis[i]){
                dfs(i);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
