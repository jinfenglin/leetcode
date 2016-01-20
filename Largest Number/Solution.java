import java.util.*;
public class Solution {
	public String largestNumber(int[] nums) {
		ArrayList<Integer> newNums= new ArrayList<Integer>(nums.length);
		for(int i=0;i<nums.length;i++){
			newNums.add(Integer.valueOf(nums[i]));
		}
		Collections.sort(newNums,new Comparator<Integer>(){
			public int compare(Integer num1,Integer num2){
				String case1=Integer.toString(num1)+Integer.toString(num2);
				String case2=Integer.toString(num2)+Integer.toString(num1);
				return case2.compareTo(case1);
			}
		
		});
		StringBuilder sb= new StringBuilder();
		for(int num:newNums){
			sb.append(Integer.toString(num));
		}
		if(newNums.get(0)==0 && newNums.get(newNums.length-1)==0)
			return '0';
		else
			return sb.toString();
	}
}
