class Solution {
	public List<List<Integer>> subsetsWithDup(int[] nums) {
		Arrays.sort(nums);
		return helper(nums,0);
	}

	public helper(int[] nums,int index){
		List<List<Integer>> partSolution= new ArrayList<List<Integer>>();
		List<Integer> tmp= new ArrayList<Integer>();
		partSolution.add(tmp);
		if(index>=nums.length)
			return partSolution;
		int cur=nums[index];
		int count=0;
		while(index<nums.length && nums[index]==cur){
			index++;
			count++;
		}
		List<List<Integer>> rest = helper(nums,index);
		for(List<Integer> solution: rest){
			for(int i=0;i<count;i++){
				solution.add(cur);
				partSolution.add(solution)			
			}
		}
		return partSolution;
	}
}
