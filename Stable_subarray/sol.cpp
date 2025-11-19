class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        
      // using the brute force solution.

      vector<long long> ans;

      for(auto q: queries){
        
        int left  = q[0];
        int right = q[1];
    
        long long count = 0;
    

       for(int i = left; i<=right; i++){
           
           for(int j = i; j<=right; j++){

           
           bool ok = true;

           for(int k = i; k<j; k++){
            if(nums[k]>nums[k+1]) ok = false;
           }
     
           if(ok) count++;
           }
       }


       ans.push_back(count);

      }


     return ans;

    }
}; 