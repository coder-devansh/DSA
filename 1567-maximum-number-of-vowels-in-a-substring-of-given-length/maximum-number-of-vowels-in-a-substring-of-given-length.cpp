class Solution {
public:
bool Vowel(char ch){
    if(ch=='a' || ch=='e' ||ch=='i' || ch=='o' || ch=='u'){
        return true;
    }
    return false;
}
    int maxVowels(string s, int k) {
        int count=0;
        int maxi=INT_MIN;
        for(int i=0;i<k;i++){
if(Vowel(s[i])){
    count++;
}

        }
        maxi=max(maxi,count);
        for(int i=k;i<s.size();i++){
            if(Vowel(s[i-k])){
                count--;
            }
            if(Vowel(s[i])){
                count++;
            }
            maxi=max(maxi,count);
        }
        return maxi;

        
    }
};