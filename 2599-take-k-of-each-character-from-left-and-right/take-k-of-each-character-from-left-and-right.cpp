class Solution {
public:
    int takeCharacters(string s, int k) {
    map<char,int>mp;
vector<int>count(3,0);
    for(int i=0;i<s.size();i++){
        count[s[i]-'a']++;
    }
    for(int i=0;i<3;i++){
       if(count[i]<k)
       {
        return -1;
       }
    }

int maxWindow=0;
int l=0;
int r=0;


vector<int>window(3,0);
int left=0;
for(int right=0;right<s.size();right++){
    window[s[right]-'a']++;

    while(left<=right && ((count[0]-window[0])<k || (count[1]-window[1])<k || (count[2]-window[2])<k)){
        window[s[left]-'a']--;
        left++;
    }
    maxWindow=max(maxWindow,right-left+1);
}
return s.size()-maxWindow;

  
   

  }
    
};