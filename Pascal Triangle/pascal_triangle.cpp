#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
	    vector< vector<int> > result;
	    for(int counter=0;counter<numRows;counter++){
		vector<int> temp;
		for(int i=0;i<=counter;i++){
			if(i==0 or i==counter)
				temp.push_back(1);
			else{
				temp.push_back(result[counter-1][i-1]+result[counter-1][i]);
			}
		}
		result.push_back(temp);	
	    }
	    return result;
		
    }
};

int main(){
	Solution *sol=new Solution();
	auto result=sol-> generate(5);
	for(auto x:result)
	{
		for(auto y:x)
		{
			cout<<y;
		}
		cout<<endl;
	}

	return 0;
}
