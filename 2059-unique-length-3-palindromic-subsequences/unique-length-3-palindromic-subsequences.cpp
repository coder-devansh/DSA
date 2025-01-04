class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>first(26,-1);
        vector<int>last(26,-1);
        int count=0;
        for(int i=0;i<s.size();i++){
            if(first[s[i]-'a']==-1)
            {
                first[s[i]-'a']=i;
            }
            last[s[i]-'a']=i;
        }
        for(char ch='a';ch<='z';ch++){
            int left=first[ch-'a'];
            int right=last[ch-'a'];
            set<char>st;

            for(int i=left+1;i<right;i++){
                st.insert(s[i]-'a');


            }
            count+=st.size();
        }
        return count;
        
    }
};