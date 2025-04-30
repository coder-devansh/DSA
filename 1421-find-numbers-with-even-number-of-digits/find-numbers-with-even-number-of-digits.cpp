class Solution {
public:
int find(int num){
    int count=0;
    while(num){
        num=num/10;
        count++;
    }
    return count;
}
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(auto it:nums){
            int count=find(it);
            if(count%2==0) ans++;
        }
        return ans;
        
    }
};