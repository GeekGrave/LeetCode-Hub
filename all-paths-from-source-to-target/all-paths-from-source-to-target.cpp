class Solution {
public:
    vector<vector<int> > ans;
    vector<int> temp;
    int target;
    void dfs(int i,vector<vector<int> > &adj){
        temp.push_back(i);
        if(i==target){
            ans.push_back(temp);
        }else{
            for(auto x:adj[i]){
                dfs(x,adj);
            }
        }
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        ans.clear();
        temp.clear();
        target = graph.size()-1;
        dfs(0,graph);
        return ans;
    }
};