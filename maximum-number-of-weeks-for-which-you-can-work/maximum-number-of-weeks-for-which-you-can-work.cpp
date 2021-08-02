class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        sort(milestones.begin(),milestones.end());
        long long s = 0;
        for(auto p:milestones) s+=p;
        long long last = milestones.back();
        s = s - last;
        last = min(last,s+1);
        s = s + last;
        return s;
    }
};