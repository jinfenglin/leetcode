c class Solution {

    public String addBinary(String a, String b) {

        int addBit=0;

        String longString = a.length()>b.length()?a:b;

        String shortString = a.length()<=b.length()?a:b;

        int diff = Math.abs(a.length()-b.length());

        StringBuilder sb = new StringBuilder();

        for(int i=0;i<diff;i++){

            sb.append(0);

        }

        sb.append(shortString);

        shortString = sb.toString();

        StringBuilder res = new StringBuilder();

        for(int i=Math.max(a.length(),b.length())-1;i>=0;i--){

            int digit1 = shortString.charAt(i) - '0';

            int digit2 = longString.charAt(i) - '0';

            int sum = digit1+digit2+addBit;

            addBit = sum>1?1:0;

            sum = sum%2;

            res.append(sum);

        }

        if(addBit==1)

            res.append(1);

        return res.reverse().toString();

    }

}
