class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {


      // using the concept of the dijkasta algortihms.

       // making the adjlist;
       vector<vector<pair<int,int>>> adj(n);

       for(int i = 0; i<flights.size(); i++){
        int u  = flights[i][0];
        int v = flights[i][1];
        int w = flights[i][2];

        pair<int,int> p  = make_pair(v,w);
        adj[u].push_back(p);
       }

       vector<int> costs(n, INT_MAX); // to store costs between the flights.
        costs[src] = 0;
        queue<vector<int>>q; // this queue is store stops,Node,and costs.

        vector<int> first = {0,src,0};
        q.push(first);


        while(!q.empty()){
          
          vector<int> front = q.front();
          int frontNode = front[1];
          int stops = front[0];
          int cost = front[2];
          q.pop();
         

          if(stops<k+1){
           
           for(auto & p: adj[frontNode]){
             
             int Node = p.first;
             int c = p.second;

             int AvlCost = c + cost;

             if(costs[Node] > AvlCost){
              
               costs[Node] = AvlCost;
               

               vector<int> temp = {stops+1,Node,costs[Node]};
               q.push(temp);

             }
           }
          }
        }

        if(costs[dst] != INT_MAX) return costs[dst];
        return -1;

    }
};