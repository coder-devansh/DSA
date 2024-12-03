class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int j=0;
        for(int i=0;s[i];i++){
            if(j<spaces.size()&&i==spaces[j]){
                ans+=" ";
                j++;
            }
            ans+=s[i];
        }
        return ans;
    }
};
static const int _ = []()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  return 0;
}();