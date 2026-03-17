#include<iostream>
#include<vector>
#include<climits>

using namespace std;

      
  


   int  solve(vector<int>&A,vector<int>&B,int n,int index,int x,int y,int z,int sum,vector<vector<vector<vector<int>>>>& dp){
       
       if( index >= n || x < 0 || y < 0 || z < 0) return 0;
       
        if(dp[index][x][y][z] != -1) return dp[index][x][y][z];
       
        int case1 =  sum - B[index] + solve(A,B,n,index+1,x,y,z,sum,dp);
        int case2 =   sum +  A[index]*(x-1)*(y-1)*z + solve(A,B,n,index+1,x-1,y-1,z,sum,dp);
        
        int case3 = sum + A[index]*x*(y-1)*(z-1) + solve(A,B,n,index+1,x,y-1,z-1,sum,dp);
        
        sum  =   max(case1,max(case2,case3));
        return dp[index][x][y][z] =  sum;
        
      
     
     
 }


int main(){
      
      int N = 2, x = 10, y= 11, z = 11;
      vector<int>A = {1,10};
      vector<int>B = {10,0};
     
    vector<vector<vector<vector<int>>>> dp(
    N+1,
    vector<vector<vector<int>>>(
        x+1,
        vector<vector<int>>(
            y+1,
            vector<int>(z+1, -1)
        )
    )
);
 
 
      int ans =   solve(A,B,N,0,x,y,z,0,dp);
      
      cout<<ans;
      
    
    
    return  0;
}