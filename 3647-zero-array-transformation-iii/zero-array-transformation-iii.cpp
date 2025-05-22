class Solution {
public:
bool canbe(vector<int>&nums,vector<vector<int>>&queries,int k){
    vector<int>diff(nums.size()+1,0);
    for(int i=0;i<k;i++){
        int start=queries[i][0];
        int end=queries[i][1];
        int val=1;
        diff[start]+=val;
        diff[end+1]-=val;

    }
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=diff[i];
        if(sum<nums[i]) return false;
    }
    return true;

}
static bool custom(vector<int>a,vector<int>b){
    return a[1]>b[1];

}
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int cur=0;
        sort(queries.begin(),queries.end());
        priority_queue<int>cand;
        priority_queue<int,vector<int>,greater<int>>end;
        int ind=0;
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            
            while(ind<queries.size() && queries[ind][0]==i){
                cand.push(queries[ind][1]);
                ++ind;
            }
            while(cur<val && !cand.empty() && cand.top()>=i){
                ++cur;
                end.push(cand.top());
                cand.pop();

            }
            if(cur<val) return -1;
            while(!end.empty() && end.top()==i){
                --cur;
                end.pop();

            }
        }
        return cand.size();
    }
};