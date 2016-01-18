import java.util.*;
public class NumArray{
	private int [] nums;
	private int [] carray;
	public NumArray(int[] nums) {
		int size=nums.length;
		this.nums=new int[size];
		carray= new int[size+1];
		for(int i=0;i<nums.length;i++){
			update(i,nums[i]);	
		}
	}

	int lowbit(int n){
		return n & -n;
	}
	void update(int i, int val) {
		int differ=nums[i]-val;
		nums[i]=val;
		while(i<nums.length){
			carray[i+1]-=differ;
			i+=lowbit(i+1);
		}


	}
	int getSum(int i){
		int res=0;
		while(i>=0){
			res+=carray[i+1];
			i-=lowbit(i+1);
		}
		return res;
	}
	public int sumRange(int i, int j) {
		return getSum(j)-getSum(i-1);//+nums[i];

	}
	public static void main(String[] args){

		int[] input={1,2,3};
		NumArray sol= new NumArray(input);
		System.out.println(sol.sumRange(0,2));
		//sol.update(0,3);
		System.out.println(sol.sumRange(1,2));

	}
}

