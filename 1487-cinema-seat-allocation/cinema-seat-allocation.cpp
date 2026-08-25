// // min_locked 2 se kam hai or max_locked 9 se jyada hai toh 2
// min_locked 4 se kam hai or 8 se jyada hai to 1
// min_locked 2 se kam hai or 5 se jyada hai to 1
// min_locked 2 se kam  hai or max_locked 6 se jyada hai 1






class Solution {
public:
static bool compare(vector<int>&a,vector<int>&b){
    if(a[0]==b[0]){
        return a[1]<b[1];
    }
    return a[0]<b[0];
}
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end(),compare);
       set<int>st;
       int ans=0;
       st.insert(reservedSeats[0][0]);
       int min_locked=0;
       int max_locked =reservedSeats[0][1];
     if (min_locked < 2 && max_locked > 9)
    ans += 2;

else if (min_locked < 4 && max_locked > 7)
    ans += 1;

else if (min_locked < 2 && max_locked > 5)
    ans += 1;

else if (min_locked < 6 && max_locked > 9)
    ans += 1;
       for(int i=1;i<reservedSeats.size();i++){
        if(reservedSeats[i][0]==reservedSeats[i-1][0]){
            min_locked=max_locked;
            max_locked=reservedSeats[i][1];
        if (min_locked < 2 && max_locked > 9)
    ans += 2;

else if (min_locked < 4 && max_locked > 7)
    ans += 1;

else if (min_locked < 2 && max_locked > 5)
    ans += 1;

else if (min_locked < 6 && max_locked > 9)
    ans += 1;

        }else{
            if(max_locked<2)ans+=2;
            else if(max_locked<4)ans+=1;
            else if(max_locked<6)ans+=1;
            min_locked=0;
            
            max_locked=reservedSeats[i][1];
            st.insert(reservedSeats[i][0]);
           if (min_locked < 2 && max_locked > 9)
    ans += 2;

else if (min_locked < 4 && max_locked > 7)
    ans += 1;

else if (min_locked < 2 && max_locked > 5)
    ans += 1;

else if (min_locked < 6 && max_locked > 9)
    ans += 1;

        }


       }
        if(max_locked<2)ans+=2;
            else if(max_locked<4)ans+=1;
            else if(max_locked<6)ans+=1;
       return ans+(n-st.size())*2;




      

        

        
    }
};