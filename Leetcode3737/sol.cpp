class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
   
    // using the brute force solution.

    int count = 0;

    int n = nums.size();

    for(int i = 0; i<n; i++){
       
      int appear = 0;
      if(nums[i] == target){
        appear++;
        count++;
      } 


      for(int j = i+1; j<n; j++){
       
       if(nums[j] == target){
        appear++;
       }

       if(appear > (j-i+1)/2){
        count++;
       }


      }



    }



  return count;

    }
};