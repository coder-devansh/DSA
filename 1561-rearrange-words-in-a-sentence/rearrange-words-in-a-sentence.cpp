class Solution {
public:
static bool compare(const pair<string,int>&a,const pair<string,int>&b){

    return a.second<b.second;
}
    string arrangeWords(string text) {
      vector<pair<string,int>>vec;
       string s="";
      for(int i=0;i<text.size();i++){
        if(text[i]==' ')
        {
            
           vec.push_back({s,s.size()});
            s="";
        }else{
            
            s+=tolower(text[i]);
        }
        
        }
        vec.push_back({s,s.size()});

        stable_sort(vec.begin(),vec.end(),compare);
        string v="";
        
        for(auto it:vec){
           
            v+=it.first;
            v+=" ";
        }
        char value=toupper(v[0]);
        v[0]=value;

        v.pop_back();
        return v;
    }
};