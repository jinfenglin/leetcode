public class Solution {
	public List<List<Integer>> permuteUnique(int[] nums) {
		Map<Integer,Integer> numMap=new HashMap<Integer,Integer>();
		for(int n:nums)
			numMap.put(n,numMap.get(n)+1);
		return DFS(mp,0,nums.length);

	}
	public List<List<Integer>> DFS(Map<Integer,Integer> mp,int round,int totalRound){
		List<List<Integer>> res=new ArrayList<List<Integer>>();
		if(round==totalRound){
			res.add(new ArrayList<Integer>());
			return res;
		}
		for(int key:mp.keySet()){
			if(mp.get(key)>0){
				mp.put(key,mp.get(key)-1);
				List<List<Integer>> tmp=DFS(mp,round+1,totalRound);
				for(List<Integer> solution:tmp){
					solution.add(key);
				}
				mp.put(key,mp.get(key)+1);
			}
		}
		return res;
	}
}
