class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int right=0;
        int left=0;
        int maxi=0;
        map<int,int>mp;
        while(right<fruits.size()){
            mp[fruits[right]]++;
            while(mp.size()>2){
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            maxi=max(maxi,right-left+1);
            right++;
        }
        return maxi;
        
    }
};