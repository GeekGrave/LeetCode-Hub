class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0,j = 0;
        while(i<name.size() and j<typed.size()){
            if(name[i]==typed[j]) i++,j++;
            else if(j>0 and typed[j]==typed[j-1]){
                j++;
            }else return false;
        }
        
        if(i==name.size()) {
            while(j<typed.size()){
                if(typed[j]!=name[i-1]) return false;
                j++;
            }
            return true;
        }
        return false;
    }
};