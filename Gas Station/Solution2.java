c class Solution {

    public int canCompleteCircuit(int[] gas, int[] cost) {

        int len = gas.length;

        if(len == 0)

            return -1;

        for(int i=0;i<len;){

            int j=0;

            int remain=0;

            for(;j<len;j++){

                int loc = (i+j)%len;

                remain+= gas[loc] - cost[loc];

                if(remain<0){

                    if(loc<i)

                        return -1;

                    i=loc+1;

                    break;

                }

            }

            if(j==len)

                return i;

        }

        return -1;

    }

}
