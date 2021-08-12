class Solution {
public:
    vector<int> ar;
    int t;
    struct Node{
        int v = -1;
    };
    
    int count(int i,int s,map<pair<int,int>,Node> &dp){
        if(i==ar.size()){
            if(s==t) return 1;
            else return 0;
        }        
        if(dp[{i,s}].v!=-1) return dp[{i,s}].v;
        
        int ans = count(i+1,s+ar[i],dp) + count(i+1,s-ar[i],dp);
        return dp[{i,s}].v = ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        ar = nums;
        t = target;
        map<pair<int,int>,Node> dp;
        return count(0,0,dp);
    }
};