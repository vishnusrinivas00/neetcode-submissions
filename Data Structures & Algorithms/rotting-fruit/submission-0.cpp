class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int,int>>q;
        int fresh = 0 ; 

        for(int r = 0 ; r<row;r++){
            for(int c = 0 ; c<col ;c++){
                if(grid[r][c]==2){
                    q.push({r,c});
                }
                if(grid[r][c]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0)return 0; 
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        int minutes = -1;
        while(!q.empty()){
            int qsize = q.size();
            minutes++;
            while(qsize--){
                auto[x,y]=q.front();
                q.pop();

                for(auto [dx,dy]:dir){
                    int nx = x+dx;
                    int ny = y+dy;

                    if(nx>=0&&nx<row&&ny>=0&&ny<col&&grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        fresh--;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return(fresh==0?minutes:-1);
    }
};
