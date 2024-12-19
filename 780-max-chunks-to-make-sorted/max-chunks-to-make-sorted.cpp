class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
      int n=arr.size();
      vector<int>prefix(arr);
      vector<int>suffix(arr);
      for(int i=1;i<n;i++){
        prefix[i]=max(prefix[i],prefix[i-1]);
      }
      for(int i=n-2;i>=0;i--){
        suffix[i]=min(suffix[i],suffix[i+1]);
      }
      int chunks=0;
      for(int i=0;i<n;i++){
        if(i==0 || suffix[i]>prefix[i-1])
        {
            chunks++;
        }
      }
      return chunks;

        

        
    }
};