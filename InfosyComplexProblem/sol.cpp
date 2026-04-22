// Online C++ compiler to run C++ program online
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve(int i,int j,int t,vector<vector<int>>&A,vector<vector<int>>&B,int S, vector<vector<vector<int>>>&dp){
      // base case;
     int n = A.size();
     int m = A[0].size();
     if(i >= n || j >= m) return  INT_MIN;
     if(i == n-1 && j == m-1){
         if(t  == 1){
           return   dp[i][j][t] =   A[i][j];
         }
         else{
           return   dp[i][j][t] = B[i][j];
         }
     }
       
       if(dp[i][j][t] != -1) return dp[i][j][t];
      
      
     // now explore the other options
     int maxi = INT_MIN;
     if(t == 1){ // that means we are present in the A matrix;
          int ViaA = max(solve(i,j+1,t,A,B,S,dp),solve(i+1,j,t,A,B,S,dp));
            int op3 = solve(i, j+1,0,A,B,S,dp);
            if(op3 != INT_MIN){
                op3 -= S;
            }

            int op4 = solve(i+1,j,0,A,B,S,dp);
            if(op4 != INT_MIN){
                op4 -= S;
            }
            
            int ViaB = max(op3,op4);
          
          int temp =  max(ViaA,ViaB);
          if(temp == INT_MIN){
              return dp[i][j][t] =  INT_MIN;
          }
          
          maxi = max(maxi,temp + A[i][j]);
         
     }
     else{
          int ViaB = max(solve(i,j+1,t,A,B,S,dp),solve(i+1,j,t,A,B,S,dp));
          int op3 = solve(i,j + 1,1,A,B,S,dp);
          if(op3 != INT_MIN){
              op3 -= S;
          }
          
          int op4 = solve(i+1,j,1,A,B,S,dp);
          if(op4 != INT_MIN){
              op4 -= S;
          }
          
          int ViaA = max(op3,op4);
          
          int temp = max(ViaA,ViaB);
          if(temp == INT_MIN){
              return dp[i][j][t] =  temp;
          }
          
          maxi = max(maxi,(temp + B[i][j]));
     }
    return dp[i][j][t] =  maxi;
}

int main(){
    int n = 3;
    int m = 3;
    vector<vector<int>>A(n,vector<int>(m));
    vector<vector<int>>B(n,vector<int>(m));
    
    
    cout<<"enter the element of the matrix A"<<endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
          cin>>A[i][j];  
        }
     cout<<endl;
    }
    
    cout<<"enter the element of the matrix B"<<endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>B[i][j];
        }
        cout<<endl;
    }
    
    int S;
    cout<<"enter the switching cost"<<endl;
    cin>>S;
    
    // vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(2,-1)));
    
    // int maxPathSum = max(solve(0,0,1,A,B,S,dp),solve(0,0,0,A,B,S,dp));
    
    // cout<<"the maximum PathSum:"<<maxPathSum<<endl;
    
    // using the concept of the tabulation methods.
      vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(2,INT_MIN)));
      // base case.
      dp[n-1][m-1][1] = A[n-1][m-1];
      dp[n-1][m-1][0] = B[n-1][m-1];
      
      // now explore all the polsibilities
      for(int i = n-1; i>=0; i--){
          for(int j = m-1; j>=0; j--){
               if(i == n-1 && j == m-1) continue;
              for(int t = 0; t<2; t++){
                  int maxi = INT_MIN;
                   if(t == 1){ // that means we are present in the A matrix;
             int op1 =  j + 1 < m ? dp[i][j+1][t] :INT_MIN;
             int op2 = i + 1 < n ? dp[i+1][j][t] : INT_MIN;
             
             int ViaA = max(op1,op2);
             
            int op3 =  j+1 < m  ?  dp[i][j+1][0] : INT_MIN;
            if(op3 != INT_MIN){
                op3 -= S;
            }

            int op4 =   i+1 < n ? dp[i+1][j][0] : INT_MIN;
            if(op4 != INT_MIN){
                op4 -= S;
            }
            
            int ViaB = max(op3,op4);
          
          int temp =  max(ViaA,ViaB);
          if(temp != INT_MIN){
           maxi = max(maxi,temp + A[i][j]);
          }
       }
       else{
            int op1 = j + 1 < m ? dp[i][j+1][t] : INT_MIN;
            int op2 = i + 1 < n ? dp[i+1][j][t] : INT_MIN;
            int ViaB = max(op1,op2);
            
          int op3 =   j + 1 < m ? dp[i][j+1][1] : INT_MIN;
          if(op3 != INT_MIN){
              op3 -= S;
          }
          
          int op4 =  i+1 < n ? dp[i+1][j][1] : INT_MIN;
          if(op4 != INT_MIN){
              op4 -= S;
          }
          
          int ViaA = max(op3,op4);
          
          int temp = max(ViaA,ViaB);
          if(temp != INT_MIN){
               maxi = max(maxi,(temp + B[i][j]));  
          }
         
       }
       
         dp[i][j][t] = maxi;
              }
          }
      }
      
    int maxPathSum = max(dp[0][0][0],dp[0][0][1]);
    cout<<" the maximum pathSum: " << maxPathSum <<endl;
   
}
