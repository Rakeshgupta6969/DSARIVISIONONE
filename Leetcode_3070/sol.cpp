class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
     
      // using the brute force solution.

    //   int ans = 0;
    //   int n = grid.size();
    //   int m = grid[0].size();
     

    //    for(int i  = 0; i<n; i++){
    //    for(int j = 0; j<m; j++){
       
    //    int sum = 0;
        
    //     for(int k1 = i; k1>=0; k1--){
    //         for(int k2 = j; k2>=0; k2--){
    //             sum += grid[k1][k2];
    //         }
    //     }

    //      if(sum <= k) ans++;
    //    }
    //    }

       



    //  return ans;




       // using the optimal solution ,thoda hi sochna tha bhai ,miss kr gya.



//        int ans = 0;

//        int n = grid.size();
//        int m = grid[0].size();

//        vector<vector<int>>store(n,vector<int>(m,0));

      
//       store[0][0];


//       for(int i = 0; i<n; i++){
//       for(int j = 0; j<m; j++){

//       // summatrix sum (0,0) to the (i,j);

//        int sum  = grid[i][j];

//        // upper submatrices sum

//        if(i-1>=0){
//         sum += store[i-1][j];
//        }

//        // left sub matrix sum

//        if(j-1 >= 0){
//         sum += store[i][j-1];
//        }


//        // now substract the repeated submatrix sum.

//        if(i-1 >= 0 && j-1 >= 0){
//         sum -= store[i-1][j-1];
//        }

//       store[i][j] = sum;

//       }
//   }


//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<m; j++){
//             if(store[i][j]  <= k) ans++;
//         }
//     }


//        return ans;



  

  // optimise the space updating the same given matrix grid.

  int ans = 0;
  int n = grid.size();
  int m = grid[0].size();


    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){

        
          int sum = grid[i][j];

          if(i-1 >= 0){
            sum += grid[i-1][j];
          }
      
         if(j-1 >= 0 ){
            sum += grid[i][j-1];
         }

          
          if(i-1 >= 0 && j-1 >=  0){
            sum -= grid[i-1][j-1];
          }

          grid[i][j] = sum;

          if(grid[i][j] <= k) ans++;


        }
    }


        return ans;
    }
};