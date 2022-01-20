class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
      unordered_map<int, bool> m;
        set<pair<int, int>> st;
        int ans = 0;
        for(auto i : nums)
        {
            if(m.find(i + k) != m.end() && st.find({i, i + k}) == st.end() && st.find({i + k, i}) == st.end())
                ans += m[i + k], st.insert({i, i + k}), st.insert({i + k, i});
            if(m.find(i - k) != m.end() && st.find({i, i - k}) == st.end() && st.find({i - k, i}) == st.end())
                ans += m[i - k], st.insert({i, i - k}), st.insert({i - k, i});

            m[i] = true;
        }   

        return ans;
    }
};