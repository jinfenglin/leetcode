import java.util.*;
public class Solution {
	private void exploreMatrix(int[][] matrix,int x,int y,int xLen,int yLen,List<Integer> ans){
		if(xLen==1){
			for(int i=0;i<yLen;i++)
				ans.add(matrix[x][y+i]);
		}else if(yLen==1){
			for(int i=0;i<xLen;i++)
				ans.add(matrix[x+i][y]);
		}else{
			for(int i=0;i<yLen-1;i++)
				ans.add(matrix[x][y+i]);
			for(int i=0;i<xLen-1;i++)
				ans.add(matrix[x+i][y+yLen-1]);
			for(int i=0;i<yLen-1;i++)
				ans.add(matrix[x+xLen-1][y+yLen-1-i]);
			for(int i=0;i<xLen-1;i++)
				ans.add(matrix[x+xLen-1-i][y]);
		}
		if(xLen-2>0 && yLen-2>0)
			exploreMatrix(matrix,x+1,y+1,xLen-2,yLen-2,ans);

	}
	public List<Integer> spiralOrder(int[][] matrix) {
		List<Integer> ans=new ArrayList<Integer>();
		if(matrix.length>0)
			exploreMatrix(matrix,0,0,matrix.length,matrix[0].length,ans);
		return ans;
	}
	public static void main(String[] args){
		int[][] matrix={{1,2,3,10},{4,5,6,11},{7,8,9,12}};
		Solution sol=new Solution();
		List<Integer> ans=sol.spiralOrder(matrix);
		for(int num:ans)
			System.out.print(num+" ");
		System.out.println("");
	}
}
