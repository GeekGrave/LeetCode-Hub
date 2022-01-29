class Solution {
public:
    int findDuplicate(vector<int>& A) {
            map<int,int> m;
    for(int i=0;i<A.size();i++){
        m[A[i]]++;
        if(m[A[i]]>1){
            return A[i];
        }
    }
    return -1;
    }
};