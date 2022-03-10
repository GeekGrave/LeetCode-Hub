class Solution {
public:
    static bool mycmp(vector<int> v1,vector<int> v2){
        if(v1[0]==v2[0]) return v1[1]<v2[1];
        return v1[0]<v2[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        
        sort(intervals.begin(),intervals.end(),mycmp);
        // for(auto i:intervals){
        //     cout<<i[0]<<" "<<i[1]<<endl;
        // }
        vector<vector<int>> temp;
        for(int i=0;i<intervals.size();){
            int f = intervals[i][0];
            int s = intervals[i][1];
            int flag = 0;
            while(i<intervals.size() and s>=intervals[i][0] ){
                s = max(s,intervals[i][1]);
                flag = 1;
                i++;
            }
            temp.push_back({f,s});
            if(!flag) i++;
        }
        return temp;
    }
};