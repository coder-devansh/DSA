class Solution {
public:
static bool compare(const pair<int,pair<int,char>>&a,const pair<int,pair<int,char>>&b){
    return a.first<b.first;
}
    vector<int> survivedRobotsHealths(vector<int>& position, vector<int>& health, string dir) {
        vector<int>temp=position;
        vector<pair<int,pair<int,char>>>vec;
        for(int i=0;i<position.size();i++)
        {
            vec.push_back({position[i],{health[i],dir[i]}});
        }
        sort(vec.begin(),vec.end(),compare);
        for(int i=0;i<vec.size();i++){
            position[i]=vec[i].first;
            dir[i]=vec[i].second.second;
            health[i]=vec[i].second.first;
        }
        stack<int>st;
         
        for(int i=0;i<position.size();i++){
            if(dir[i]=='R'){
                st.push(i);
                
                continue;
            }
            else if(dir[i]=='L')
            {
                
                
                if(!st.empty() && dir[st.top()]=='R'){
                    bool found=false;
                while(!st.empty() && dir[st.top()]=='R'){
                    if(health[i]==health[st.top()]){
                        found=true;
                        st.pop();
                        
                        break;
                        
                    }
                    if(health[i]>health[st.top()]){
                        st.pop();
                        health[i]-=1;
                        continue;
                        
                    }
                    if(health[i]<health[st.top()]){
                       found=true;
                        health[st.top()]-=1;
                        
                        break;
                        
                    }

                }
                if(!found){
                    st.push(i);
                }
                }else{
                    st.push(i);
                    
                }
            }
            
        }
        map<int,int>mp;
        for(int i=0;i<health.size();i++){
            mp[position[i]]=health[i];
        }
        
        set<int>st1;
        vector<int>ans;
        
        while(!st.empty()){
            st1.insert(position[st.top()]);
            st.pop();
        }
        for(int i=0;i<temp.size();i++){
            if(st1.find(temp[i])!=st1.end()){
                ans.push_back(mp[temp[i]]);
            }
        }
        return ans;
        
    }
};