class Solution {
public:
vector<int>dp;
// void find(int i,vector<string>&words,vector<int>&groups){
//     for(int j=0;j<i;j++){
//         if(groups[i]!=groups[j] && words[i].size()==words[j].size() && dist(words[i],words[j])==1){

//         }
//     }
// }
int dist(string word1,string word2){
    int count=0;
    for(int i=0;i<word1.size();i++){
        if(word1[i]!=word2[i]){
            count++;
        }

    }
    return count;
}
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        dp.resize(words.size(),1);
        // find(0,words,groups);
        int maxi=INT_MIN;
        vector<int>parent(words.size(),-1);
        for(int i=1;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(groups[i]!=groups[j] && words[i].size()==words[j].size() && dist(words[i],words[j])==1){
                    
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        parent[i]=j;
                    }

                }
            }
        }
        int index=0;
       for(int i=0;i<dp.size();i++){
        if(maxi<=dp[i]){
            index=i;
            maxi=dp[i];
        }
       }
       for(auto it:dp)cout<<it<<" ";
       cout<<endl;
       for(auto it:parent) cout<<it<<" ";
       vector<string>ans;
       while(index!=-1){
        ans.push_back(words[index]);
        index=parent[index];
       }
       
       reverse(ans.begin(),ans.end());

        cout<<endl;
        return ans;
        
        
    }
};