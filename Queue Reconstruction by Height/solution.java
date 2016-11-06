public class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people,new Rank());
        List<int[]> res = new LinkedList<int[]>();
        for(int i=0;i<people.length;i++){
            res.add(people[i][1],people[i]);
        }
        int[][] output = new int[people.length][2];
        for(int i=0;i<people.length;i++)
            output[i] = res.get(i);
        return output;
    }
    private class Rank implements Comparator<int[]>{
        @Override
        public int compare(int[] a,int[] b){
            if(a[0]==b[0])
                return a[1] - b[1];
            return b[0] - a[0];
        }
    }
}
