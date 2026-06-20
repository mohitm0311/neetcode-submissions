class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int count_fresh = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    count_fresh++;
                }
            }
        }
        if(count_fresh==0) return 0;
        int time = -1;
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto [x,y] = q.front();
                q.pop();
                for(int i=0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        count_fresh--;
                        q.push({nx,ny});
                    }
                }
            }
            time++;
        }
        if(count_fresh==0) return time;
        return -1;
    }
};
