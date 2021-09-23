class Solution {
public:
    vector<int> ar;
    int t;
    void solve(int i,vector<int> v,vector<vector<int>> &ans,int sum){
        if(i==ar.size() or sum>t) return;
        if(sum==t){
            ans.push_back(v);
            return;
        }
        v.push_back(ar[i]);
        solve(i,v,ans,sum+ar[i]);
        v.pop_back();
        solve(i+1,v,ans,sum);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ar = candidates;
        t = target;
        vector<vector<int> > ans;
        solve(0,{},ans,0);
        return ans;
    }
};