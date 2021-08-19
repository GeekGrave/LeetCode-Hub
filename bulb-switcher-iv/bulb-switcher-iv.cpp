class Solution {
public:
    int minFlips(string target) {
        char curr = '0';
        int ctr=0;
        for(int i=0;i<target.size();i++){
            if(target[i]!=curr) {
                ctr++;
                curr = curr=='0'?'1':'0';
            }
        }
        return ctr;
        
    }
};