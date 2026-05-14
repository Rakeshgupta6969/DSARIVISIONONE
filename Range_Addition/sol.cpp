#include<iostream>
#include<vector>
using namespace std;


int main(){
     vector<int>nums = {0,0,0,0,0};
     vector<vector<int>>queries = {{0,2,7},{1,4,8},{3,4,-4}};
     // here we have to perform the range update addition of array nums 
     // for a specific queries
     // lets queries[0] = {l,r,x} = {0,2,7}
     // I have to update the add from the index l to r with x

     // with the helps of the normal approach;
    //  int n = queries.size();
    //  for(int i  = 0; i<n; i++){
    //     int l = queries[i][0];
    //     int r = queries[i][1];
    //     int x = queries[i][2];
    //     for(int j = l; j<=r; j++){
    //         nums[j] += x;
    //     }
    //  }
    //  // now print the updated nums declared
    //  for(int i = 0; i<nums.size(); i++){
    //     cout<<nums[i]<<" ";
    //  }


     // now with the help of the difference array techniques
     for(int  i = 0; i<queries.size(); i++){
        int l = queries[i][0];
        int r = queries[i][1];
        int x = queries[i][2];
        nums[l] += x;
        if(r + 1 < nums.size()){
            nums[r+1] -= x;
        }
     }

     // now perform the cumulative sum;
     for(int i = 1; i<nums.size(); i++){
        nums[i] = nums[i] +  nums[i-1];
     }
     // print nums after the updating the nums
     for(int  i = 0; i< nums.size(); i++){
        cout<<nums[i]<<" ";
     } 
    return 0;
}