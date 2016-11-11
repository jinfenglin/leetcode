c class Solution {

    public int maxRotateFunction(int[] A) {

        if(A.length ==0)

            return 0;

        long sum = 0;

        for(int i=0;i<A.length;i++){

            sum+=A[i];

        }

        int[] dp = new int[A.length];

        dp[0] = basicRotate(A);

        int max= dp[0];

        for(int i=1;i<A.length;i++){

            dp[i] = (int)(dp[i-1]+sum-A.length*A[A.length-i]);

            max = Math.max(dp[i], max);

        }

        return max;

    }

    public int basicRotate(int[] A){

        int res = 0;

        for(int i= 0;i<A.length;i++)

            res += A[i]*i;

        return res;

    }



}
