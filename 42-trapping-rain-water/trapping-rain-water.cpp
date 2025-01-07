class Solution {
public:
    int trap(vector<int>& height) {
        long long sum=0;
        int n=height.size();
        vector<int>prefix(height.size()+1,0);
        vector<int>suffix(height.size()+1,0);
        prefix[0]=height[0];
        for(int i=1;i<height.size();i++){
            prefix[i]=max(height[i],prefix[i-1]);
        }
        suffix[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(height[i],suffix[i+1]);

        }
        for(int i=0;i<n;i++){
            int leftmax=prefix[i];
            int rightmax=suffix[i];
            if(leftmax>height[i] && height[i]<rightmax){
                sum+=min(leftmax,rightmax)-height[i];
            }

        }
        return sum;
       
        
        
    }
};