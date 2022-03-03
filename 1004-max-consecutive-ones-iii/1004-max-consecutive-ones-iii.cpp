class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j=0;
        int ans = INT_MIN;
        int i;
        for(i=0;i<nums.size();i++){
            while(k<0){
                if(nums[j]==0) k++;
                j++;
            }
            if(nums[i]==0) k--;
            ans = max(ans,i-j);
        }
        if(k>=0)
            ans = max(ans,i-j);
        return ans;
    }
};