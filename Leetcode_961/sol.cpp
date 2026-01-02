class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
     // using the brute force solution.

     int  n  = nums.size();

     unordered_map<int,int> mp;

     for(auto & num : nums){
        mp[num]++;
     }

     for(auto & p: mp){
        if(p.second == n/2) return p.first;
     }


        return -1;

    }
};