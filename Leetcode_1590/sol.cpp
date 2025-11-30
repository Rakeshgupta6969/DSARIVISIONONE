class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

     // using the brute force solution.

    //  int totalsum  = accumulate(nums.begin(),nums.end(),0);
    //  if( totalsum % p == 0) return 0;

    //    if(totalsum < p) return -1;

    //     int reminder = totalsum % p;

         
     
    //     int length = INT_MAX;

    //  int n = nums.size();


    //  for(int i = 0; i<n; i++){

    //      int count = 0;
    //      int sum = 0;

    //      if(nums[i]<=reminder){
    //         count++;
    //         sum += nums[i];
    //      }
      
    //   for(int j = i+1; j<n; j++){

    //       if(sum + nums[j]<=reminder){
    //         count++;
    //          sum += nums[j];
    //       }


    //   }
      

          
    //    if(sum == reminder){
    //      length = min(count,length);
    //    }


    //  }


    //  return length;


    // using the optimal solution.

      int totalsum = 0;
    
      for(auto & num : nums){
        totalsum = (totalsum + num)%p;
      }
    
    if(totalsum %p ==0) return 0;

    unordered_map<int,int>mp;

    int target = totalsum %p;


    int curr = 0;
    int minlength = INT_MAX;
    mp[curr] = -1;

    int n = nums.size();
    for(int i = 0; i<n; i++){
       curr = (curr + nums[i])%p;
    

        int prev = (curr - target + p)%p;
        if(mp.find(prev) != mp.end()){
            int j = mp[prev];
            minlength = min(minlength,(i-j));
        }

      mp[curr] = i;
    }

     return minlength == INT_MAX || minlength == n ? -1 : minlength;

    }
};