class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        if(n==1) return s;
        int dp[n][n];
        memset(dp,-1,sizeof(dp));
        // for(int i=0;i<=n-5;i++){
        //     if(s.substr(i,5)=="sknks") cout<<i<<endl;
        // }
        
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
            if(i!=n-1){
                if(s[i]==s[i+1]) dp[i][i+1] = 1;
                else dp[i][i+1] = 0;
            }
        }
        for(int a=0;a<n;a++){
            for(int b=0;b<n-a;b++){
                int i=b,j=b+a;               
                if(dp[i][j]==-1){
                    if(s[i]==s[j] and dp[i+1][j-1]==1){
                        dp[i][j] = 1;
                    }else dp[i][j] = 0;
                }
            }
        }
        int pos1 = -1,pos2 = -1;
        int maxx = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // cout<<dp[i][j]<<" ";
                if(dp[i][j]==1){
                    if(j-i>maxx){
                        maxx = j-i;
                        pos1 = i,pos2 = j;
                    }
                }
            }
            // cout<<endl;
        }
        // cout<<dp[405][409]<<endl;
        return s.substr(pos1,pos2-pos1+1);
    }
};