class Solution {
public:
    int dfs(int x,int y, vector<vector<int>>& grid, vector<vector<bool>> &visited){
        int count=1;
        int n = grid.size();
        int m = grid[0].size();
        visited[x][y] = true;
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1 && !visited[nx][ny]){
                count+= dfs(nx,ny, grid, visited);
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int max_count = 0;
        for(int i=0;i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int count = dfs(i,j, grid, visited);
                    max_count = max(max_count, count);
                }
            }
        }
        return max_count;
    }
};
