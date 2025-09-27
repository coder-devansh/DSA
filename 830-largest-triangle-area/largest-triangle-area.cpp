class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxi=INT_MIN;
        for(int i=0;i<points.size();i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=0;j<points.size();j++){
                int x2=points[j][0];
                int y2=points[j][1];
                for(int k=0;k<points.size();k++){
                    int x3=points[k][0];
                    int y3=points[k][1];
                    int val=x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
                    double ans=abs(val)*1.0/2;
                    maxi=max(maxi,ans);

                }
            }
        }
        return maxi;
        
    }
};