class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int max_area=0;
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        for(int r=0;r<row;r++){
            for(int c = 0 ; c<col;c++){
                if(grid[r][c]==1&&!visited[r][c]){
                int area = dfs(grid,visited,r,c);
                max_area=max(max_area,area);
                }
            }   
        }
        return max_area;
    }
    int dfs(vector<vector<int>>& grid , vector<vector<bool>>& visited, int r , int c){
        int row = grid.size();
        int col = grid[0].size(); 
        if(r<0||r>=row||c<0||c>=col)return 0;
        if(grid[r][c]==0||visited[r][c])return 0;
        visited[r][c]=true;
        int area = 1;

        area+=dfs(grid,visited,r+1,c);
        area+=dfs(grid,visited,r-1,c);
        area+=dfs(grid,visited,r,c+1);
        area+=dfs(grid,visited,r,c-1);

        return area;
    }
};
