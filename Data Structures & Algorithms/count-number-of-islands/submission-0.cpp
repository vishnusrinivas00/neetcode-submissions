class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        int count=0;
        for(int r = 0 ; r<row ; r++){
            for(int c = 0 ;c <col;c++){
                if(grid[r][c]=='1'&&!visited[r][c]){
                    count++;
                    dfs(grid,visited,r,c);
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int r, int c){
        int row = grid.size();
        int col = grid[0].size();

        if(r<0||r>=row||c<0||c>=col)return;
        if(grid[r][c]=='0'||visited[r][c])return;
        visited[r][c]=true;

        dfs(grid,visited,r+1,c);
        dfs(grid,visited,r-1,c);
        dfs(grid,visited,r,c+1);
        dfs(grid,visited,r,c-1);
    }
};
