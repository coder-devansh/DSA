class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        vector<int>temp;
        int n=colors.size();

        temp=colors;
        for(int i=0;i<colors.size();i++){
            temp.push_back(colors[i]);
        }
        colors=temp;
        int count=0;
        for(int i=0;i<n;i++){
        if(colors[i]!=colors[i+1] && colors[i+1]!=colors[i+2])count++;
            }
        return count;
        
    }
};