// gredy sort the edges on the basis of weight
// if two nodes not connected so unite thats our minm cost connection
// DSU approach
vector<int> parent,rank;
  int find(int u){
      if(u==parent[u]){
          return u;
      }
      return parent[u]=find(parent[u]);
  }
  
  void unite(int u,int v){
      int U=find(u);
      int V=find(v);
      
      if(U==V) return;
      
      if(rank[U] > rank[V]){
          parent[V]=U;
      }
      else if(rank[U] < rank[V]){
          parent[U]=V;
      }
      else{
          parent[V]=U;
          rank[U]++;
      }
  }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        rank.resize(V,0);
        parent.resize(V);
        for(int i=0;i<V;++i){
            parent[i]=i;
        }
        int cost=0;
        sort(edges.begin(),edges.end(),[&](vector<int> &a, vector<int> &b){
            return a[2]<b[2];
        });
        
        for(auto &e : edges){
            if(find(e[0])!=find(e[1])){
                unite(e[0],e[1]);
                cost+=e[2];
            }
        }
        
        return cost;
    }
