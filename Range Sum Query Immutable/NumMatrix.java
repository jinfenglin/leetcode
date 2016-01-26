public class NumMatrix {
	private int[][] compressed;
	private int xLen,yLen;
	public NumMatrix(int[][] matrix) {
		xLen=matrix.length;
		if(xLen>0)
			yLen=matrix[0].length;
		else
			yLen=0;
		compressed=new int[xLen][yLen];
		for(int i=0;i<xLen;i++){
			for(int j=0;j<yLen;j++){
				if(j==0)
					compressed[i][j]=matrix[i][j];
				else
					compressed[i][j]=compressed[i][j-1]+matrix[i][j];
			}
		}
		for(int i=1;i<xLen;i++)
			for(int j=0;j<yLen;j++){
				compressed[i][j]+=compressed[i-1][j];
			}
	}

	public int sumRegion(int row1, int col1, int row2, int col2) {
		int publicData=0,upper=0,left=0;
		if(row1>0 && col1>0)
			publicData=compressed[row1-1][col1-1];
		if(row1>0)
			upper=compressed[row1-1][col2];
		if(col1>0)
			left= compressed[row2][col1-1];
		return compressed[row2][col2]-upper-left+publicData;
	}
	public static void main(String[] args){
		int[][] matrix= new int[][]{
			{3,0,1,4,2},
				{5,6,3,2,1},
				{1,2,0,1,5},
				{4,1,0,1,7},
				{1,0,3,0,5}
		};
		NumMatrix nm=new NumMatrix(matrix);
		System.out.println(nm.sumRegion(1,1,3,3));
	}
}

