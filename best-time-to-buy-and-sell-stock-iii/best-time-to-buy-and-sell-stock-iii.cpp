class Solution {
public:
    vector<int> ar;
    int n;
    int dp[100001][3][3];
    int fun(int i,int curr,int x){
        if(i==n) return 0;
        
        if(x==0) return 0;
        
        if(dp[i][curr][x]!=-1) return dp[i][curr][x];
        int ans = 0;
    
        if(curr==0){
            ans = max({ans,fun(i+1,1,x)-ar[i],fun(i+1,0,x)});
        }else{
            ans = max({ans,fun(i+1,0,x-1)+ar[i],fun(i+1,1,x)});
        }
        return dp[i][curr][x] = ans;
    }
    int maxProfit(vector<int>& prices) {
        ar = prices;
        memset(dp,-1,sizeof(dp));
        n = ar.size();
        return fun(0,0,2);
    }
};