#include <iostream>
#include <vector>
using namespace std;


class NumMatrix {
	public:
		vector<vector<int>> folded;
		int rows,cols;
		NumMatrix(vector<vector<int>> &matrix) {
			rows=matrix.size();
			if(rows)
				cols=matrix[0].size();
			else
				cols=0;
			for(int i=0;i<rows;i++){
				vector<int> tmp;
				tmp.resize(cols);
				for(int j=0;j<cols;j++){
					if(j==0)
						tmp[j]=matrix[i][j];
					else
						tmp[j]=tmp[j-1]+matrix[i][j];
				}
				folded.push_back(tmp);
			}
			for(int j=0;j<cols;j++)
				for(int i=0;i<rows;i++){
					if(i==0)
						continue;
					else
						folded[i][j]=folded[i-1][j]+folded[i][j];
				}
		}

		int sumRegion(int row1, int col1, int row2, int col2) {
			if(row1>0 and col1>0)
				return folded[row2][col2]-folded[row1-1][col2]-folded[row2][col1-1]+folded[row1-1][col1-1];
			else if(row1==0){
				return folded[row2][col2]-folded[row2][col1-1];
			}
			else{
				return folded[row2][col2]-folded[row1-1][col2];
			}
		}
};

int main(){
}
