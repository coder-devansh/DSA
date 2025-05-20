class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int left=0;
        int right=people.size()-1;
        int boat=0;
        while(left<=right){
            if(people[left]+people[right]<=limit){
                boat+=1;
                left++;
                right--;
            }else if(people[right]<=limit){
                right--;
                boat++;
            }else{
                left++;
                boat++;
            }
                
            }
        return boat;
        
    }
};