#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
 vector<int> getRow(int rowIndex) {

        vector<int> row(rowIndex+1,0);
        row[0]=1;
        for(int i=1;i<=rowIndex;i++)
            for(int j=i;j>=1;j--)
                row[j]=row[j-1]+row[j];

        return(row);
    }};

int main(){
	Solution *sol= new Solution;
	auto result=sol->getRow(30);
	for(int x:result){
		cout<<x<<" ";
	}
	cout<<endl;
}
