class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        long long  count=0;
        for(int i=0;i<dominoes.size();i++){
            int a=dominoes[i][0];
            int b=dominoes[i][1];
            for(int j=0;j<i;j++){
                int c=dominoes[j][0];
                int d=dominoes[j][1];
                if((a==c && b==d) || (a==d && b==c)) count+=1;
            }
        }
        return count;
        
    }
};