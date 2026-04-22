#include<bits/stdc++.h>
using namespace std;

 long solve(int row,int col,int M,int costA,int costB,vector<vector<int>>&V,vector<vector<int>>&dp){
     
    // base case.
    if(col >= M) return 0;
    if(dp[row][col] != -1) return dp[row][col];

    // now explore other two option
    long  op1 = (costA - V[row][col]) + solve(row,col+1,M,costA,costB,V,dp);
    long  op2 = INT_MAX;
    if(col+2 < M){
        op2 = costB + solve(row,col + 2,M.costA,costB,V,dp);
    }

    return dp[row][col] = min(op1,op2);

cd


 }

long MinCost(int N,int M,int costA,int costB,vector<vector<int>>&V){
       
    //  here we only focused on the cell of the each row
    // vector<vector<long>>dp(n,vector<long>(M,-1));
    // long  ans =  0;
    // for(int i  = 0; i<N; i++){
      
    //   ans += solve(i,0,M,costA,costB,V,dp);  


    // }
    // return ans;
     


     // using the concept of tabulation.
    vector<vector<long>>dp(n,vector<long>(M,0));
    // base case.
     int temp = 0;
    for(int j = 0; j<M; j++){
        long  op1  = costA - V[N-1][j];
         long  op2 = INT_MAX;
        if(temp < M){
            op2 = costB;
            temp += 2;
        }
        dp[N-1][j] = min(op1,op2); 
    }


            for(int  row = N-2; row >= 0; row--){
                for(int col = 0; col <M; col++){
                    // now explore other two option
            long  op1 = (costA - v[row][col]) + dp[row][col+1];
            long  op2 = INT_MAX;
            if(col+2 < M){
                op2 = costB + dp[row][col + 2];
            }

             dp[row][col] =   min(op1,op2); 



        }
     }

     return dp[0][0];

}