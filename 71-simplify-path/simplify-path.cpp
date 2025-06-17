class Solution {
public:
void find(int&i,string&point,string&alpha,string path){
    bool points=true;;
    string val="";
    i++;
    for( i;i<path.size() && path[i]!='/';i++){
        
        if(path[i]!='.'){
            points=false;
        }
        val+=path[i];
    }
    if(points==true){
        point=val;

    }
    else
    {
        alpha=val;
    }
}
    string simplifyPath(string path) {
    vector<string>temp;
    stack<string>st;
    vector<string>ans;
   for(int i=0;i<path.size();){
    string alpha="";
    string point="";
    if(path[i]=='/'){
        find(i,point,alpha,path);

    }
    if(alpha.size()<=0 && path.size()<=0){
        continue;
    }
    if(point.size()>0){
         if(point.size()==2){
            if(!st.empty()){
                st.pop();
             }
        }
        else if(point.size()==1);
        else {
            st.push(point);
        }

    }else if(alpha.size()>0){
        st.push(alpha);

    }
    
       
        
       
    

   }
   while(!st.empty()){
    ans.push_back(st.top());
    st.pop();
   }
   string result="/";
    for(int i=ans.size()-1;i>=0;i--){
        if(ans[i].size()>0){
             result+=ans[i];
        result+='/';

        }
       

    }
    if(result.size()>1){
        result.pop_back();
    }
    
    return result;

        
    }
};