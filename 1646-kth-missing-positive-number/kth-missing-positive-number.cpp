class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int maxi=0;
       for(auto it:arr){
        maxi=max(maxi,it);
       }
       vector<int>vec;
       for(int i=1;i<=maxi;i++){
        vec.push_back(i);
       }
      for(int i=0;i<arr.size();i++){
        auto it=find(vec.begin(),vec.end(),arr[i]);
        if(it!=vec.end()){
            vec.erase(it);
        }
      }
      if(vec.size()==0){
        return arr[arr.size()-1]+k;
      }
      if(k<=vec.size()){
        return vec[k-1];
      }
      return arr[arr.size()-1]+(k-vec.size());
    }
};