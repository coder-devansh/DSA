class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int result=0;
        for(int i=0;i<derived.size();i++){
            result=result ^ derived[i];
        }
        return result==0;

        
        
    }
};