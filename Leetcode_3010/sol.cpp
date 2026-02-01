class Solution {
public:
    int minimumCost(vector<int>& nums) {


        // using the brute force solution;
        int TotalSum  = 0;
        for(auto & num : nums){
            TotalSum += num;
        }

        if(nums.size() == 3) return TotalSum;


        int n  = nums.size();
        int sum = nums[0];
        nums[0] = 100;

        sort(nums.begin(),nums.end());


        sum += (nums[0] + nums[1]);


        return sum; 

    }
};