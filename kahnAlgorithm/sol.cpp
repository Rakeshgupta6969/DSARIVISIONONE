class Solution {
  public:
  
    //  unordered_map<int,vector<int>> adjlist;
    //  unordered_map<int,bool>visited;
    //  stack<int> st;
     
     
    //  void dfs(int node){
    //      visited[node] = true;
         
         
         
    //      for(auto & ngbr: adjlist[node]){
              
    //           if(!visited[ngbr]){
    //               dfs(ngbr);
    //           }
    //      }
         
    //      st.push(node);
    //  }
     
     
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
       
    //     // using the optimal solution.
        
    //     for(int i = 0; i<edges.size(); i++){
            
    //          int u = edges[i][0];
    //          int v = edges[i][1];
             
    //          adjlist[u].push_back(v);
    //     }
        
        
        
    //     for(int i = 0; i<V; i++){
             
    //          if(!visited[i]){
    //              dfs(i);
    //          }
            
            
    //     }
        
        
    //     vector<int> ans;
        
    //     while(!st.empty()){
    //         ans.push_back(st.top());
    //             st.pop();
            
    //     }
       
    //   return ans;
    
    
    
    // TOPOLOGICAL SORT USING THE KHAN'H ALGORITHMS OR BFS.
    
    
    
    // making the adj list;
    
    unordered_map<int,vector<int>> adj;
    
    vector<int>indegree(V); // store indgree of the nodes.
    
      for(int i = 0; i<edges.size(); i++){
          
          int u = edges[i][0];
          int v = edges[i][1];
          
          adj[u].push_back(v);
          
          indegree[v]++;
          
         
      }
      
      
       
       queue<int> q;
       
       for(int i = 0; i<V; i++){
           if(indegree[i] == 0){
               q.push(i);
           }
       }
       
       // apply the BFS traversal as usual.
       
       vector<int> ans;
       
       while(!q.empty()){
             
             int frontNode = q.front();
             q.pop();
             ans.push_back(frontNode);
             
             
             
             for(auto node:adj[frontNode]){
                 
                   indegree[node]--;
                   if(indegree[node] == 0){
                       q.push(node);
                   }
                 
                 
             }
             
             
       }
      
      
       return ans;
       
        
    }
};