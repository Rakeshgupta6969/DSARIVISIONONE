class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

     // using the brute force solution.

     // using the concept dijkastra's algorithms;

     // making the adjlist;

       vector<vector<pair<int,int>>>adj(n+1);
       

       for(int  i = 0; i<times.size(); i++){
           
             int u = times[i][0];
             int v = times[i][1];
             int w = times[i][2];

             adj[u].push_back({v,w});

       }
       

       // time vector to store the minTime;

       vector<int>time(n+1,INT_MAX);
       time[k] = 0;
       time[0] = 0;

       // making the mean heap to peform the dijkastra's algorithm
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
      q.push({0,k});


      // now start 
      while(!q.empty()){
        int tm = q.top().first;
        int Node = q.top().second;
        q.pop();

        if(tm>time[Node])continue;

        if(time[Node] == INT_MAX) continue;

         // now exploring the neighour Node;

         for(auto & p:adj[Node]){
            int frontNode = p.first;
            int t = p.second;

            int currT = time[frontNode];
            int avlT  = t + tm;

            if(avlT <currT){
                time[frontNode] = avlT;

                q.push({avlT,frontNode});
            }
         } 

      }
      
      int ans = INT_MIN;
      for(int i = 0; i<=n; i++){
         
         if(time[i] == INT_MAX) return -1;

         ans = max(ans,time[i]);
      }


      return ans;
    }
};