class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int req = n/3;
        int ctr=1;
        vector<int> ans;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                if(ctr>req) ans.push_back(nums[i-1]);
                ctr=1;
                continue;
            }
            ctr++;
        }
        if(ctr>req) ans.push_back(nums[n-1]);
        return ans;
    }
};