class Solution {
    public boolean isSubsequence(String s, String t) {

        if(s.length() ==0)

            return true;

        if(t.length() ==0)

            return false;

        int cur = 0;

        for(int i=0;i<t.length();i++){

                if(t.charAt(i) == s.charAt(cur))

                        cur++;

                if(cur == s.length())

                        return true;

        }

        return false;

    }

}
