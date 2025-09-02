class Solution {
public:
static bool custom(vector<int>&a,vector<int>&b){
    if(a[0]==b[0]){
        return a[1]<b[1];
    }
    return a[0]>b[0];
}
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),custom);
        int count=0;
        for(int i=0;i<points.size();i++){
            int x2=points[i][0];
            int y2=points[i][1];
             
            for(int j=i+1;j<points.size();j++){
                int x1=points[j][0];
                int y1=points[j][1];

                if(x2>=x1 && y2<=y1){
                    bool found=false;
                    for(int k=0;k<points.size();k++){
                        int x=points[k][0];
                        int y=points[k][1];
                       if(points[i]==points[k] || points[j]==points[k])continue;
                        if((x1<=x && x<=x2) && (y2<=y && y<=y1)){
                            found=true;
                        }
                    
                }
                 if(!found)count++;
            }
        }
       
        
    }
    return count;
    }
};