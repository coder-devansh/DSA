static bool compare(vector<int>&a,vector<int>&b){
    if(a[0]==b[0]){
        return a[1]<b[1];
    }
    return a[1]<b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),compare);
        int max_value=max(points[0][0],points[0][1]);
        int count=1;
        for(int i=1;i<points.size();i++){
            int a=points[i][0];
            int b=points[i][1];
            if(a<=max_value && max_value<=b){

            }else{
                count++;
                max_value=max(a,b);
            }
        }
        return count;
       

        
    }
};