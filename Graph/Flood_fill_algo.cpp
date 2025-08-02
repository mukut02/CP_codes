/*
Q link : https://leetcode.com/problems/number-of-enclaves/
Do 4 sided DFS on 1s in the 4 boundaries
After all visit the remaining s not visited count them
*/

class Solution {
public:
int n,m;
vector<int> dx,dy;
void dfs(int i,int j,vector<vector<bool>> &vis,vector<vector<int>>& grid){
    vis[i][j]=1;

    for(int k=0;k<4;++k){
        int nx=i + dx[k];
        int ny=j + dy[k];
        if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==1){
            dfs(nx,ny,vis,grid);
        }
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        dx={-1,0,1,0};
        dy={0,1,0,-1};
        vector<vector<bool>> vis(n,vector<bool>(m,0));

        for(int i=0;i<n;++i){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,vis,grid);
            }

            if(!vis[i][m-1] && grid[i][m-1]==1){
                dfs(i,m-1,vis,grid);
            }
        }

        for(int j=0;j<m;++j){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,vis,grid);
            }

            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,vis,grid);
            }
        }
        int ans=0;
        for(int i=1;i<n-1;++i){
            for(int j=1;j<m-1;++j){
                if(!vis[i][j] && grid[i][j]==1){
                    ans++;
                }
            }
        }

        return ans;
    }
};
