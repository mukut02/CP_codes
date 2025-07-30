/*
Single Source Shortest Path Algo for non_negative weights
TC : O ( (V+E)log(V))
SC : O ( |E| +|v| )
take shorted dist from top of Min Heap -> and edge relax it  

IGNORE : If doing for first time -> ignore set method 
Alt: Set can be used and optimse the prev present higher val can be removed 
*/
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq; 
        vector<int> dist(V,INT_MAX);
        
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        dist[src]=0;
        pq.push({0,src});
    
        while(!pq.empty()){
            int node=pq.top().second;
            int val=pq.top().first;
            pq.pop();
           if(dist[node]<val) continue; // IMP optimisation saves from TLE
          // already updated by a better value earlier no need to check it in this iteration
            for(auto it : adj[node]){
                int adjNode=it.first;
                int wt=it.second;
                if(dist[adjNode] > dist[node]+wt){
                   dist[adjNode]= dist[node]+wt;
                   pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
