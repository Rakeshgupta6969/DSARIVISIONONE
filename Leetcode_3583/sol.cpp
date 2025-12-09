class Solution {
public:
     const int mod = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {

       // using the brute force solution.
    //    int count = 0;

    //    int n = nums.size();

    //    for(int  i = 0; i<n; i++){
          
    //       for(int j = i+1; j<n; j++){

    //         for(int k = j+1; k<n; k++){

    //            int a = nums[i];
    //            int b = 2*nums[j];
    //            int c = nums[k];
    //            if(a == b && c == b) count++;

    //         }
    //       }


    //    }



    // return count% mod;



     //  using the better solution.

    //  int n = nums.size();

    //  int   count = 0;

    //  for(int i = 1; i<n-1; i++){
         
    //      int req = 2*nums[i];

    //      bool left = false;
    //      int  leftCount = 0;

    //      for(int j  = 0; j<i; j++){
    //         if(nums[j] == req){
    //             leftCount++;
    //             left = true;
               
    //         }
    //      }

    //      bool right = false;
    //      int  rightCount = 0;

    //      for(int k = i+1; k<n; k++){
    //         if(nums[k] == req){
    //             right = true;
    //             rightCount++;
    //         }
    //      }

         
    //      if(left && right){
    //         count += (leftCount  % mod) * rightCount % mod;
    //      }

    //  }


    // return count % mod;


  

  // now using the optimal solution.
  int n = nums.size();
  long long  count   =  0;

  unordered_map<int,long long> leftfreq;
  unordered_map<int,long long > rightfreq;

    // increase all element of the right freq;

    for(int i = 0; i<n; i++){
    
     rightfreq[nums[i]]++;


    }


     // now check the condition.

     for(int j = 0; j<n; j++){

        rightfreq[nums[j]]--;

        int req = 2LL*nums[j];

        long long  leftcount = leftfreq[req];
        long long  rightcount = rightfreq[req];

        count += ((leftcount%mod)* (rightcount%mod)) % mod;
        leftfreq[nums[j]]++;

     }

    
    return count % mod;
       


    }
};