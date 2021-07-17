#define pb push_back
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& ar, int k) {
        multimap<int, int, greater <int> > m;
        int n = ar.size();
        for(int i=0;i<k;i++){
            m.insert({ar[i],i});
        }
        auto it = m.begin();
        vector<int> ans;
        int maxx = it->first;
        ans.pb(maxx);
        int j = 0;
        for(int i=k;i<n;i++){
            m.insert({ar[i],i});
            auto y = m.find(ar[j]);
            m.erase(y);
            auto z = m.begin();
            maxx = z->first;
            ans.pb(maxx);
            j++;
        }
        return ans;
    }
};