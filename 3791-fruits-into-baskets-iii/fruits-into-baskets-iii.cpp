class Solution {
public:
void builtSegmentTree(int i,int l,int r,vector<int>&fruits,vector<int>&tree){
    if(l==r){
        tree[i]=fruits[r];
        return ;
    }
    int mid=l+(r-l)/2;
    builtSegmentTree(2*i+1,l,mid,fruits,tree);
    builtSegmentTree(2*i+2,mid+1,r,fruits,tree);
    tree[i]=max(tree[2*i+1],tree[2*i+2]);
}
bool canbeplaced(int value,int i,int l,int r,vector<int>&tree){
    if(l==r){
        if(tree[i]>=value){
            tree[i]=-1;
            return true;
        }
        return false;
    }
    int mid=l+(r-l)/2;
    bool left=false;
    if(tree[2*i+1]>=value){
        left=canbeplaced(value,2*i+1,l,mid,tree);

    }
    bool right=false;
    if(!left && tree[2*i+2]>=value){
        right=canbeplaced(value,2*i+2,mid+1,r,tree);
    }

    tree[i]=max(tree[2*i+1],tree[2*i+2]);
    return left || right;

}
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
      int size = 4 * max((int)fruits.size(), (int)baskets.size());
        vector<int>segmentTree(size,0);
        builtSegmentTree(0,0,fruits.size()-1,baskets,segmentTree);
        
        int count=0;
        for(int i=0;i<fruits.size();i++){
            if(!canbeplaced(fruits[i],0,0,baskets.size()-1,segmentTree))count++;
        }

        return count;
        
    }
};