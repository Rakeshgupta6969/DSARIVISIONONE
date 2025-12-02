class Solution {
public:
   
    const int MOD =  1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
     // using the brute force solution.

     unordered_map<int,int> mp;  // count total number of x-axis points towards a y-axis point.


     for(int i = 0; i<points.size(); i++){
        int y = points[i][1];
        mp[y]++;
     }

     long long  sum = 0;

     long long PrevLines = 0;

     for(auto & p:mp){
        long long CountPoints = p.second;

        long long totalLines = CountPoints*(CountPoints-1)/2;

        sum  += (PrevLines*totalLines)%MOD;

          PrevLines += totalLines;

     }

     return sum % MOD;



    }
};