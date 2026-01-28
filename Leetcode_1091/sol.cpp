class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
     
       // using the dijkstra algorithms with queue ,note here not priority_queue;
     if(grid[0][0] != 0) return -1;



       int n  = grid.size();
       int m = grid[0].size();

       vector<vector<int>> dis(n,vector<int>(m,INT_MAX));


       // here we use the queue at the place of the priority queue;


       queue<pair<int,pair<int,int>>> q; // {dis,{i,j}};

       q.push({1,{0,0}});
       dis[0][0] = 1;

       // now performing the bfs traversal;

       while(!q.empty()){

        pair<int,pair<int,int>> pr = q.front();
        q.pop();

        int d = pr.first;
        int x = pr.second.first;
        int y = pr.second.second;

         
         if(x == n-1 && y == m-1) break;

        if(d>dis[x][y]) continue;

        if(dis[x][y] == INT_MAX){
            continue;
        }

        // now the direction = {left,right,up,down,upleft,upright,downleft,downright};

        int dx[8] = {0,0,-1,1,-1,-1,1,1};
        int dy[8] = {-1,1,0,0,-1,1,-1,1};

        for(int i = 0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

           if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0){
               
               int avldis = d + 1;
               
               int currdis = dis[nx][ny];

               if(avldis < currdis){
                dis[nx][ny] = avldis;

                q.push({avldis,{nx,ny}});
               }
           }
             
        }

       }

     
     for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(dis[i][j] == INT_MAX){
                dis[i][j] = -1;
            }
        }
     }

        return dis[n-1][m-1];
    }
};