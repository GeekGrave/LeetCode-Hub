class Solution {
public:
    int candy(vector<int>& ar) {
        int n = ar.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        
        for(int i=1;i<n;i++){
            if(ar[i]>ar[i-1]) left[i] = 1 + left[i-1];
        }
        for(int i=n-2;i>=0;i--){
            if(ar[i]>ar[i+1]) right[i] = 1 + right[i+1];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max(left[i],right[i]);
        }
        return ans;
    }
};