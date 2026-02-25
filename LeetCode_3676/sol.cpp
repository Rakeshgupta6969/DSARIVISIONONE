class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
      // using the brute force solution;

      map<int,vector<int>>mp;

       
       for(int i = 0; i<arr.size(); i++){

        int num = arr[i];
        int count = 0; 

        while(num != 0){

         num = num & ( num - 1);

         count++;

        }

        mp[count].push_back(arr[i]);


       }



       vector<int> ans;

       for(auto p:mp){
         
         vector<int> temp = p.second;
         sort(temp.begin(),temp.end());
        
        for(auto & k:temp){
            ans.push_back(k);
        }

        
       }


       return ans;

         
    }
};