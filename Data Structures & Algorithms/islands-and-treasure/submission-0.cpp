class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>>q;
        for(int r=0 ; r<row;r++){
            for(int c =0 ; c<col;c++){
                if(grid[r][c]==0){
                    q.push({r,c});
                }
            }
        }
        vector<pair<int,int>>dis= {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            for(auto[dx,dy]:dis){
                int nx = x+dx;
                int ny = y+dy;

                if(nx>=0&&nx<row&&ny>=0&&ny<col&&grid[nx][ny]==INT_MAX){
                    grid[nx][ny]=1+grid[x][y];
                    q.push({nx,ny});
                }
            }
        }
    }
};
