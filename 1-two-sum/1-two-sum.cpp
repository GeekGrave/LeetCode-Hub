class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        // int m[10000];
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }
        //3-0
        //2-1
        // m[x]
        //4-2
        for(int i=0;i<nums.size();i++){
            int x = target-nums[i];
            if(m.find(x)!=m.end() and m[x]!=i){
                return {i,m[x]};
            }
        }
        return {-1,-1};
    }
};