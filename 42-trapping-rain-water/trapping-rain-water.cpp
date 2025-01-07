class Solution {
public:
// for each index 

    int trap(vector<int>& height) {
        vector<int>prefix(height.size()+1,0);
        vector<int>suffix(height.size()+1,0);
        prefix[0]=height[0];
        for(int i=1;i<height.size();i++){
            prefix[i]=max(height[i],prefix[i-1]);

        }
        int n=height.size();
        suffix[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(height[i],suffix[i+1]);
        }
        long long sum=0;
        for(int i=0;i<height.size();i++){
            int leftmax=prefix[i];
            int rightmax=suffix[i];
            if(leftmax>height[i] && rightmax>height[i])
            {
                sum+=min(leftmax,rightmax)-height[i];
            }
        }
        return sum;
        
    }
};