class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = min(word1.length(),word2.length());
        string ans;
        for(int i=0;i<n;i++){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        string t;
        t = word1.length()>word2.length()?word1:word2;
        ans+=t.substr(n,t.size()-n);
        return ans;
    }
};