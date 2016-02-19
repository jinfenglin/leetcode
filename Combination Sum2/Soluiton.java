public class Solution {
	public List<List<Integer>> combinationSum2(int[] candidates, int target) {
		Arrays.sort(candidates);
		return DFS(candidates,0,target);
	}
	public List<List<Integer>> DFS(int[] candidates,int index,int target){
		List<List<Integer>> result=new ArrayList<List<Integer>>();
		//System.out.println(target);
		if(target==0){
		    result.add(new ArrayList<Integer>());
		}
		if(index>=candidates.length)
			return result;
		for(int i=index;i<candidates.length;i++){
		    if(target-candidates[i]<0)
		        break;
		    List<List<Integer>> tmp=DFS(candidates,i+1,target-candidates[i]);
		    for(List<Integer> iter:tmp){
		        iter.add(0,candidates[i]);
		        result.add(iter);
		    }
		    while(i<candidates.length-1 && candidates[i]==candidates[i+1])
		        i++;
		}
		return result;
	}
}
