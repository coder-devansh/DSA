class Solution {
public:
// recursion approach

    int candy(vector<int>& rating) {
        long long sum=1;
        int n=rating.size();
        int i=1;
        while(i<n){
            if(rating[i]==rating[i-1]){
                sum+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && rating[i]>rating[i-1]){
                peak++;
                sum+=peak;
                
                i++;

            }
            int down=1;
            while(i<n && rating[i]<rating[i-1]){
                sum+=down;
                down++;
                i++;
            }
            if(down>peak){
                sum+=(down-peak);
            }
        }
        return sum;
    }
};