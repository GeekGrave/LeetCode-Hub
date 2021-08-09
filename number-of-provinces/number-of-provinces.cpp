class Solution {
public:
    int findCircleNum(vector<vector<int>>& graph) {
        int n = graph.size();   
        int vis[301] = {0};
        int ctr=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ctr++;
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                while(!q.empty()){
                    int x = q.front();
                    q.pop();
                    for(int j=0;j<n;j++){
                        if(graph[x][j]==1){
                            if(!vis[j]){
                                q.push(j);
                                vis[j] = 1;
                            }
                        }
                    }
                }
            }
        }
        return ctr;
    }
};