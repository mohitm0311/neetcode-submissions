class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        vector<int> dx = {1,-1,0,0};
        vector<int> dy ={0,0,1,-1};
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            int distance = grid[x][y];
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!=-1){
                    int new_dist = 1 + distance;
                    if(new_dist< grid[nx][ny]){
                        grid[nx][ny] = new_dist;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
};
