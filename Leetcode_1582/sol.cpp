class Solution {
   
   bool solve1(vector<vector<int>>&mat,int row,int col){
        
             
        for(int i = 0; i<mat[0].size(); i++){
            if(i == col) continue;

            if(mat[row][i] == 1)return false;

            
        }

       return true;

   }


    bool solve2(vector<vector<int>>&mat,int row,int col){
        
             
        for(int i = 0; i<mat.size(); i++){
            if(i == row) continue;

            if(mat[i][col] == 1)return false;

            
        }

       return true;

   }


   



public:
    int numSpecial(vector<vector<int>>& mat) {
        
        // using the brute force solution.

        int count = 0;
        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0; i<n; i++){
         
         for(int j = 0; j<m; j++){
           
           if(mat[i][j] == 1){
           
            bool rowCheck = solve1(mat,i,j); // row check 
            bool colCheck = solve2(mat,i,j); // col check;

            if(rowCheck  == true && colCheck == true) count++;



           }


         }


        }

       
       return count;

    }
};