
class Solution {
public:
vector<int>parent;
int find(int node){
    if(parent[node]==node)return node;
    return parent[node]=find(parent[node]);
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(int i=0;i<s1.size();i++){
            int u=find(s1[i]-'a');
            int v=find(s2[i]-'a');
            if(u>v){
                parent[u]=v;
            }else {
                parent[v]=u;
            }
        }
        string str="";
        for(int i=0;i<baseStr.size();i++){
           str+=(char)(find(baseStr[i]-'a')+'a');

        }
        return str;

        
    }
};