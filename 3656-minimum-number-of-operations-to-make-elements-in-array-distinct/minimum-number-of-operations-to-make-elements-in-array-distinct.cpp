class Solution {
public:
bool found(int i,int n,vector<int>&nums){
    map<int,int>mp;
    for(int j=i;j<n;j++){
        mp[nums[j]]++;
        if(mp[nums[j]]>=2) return false;

    }
    return true;
}
    int minimumOperations(vector<int>& nums) {
        map<int,int>mp;
        bool duplicate=false;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
        if(mp[nums[i]]==2){
            duplicate=true;

        }


    }
    if(duplicate==false) return 0;
    if(duplicate ==true && nums.size()<=3) return 1;
    int i=0;
    int opr=0;
    while(i<nums.size()){
        if(i+3<nums.size()){
            if(found(i,nums.size(),nums)){
                return opr;
            }
            
            i+=3;
            opr++;
        }else{
            break;
        }
    }
    bool duplicat=false;
            map<int,int>p;
            for(int j=i;j<nums.size();j++){
                p[nums[j]]++;
                if(p[nums[j]]>=2) duplicat=true;

            }
            if(duplicat==true){
                return opr+1;
            }
            return opr;

        
    }
};