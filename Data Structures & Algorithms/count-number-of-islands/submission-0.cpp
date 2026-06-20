class Solution {
public:
    void dfs(int x,int y, vector<vector<char>>& grid, vector<vector<bool>> &visited){
        int n = grid.size();
        int m = grid[0].size();
        visited[x][y] = true;
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]=='1' && !visited[nx][ny]){
                dfs(nx,ny, grid, visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        for(int i=0;i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(i,j, grid, visited);
                    count++;
                }
            }
        }
        return count;
    }
};
