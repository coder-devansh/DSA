class Solution {
public:
static bool compare(vector<int>&a,vector<int>&b){
    if(a[1]==b[1]){
        return a[0]<b[0];
    }
    return a[1]<b[1];
}
bool y_found(vector<vector<int>>&buildings,int value1,int value2){
    int low=0;
    int high=buildings.size()-1;
    int upper_bound=-1;
    int lower_bound=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(buildings[mid][1]==value1){
            upper_bound=mid;
            low=mid+1;
        }else if(buildings[mid][1]<value1){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }

if(upper_bound==-1 || buildings[upper_bound][0]==value2)return false;
     low=0;
     high=buildings.size()-1;
     while(low<=high){
        int mid=(low+high)/2;
        if(buildings[mid][1]==value1){
            lower_bound=mid;
            high=mid-1;
        }else if(buildings[mid][1]<value1){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    if(lower_bound==-1)return false;
    if(buildings[lower_bound][0]==value2)return false;
    return true;
}
bool x_found(vector<vector<int>>&buildings,int value1,int value2){
    int low=0;
    int high=buildings.size()-1;
    int upper_bound=-1;
    int lower_bound=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(buildings[mid][0]==value1){
            upper_bound=mid;
            low=mid+1;
        }else if(buildings[mid][0]<value1){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    if(upper_bound==-1)return false;
    if(buildings[upper_bound][1]==value2)return false;
     low=0;
     high=buildings.size()-1;
     while(low<=high){
        int mid=(low+high)/2;
        if(buildings[mid][0]==value1){
            lower_bound=mid;
            high=mid-1;
        }else if(buildings[mid][0]<value1){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    if(lower_bound==-1)return false;
    if(buildings[lower_bound][1]==value2)return false;
    return true;
}
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int count=0;
        vector<vector<int>>store(n,vector<int>(2,0));
        store=buildings;
        sort(store.begin(),store.end(),compare);
        sort(buildings.begin(),buildings.end());
        for(int i=0;i<buildings.size();i++){
            int value1=buildings[i][0];
            int value2=buildings[i][1];
           bool left= x_found(buildings,value1,value2);
            bool right=y_found(store,value2,value1);
            if(left && right)count++;
        }
        return count;


       

            
        
        

        
    }
};