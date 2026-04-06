#define ll long long
class Solution {
public:

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>>st;
        string str="NESW";
        int x_dir[4]={0,1,0,-1};
        int y_dir[4]={1,0,-1,0};
        int curr_dir=0;
        for(auto it:obstacles){
            st.insert({it[0],it[1]});
        }
        ll max_ans=0;
        
        ll x=0;
        ll y=0;
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-2){
                if(curr_dir-1==-1)curr_dir=str.size()-1;
                else curr_dir--;

            }
            else if(commands[i]==-1){
                if(curr_dir+1==str.size())curr_dir=0;
                else curr_dir++;
            }
            else{
                for(int k=1;k<=commands[i];k++){
                    x+=x_dir[curr_dir];
                    y+=y_dir[curr_dir];
                    if(st.find({x,y})!=st.end()){
                        x-=x_dir[curr_dir];
                        y-=y_dir[curr_dir];
                        max_ans=max(max_ans,(x*x+y*y));
                        break;
                    }else
                    {
                        max_ans=max(max_ans,(x*x+y*y));
                    }
                }
            }
           
            max_ans=max(max_ans,(x*x+y*y));
        }
       
        return (max_ans);



    
        
    }
};