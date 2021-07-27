class Solution {
public:
    
    int ans;
    
    vector<int> ar;
    void dfs(int u,int par,int time, vector<int> adj[]){
        ans = max(ans,time);
        for(auto x : adj[u]){
            if(x!=par) 
                dfs(x,u,time+ar[u],adj);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        ans = 0;
        ar = informTime;
        vector<int> adj[n+1];
        for(int i=0;i<n;i++){
            if(i!=headID)
                adj[manager[i]].push_back(i);
        }
        dfs(headID,headID,0,adj);
        return ans;
    }
};