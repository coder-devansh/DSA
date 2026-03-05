class Solution {
public:
int find(int num,string s){
    int count=0;
    for(int i=0;i<s.size();i++){
        if(i%2==0 && s[i]-'0'!=num)count++;
        else if(i%2!=0 && s[i]-'0'!=(1-num))count++;
    }
    return count;
}
    int minOperations(string s) {
        return min(find(0,s),find(1,s));
        
    }
};