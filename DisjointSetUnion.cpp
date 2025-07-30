//Snippet for DSU
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent;
public:    
    // constructor
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        
        // self parent intitial config
        for(int i=0;i<=n;++i){
            parent[i]=i;
        }
    }
    
    int findUpar(int u){
        
        if(u==parent[u]){
            return u;
        }
        return parent[u]=findUpar(parent[u]);
        // this memoization type step is path compresion
    }
    
    void unionByRank(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        
        //already same ultimate parent nothing needed
        if(ulp_v == ulp_u){
            return;
        }
        // higher rank is ult parent
        // if same assign anyone the other paren and inc its rank
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    // TC O(4alpha) =O(1)for both findUpar and unionByRank
  
};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    
    cout << ds.findUpar(3) << ' ' << ds.findUpar(7) << '\n';
    
    ds.unionByRank(3,7);
    
    cout << ds.findUpar(3) << ' ' << ds.findUpar(7) << '\n';
}
// https://leetcode.com/discuss/post/1072418/disjoint-set-union-dsuunion-find-a-compl-2oqn/
