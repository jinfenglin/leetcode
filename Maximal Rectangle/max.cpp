#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
	public:
		int cal_area(vector<int> vec){
			stack<int> stk;
			vec.push_back(0);
			int max_area=0;
			for(int i=0;i<vec.size();i++){
				//cout<<i<<endl;
				if(!stk.empty())
				{
					while(!stk.empty() and vec[i]<vec[stk.top()]){
						int tmp=vec[stk.top()];
						stk.pop();
						int length=0;
						if(stk.empty()){
							length=i;
						}
						else{
							//cout<<"top:"<<stk.top()<<endl;
						       	length=i-(stk.top()+1);
						}
						//cout<<"length:"<<length<<endl;
						int area=tmp*length;
						//cout<<"area:"<<area<<endl;
						max_area=max(area,max_area);
					}
				}
				stk.push(i);
			}
			return max_area;
		}
		int maximalRectangle(vector<vector<char>>& matrix) {
			vector<vector<int> > height;
			for(int i=0;i<matrix.size();i++){
				vector<int> tmp;
				for(int j=0;j<matrix[i].size();j++){
					if(matrix[i][j]=='1'){
						if(i>0){
							tmp.push_back(height[i-1][j]+1);
						}else{
							tmp.push_back(1);
						}
					}else{
						tmp.push_back(0);
					}
				}
				height.push_back(tmp);
			}
			int max_area=0;
			for(int i=0;i<height.size();i++){
				int area=cal_area(height[i]);
				max_area=max(area,max_area);

			}
			return max_area;

		}
};
int main(){
	Solution *sol= new Solution;
	vector<char> f1={'0','1','1','0','0'};
	vector<char> f2={'0','0','0','1','0'};
	vector<char> f3={'0','1','1','1','0'};
	vector<char> f4={'0','1','1','1','0'};
	vector<char> f5={'0','0','0','0','0'};
	vector<int> test={4,1,4,3};
	//cout<<"test:"<<endl;
	//cout<<sol->cal_area(test)<<endl;
	vector<vector<char> > init={f1,f2,f3,f4,f5};
	cout<<sol-> maximalRectangle(init)<<endl;
}
