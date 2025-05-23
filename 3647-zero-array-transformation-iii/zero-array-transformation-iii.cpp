class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(),queries.end());
        int usedCount=0;// to store the count of used queries
        priority_queue<int>end_point;
        priority_queue<int,vector<int>,greater<int>>past_point;// used to store outdated point
        int ind=0;
        for(int i=0;i<nums.size();i++){
            while(ind<queries.size() && queries[ind][0]==i){
                end_point.push(queries[ind][1]);
                ind++;
            }
            nums[i]-=past_point.size();
            while(nums[i]>0 && !end_point.empty() && end_point.top()>=i){
             nums[i]--;
             past_point.push(end_point.top());
             end_point.pop();
             usedCount++;



            }
            if(nums[i]>0){
                return -1;
            }
            while(!past_point.empty() && past_point.top()<=i){
                past_point.pop();

            }

        }
        return queries.size()-usedCount;

        
    }
};