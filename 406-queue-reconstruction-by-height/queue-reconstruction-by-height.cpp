static bool compare(vector<int>&a,vector<int>&b){
    if(a[0]==b[0]){
        return a[1]<b[1];
    }
    return a[0]>b[0];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),compare);
        vector<vector<int>>result;
        for(int i=0;i<people.size();i++){
            int p=people[i][1];
            result.insert(result.begin()+p,people[i]);
        }
        return result;



        
    }
};