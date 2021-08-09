class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> adj[100001];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0],v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // int maxx = -1;
        // int number = 0;
        for(int i=0;i<100001;i++){
            if(adj[i].size()==edges.size()){
                return i;
            }
        }
        return 0;
    }
};