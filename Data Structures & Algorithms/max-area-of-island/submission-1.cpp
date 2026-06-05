class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int max_area = 0;

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(grid[r][c] == 1 && !visited[r][c]){
                    int area = bfs(grid, visited, r, c);
                    max_area = max(max_area, area);
                }
            }
        }

        return max_area;
    }

    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c){
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int,int>> q;
        q.push({r, c});
        visited[r][c] = true;

        int area = 0;

        vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            area++;

            // check all 4 directions
            for(auto [dx, dy] : dir){
                int nx = x + dx;
                int ny = y + dy;

                if(nx >= 0 && nx < row &&
                   ny >= 0 && ny < col &&
                   grid[nx][ny] == 1 &&
                   !visited[nx][ny]) {

                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return area;
    }
};
