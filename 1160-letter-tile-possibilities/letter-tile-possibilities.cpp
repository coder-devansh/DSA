class Solution {
public:
set<string>st;

vector<int>used;
void find(string tiles,string path){
    if(path.size()>0){

         st.insert(path);

    }
   
    for(int i=0;i<tiles.size();i++){
        if(used[i]==0){
            used[i]=1;
            find(tiles,path+tiles[i]);
            used[i]=0;
        }

    }
   



    
   
}
    int numTilePossibilities(string tiles) {
        used.resize(tiles.size(),0);
       find(tiles,"");
       return st.size();

        
    }
};