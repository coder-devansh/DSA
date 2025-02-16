class Solution {
public:
set<int>st;
vector<vector<int>>result;
bool generate(int index,int n,vector<int>&arr){
    if(index==arr.size()){
        for(auto it:arr){
            cout<<it<<" ";
        }
        cout<<endl;

        return true;
    }
    if(index<arr.size() && arr[index]!=0){
        return generate(index+1,n,arr);
    }
    for(int i=n;i>=1;i--){
        if(st.find(i)!=st.end()) continue;
        if(i==1){
            arr[index]=1;
            st.insert(1);
           if( generate(i+1,n,arr))return true;
            arr[index]=0;
            st.erase(1);
        }else{
            if(i+index<arr.size() && arr[i+index]==0){
                arr[index]=i;
                arr[index+i]=i;
                st.insert(i);
                if(generate(index+1,n,arr)) return true;
                arr[index]=0;
                arr[index+i]=0;
                st.erase(i);
            }
        }
    }
    return false;

 

       
    
}
    vector<int> constructDistancedSequence(int n) {
        vector<int>arr(2*n-1,0);
        generate(0,n,arr);
        if(n==1){
            return {1};
        }
        return arr;
        

        
        
        
        
        
    }
};