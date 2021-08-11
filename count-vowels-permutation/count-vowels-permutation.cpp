class Solution {
int mod = 1000000007;
int N;
struct Node{
    int v = -1;
};

public:
    int solve(char c,int i,map<pair<char,int>, Node> &dp){
        if(i==N) return 1;
        int ans = 0;
        if(dp[{c,i}].v!=-1) return dp[{c,i}].v;
        if(c=='a'){
            ans = (ans%mod + solve('e',i+1,dp)%mod)%mod;
        }else if(c=='e'){
            ans = (ans%mod + solve('a',i+1,dp)%mod)%mod;
            ans = (ans%mod + solve('i',i+1,dp)%mod)%mod;
        }else if(c=='i'){
            ans = (ans%mod + solve('a',i+1,dp)%mod)%mod;
            ans = (ans%mod + solve('e',i+1,dp)%mod)%mod;
            ans = (ans%mod + solve('o',i+1,dp)%mod)%mod;
            ans = (ans%mod + solve('u',i+1,dp)%mod)%mod;
        }else if(c=='o'){
            ans = (ans%mod + solve('i',i+1,dp)%mod)%mod;
            ans = (ans%mod + solve('u',i+1,dp)%mod)%mod;
        }else ans = (ans%mod + solve('a',i+1,dp)%mod)%mod;
        
        return  dp[{c,i}].v = ans;
    }
    int countVowelPermutation(int n) {
        N=n;
        int ans=0;
        map<pair<char,int>,Node> dp;
        ans = (ans%mod + solve('a',1,dp)%mod)%mod;
        ans = (ans%mod + solve('e',1,dp)%mod)%mod;
        ans = (ans%mod + solve('i',1,dp)%mod)%mod;
        ans = (ans%mod + solve('o',1,dp)%mod)%mod;
        ans = (ans%mod + solve('u',1,dp)%mod)%mod;
        return ans;
    }
};