class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int max_area=INT_MIN;
        while(left<right){
            if(height[left]>height[right]){
                int area=(height[right])*(right-left);
                max_area=max(max_area,area);
                right--;


            }else{
                int area=(height[left])*(right-left);
                max_area=max(max_area,area);
                left++;


            }

        }
        return max_area;
        
    }
};