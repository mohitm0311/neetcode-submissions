class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i==0 || j==0 || i==n-1 || j== m-1) && board[i][j]=='O'){
                    vis[i][j]= true;
                    q.push({i,j});
                }
            }
        }
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int i=0;i<4; i++){
                int nx = x+ dx[i];
                int ny = y + dy[i];
                if(nx>=0 && ny<m && nx<n && ny>=0 && !vis[nx][ny] && board[nx][ny]=='O'){
                    q.push({nx,ny});
                    vis[nx][ny] = true;
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]){
                    board[i][j] = 'O';
                }
                else{
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};
