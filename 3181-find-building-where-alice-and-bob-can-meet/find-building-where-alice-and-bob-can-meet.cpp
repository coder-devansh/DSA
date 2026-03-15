
class Solution {
public:
vector<int>seg;
void buildTree(int ind,int low,int high,vector<int>&height){
    if(low==high){
        seg[ind]=low;
        return;
    }
    int mid=(low+high)/2;
    buildTree(2*ind+1,low,mid,height);
    buildTree(2*ind+2,mid+1,high,height);
    int leftIndex=seg[2*ind+1];
    int rightIndex=seg[2*ind+2];
    if(height[leftIndex]>=height[rightIndex]){
        seg[ind]=leftIndex;
    }else{
        seg[ind]=rightIndex;
    }

}
int getIndex(int ind,int low,int high,int l,int r,vector<int>&height)
{
    if(low>=l && high<=r)return seg[ind];
    if(low>r || high<l)return -1;
    int mid=(low+high)/2;
    int leftIndex = getIndex(2*ind+1,low,mid,l,r,height);
    int rightIndex=getIndex(2*ind+2,mid+1,high,l,r,height);
    if(leftIndex==-1)return rightIndex;
    if(rightIndex==-1)return leftIndex;
    if(height[leftIndex]>=height[rightIndex])return leftIndex;
    else return rightIndex;
}
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        seg.resize(4*(heights.size()),0);
        buildTree(0,0,heights.size()-1,heights);
        vector<int>result;
        for(auto it:queries){
            int leftIndex=max(it[0],it[1]);
            int rightIndex=min(it[0],it[1]);
            if(leftIndex==rightIndex){
                result.push_back(leftIndex);
                continue;
            }
if(heights[leftIndex]>heights[rightIndex]){
    result.push_back( leftIndex);
    continue;
}
int max_element=max(heights[leftIndex],heights[rightIndex]);
    int low=leftIndex+1;
    int high=heights.size()-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
    int index=getIndex(0,0,heights.size()-1,low,mid,heights);
    if(index!=-1 && heights[index]>max_element){
        ans=index;
        high=mid-1;
    }else
    {
        low=mid+1;
    }
}
    result.push_back(ans);
}
        return result;
        
    }
};