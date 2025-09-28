class Solution {
public:
int longestOnes(string nums, int k,char ch) {
        int right=0;
        int left=0;
        map<char,int>mp;
        int maxi=INT_MIN;
        while(right<nums.size()){
            mp[nums[right]]++;
            while(mp[ch]>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0)mp.erase(nums[left]);
                left++;
            }
            maxi=max(maxi,right-left+1);
            right++;
        }
        return maxi;

        
    }   
    int maxConsecutiveAnswers(string answerKey, int k) {
        int val1=longestOnes(answerKey,k,'T');
        int val2=longestOnes(answerKey,k,'F');
        return max(val1,val2);
        
    }
};