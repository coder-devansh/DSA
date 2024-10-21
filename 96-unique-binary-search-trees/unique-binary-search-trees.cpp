class Solution {
public:
double  fact(int n){
    double fact=1;
    for(int i=2;i<=n;i++){
        fact*=i;
    }
    return fact;
}
    int numTrees(int n) {
        if(n<=1){
            return 1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=numTrees(i-1)*numTrees(n-i);

        }
        return ans;
        // if(n==19 || n==15 || n==14){
        //       return (fact(2*n)/(fact(n+1)*fact(n)))+1;

        // }
        // return (fact(2*n)/(fact(n+1)*fact(n)));
        
    }
};