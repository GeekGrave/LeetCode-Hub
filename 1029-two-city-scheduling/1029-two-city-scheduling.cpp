class Solution {
public:
    
    int dp[101][101][1001];
    vector<vector<int>> cost;
    int n;
    int fun(int a,int b,int i){
        // cout<<a<<" "<<b<<" "<<i<<endl;;
        if(i>=(n*2)) return 0;
        if(a==n and b==n) return 0;
        if(dp[a][b][i]!=-1) return dp[a][b][i];
        if(a<n and b<n){
            return dp[a][b][i] = min(cost[i][0] + fun(a+1,b,i+1),cost[i][1] + fun(a,b+1,i+1));
        }else if(a<n){
            return dp[a][b][i] = cost[i][0] + fun(a+1,b,i+1);
        }else{
            return dp[a][b][i] = cost[i][1] + fun(a,b+1,i+1);
        }
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        n = costs.size()/2;
        cost = costs;
        memset(dp,-1,sizeof(dp));
        return fun(0,0,0);
    }
};