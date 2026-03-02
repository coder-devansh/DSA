class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int>maxRight;

        for(int i=0;i<grid.size();i++){
            int pos=-1;
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    pos=j;
                }

            }
            maxRight.push_back(pos);
   
        }
        vector<int>all_pos=maxRight;
        sort(maxRight.begin(),maxRight.end());
        for(int i=0;i<maxRight.size();i++){
            if(maxRight[i]>i)return -1;
        }
        int count=0;
        for(int i=0;i<all_pos.size();i++){
            if(all_pos[i]<=i)continue;
            for(int j=i+1;j<all_pos.size();j++){
                if(all_pos[j]<=i){
                    int num=j;
                    while(num!=i){
                        swap(all_pos[num],all_pos[num-1]);
                        num--;
                        count++;

                    }
                    break;
                }
            }
        }
        return count;
    


        
    }
};