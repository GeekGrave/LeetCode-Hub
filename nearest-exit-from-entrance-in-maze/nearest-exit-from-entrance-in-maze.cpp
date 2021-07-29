#define f(i,n) for(int i=0;i<n;i++)
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        vector<int> adj[m*n];
        f(i,n){
            f(j,m){
                if(maze[i][j]=='.'){
                    int u = i*m+j;
                    f(k,4){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx>=0 and nx<n and ny>=0 and ny<m) {
                            if(maze[nx][ny]=='.'){
                                int v = nx*m + ny;
                                adj[u].push_back(v);
                            }
                        }
                    }
                }
            }
        }
         
        int dis[n*m];
        f(i,n*m) dis[i] = n*m+1;
        bool vis[n*m];
        memset(vis,false,sizeof(vis));
        int root = entrance[0]*m  + entrance[1];
        queue<int> q;
        dis[root] = 0;
        vis[root] = true;
        q.push(root);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto y:adj[x]){
                if(!(vis[y])){
                    vis[y] = true;
                    q.push(y);
                    dis[y] = dis[x]+1;
                    
                }
            }
        }
        int res = n*m + 1;
        f(i,n){
            f(j,m) {
                if(i==0 or j==0 or i==n-1 or j==m-1) {
                    int in = i*m + j;
                    if(in!=root)
                        res = min(res, dis[in]);
                }
            }
        }
        if(res==n*m+1)
            return -1;
        else
            return res;
        
    }
};