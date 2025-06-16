class Solution {
public:
vector<string>ans;
void generate(int open,int closed,string temp){
    if(open==0 && closed==0){
        ans.push_back(temp);
        return;

    }
    if(open>0){
        generate(open-1,closed,temp+')');
    }
     if(closed>0 && open>=closed){
        generate(open,closed-1,temp+'(');
    }
}
    vector<string> generateParenthesis(int n) {
        
        generate(n,n,"");
        return ans;
        
    }
};