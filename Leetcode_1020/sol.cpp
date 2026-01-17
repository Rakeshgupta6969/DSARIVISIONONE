class Solution {
public:
   
    int n,m;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};


     void dfs(int row,int col, vector<vector<bool>> &visited,vector<vector<int>>& grid){

         visited[row][col] = true;

         // now checking the all four direction;

         for(int i = 0; i<4; i++){
            int nrow = row + dx[i];
            int ncol  = col + dy[i];

          // now checking the condtion;
          if(nrow >= 0 && nrow <n && ncol >= 0 && ncol <m && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
            dfs(nrow,ncol,visited,grid);
          }

         }

     }



    int numEnclaves(vector<vector<int>>& grid) {
    
    // using the concept of the dfs traversal.
     n = grid.size();
     m = grid[0].size();
      
    vector<vector<bool>> visited(n,vector<bool>(m,false));
      
      // now checking the for the every boundary.

      // for the first row;

      for(int i = 0; i<m; i++){
        if(!visited[0][i] && grid[0][i] == 1){
            dfs(0,i,visited,grid);
        }
      }


      // checking for the last row;

       for(int i = 0; i<m; i++){
        if(!visited[n-1][i] && grid[n-1][i] == 1){
            dfs(n-1,i,visited,grid);
        }
      }

      // checking for the first col;

      for(int i = 0; i<n; i++){
        if(!visited[i][0] && grid[i][0]  == 1){
            dfs(i,0,visited,grid);
        }
      }
      

      // checking for the last col;
       for(int i = 0; i<n; i++){
        if(!visited[i][m-1] && grid[i][m-1]  == 1){
            dfs(i,m-1,visited,grid);
        }
      }

      int ans = 0;

      for(int  i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 1 && !visited[i][j]){
                ans++;
            }
        }
      }
    
       return ans;



    }
};