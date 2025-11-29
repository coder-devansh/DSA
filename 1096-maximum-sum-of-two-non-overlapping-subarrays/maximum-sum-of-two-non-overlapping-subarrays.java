class Solution {
    public int maxSumTwoNoOverlap(int[] nums, int firstLen, int secondLen) {
        int max_sum=Integer.MIN_VALUE;
        int n=nums.length;
        int prefix[]=new int[n];
        int suffix[]=new int[n];
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i];
        }
        int prefix_first[]=new int[n];
        int suffix_first[]=new int[n];
        int prefix_second[]=new int[n];
        int suffix_second[]=new int[n];
        if(firstLen==1){
            prefix_first[0]=nums[0];
            suffix_first[n-1]=nums[n-1];

        }
        if(secondLen==1){
            prefix_second[0]=nums[0];
            suffix_second[0]=nums[n-1];
                    }
        for(int i=1;i<nums.length;i++){
           if(i-firstLen+1==0){
            prefix_first[i]=Math.max(prefix_first[i-1],prefix[i]);
           }else if(i-firstLen>=0){
prefix_first[i]=Math.max(prefix_first[i-1],prefix[i]-prefix[i-firstLen]);
           }
           if(i-secondLen+1==0){
            prefix_second[i]=Math.max(prefix_second[i-1],prefix[i]);
           }else if(i-secondLen>=0){
prefix_second[i]=Math.max(prefix_second[i-1],prefix[i]-prefix[i-secondLen]);
           }
    }
    for(int i=n-2;i>=0;i--){
        if(i+firstLen-1==n-1){
            suffix_first[i]=Math.max(suffix_first[i+1],suffix[i]);
           }else if(i+firstLen<=n-1){
suffix_first[i]=Math.max(suffix_first[i+1],suffix[i]-suffix[i+firstLen]);
           }
           if(i+secondLen-1==n-1){
            suffix_second[i]=Math.max(suffix_second[i+1],suffix[i]);
           }else if(i+secondLen<=n-1){
suffix_second[i]=Math.max(suffix_second[i+1],suffix[i]-suffix[i+secondLen]);
           }
        
    }
    // for(int ele:suffix_first){
    //     System.out.print(ele+" ");
    // }
    // System.out.println();
    // for(int ele:suffix_second){
    //     System.out.print(ele+" ");
    // }
    for(int i=1;i<nums.length-1;i++){
        max_sum=Math.max(max_sum,prefix_first[i]+suffix_second[i+1]);
        max_sum=Math.max(max_sum,suffix_first[i]+prefix_second[i-1]);
        max_sum=Math.max(max_sum,prefix_second[i]+suffix_first[i+1]);
        max_sum=Math.max(max_sum,suffix_second[i]+prefix_first[i-1]);
    }

    return max_sum;
    }
}

