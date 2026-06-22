class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int>mp;
        for(auto it:text)mp[it]++;
        int min_count=min({mp['o']/2,mp['l']/2,mp['a'],mp['b'],mp['n']});
        return min_count;
        

        
        
    }
};