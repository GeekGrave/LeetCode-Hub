class Solution {
public:
    bool canPlaceFlowers(vector<int>& ar, int n) {
        deque<int> br(ar.begin(),ar.end());
        br.push_back(0);
        br.push_front(0);
        for(int i=0;i<br.size()-2;i++){
            if(br[i]==0 and br[i+1]==0 and br[i+2]==0 and n>0){
                br[i+1] = 1;
                n--;
            }
        }
        if(n==0) return true;
        return false;
    }
};