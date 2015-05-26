#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
	    int length=triangle.back().size();
	    int layer=triangle.size();
	    int *temp=(int *)malloc(sizeof(int)*length);
	    memset(temp,1,sizeof(int)*length);
	    temp[0]=triangle[0][0];
	    for(int i=1;i<layer;i++){
	    	for(int j=triangle[i].size()-1;j>=0;j--){
			if(j>0 and j<triangle[i].size()-1){
				temp[j]=min(triangle[i][j]+temp[j],triangle[i][j]+temp[j-1]);
			}else if(j==0)
				temp[j]=triangle[i][j]+temp[j];
			else
				temp[j]=triangle[i][j]+temp[j-1];
		}
	    }
	    int result=temp[0];
	    for(int i=0;i<length;i++){		    
		    if(temp[i]<result)
			    result=temp[i];
	    }
	    return result;
    }
};
int main(){
	Solution *sol= new Solution;
	vector<int> f1={2};
	vector<int> f2={3,4};
	vector<int> f3={6,5,6};
	vector<int> f4={4,1,8,3};
	vector<vector<int> > init={f1,f2,f3,f4};	
	cout<<sol->minimumTotal(init)<<endl;
}
