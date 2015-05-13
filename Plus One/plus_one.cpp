#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
	    for(auto it=digits.rbegin();it!=digits.rend();it++)
	    {
		    cout<<*it<<endl;
		    if(*it==9 and it+1==digits.rend())
		    {
			    *it=0;
			    digits.insert(digits.begin(),1);
			    return digits;
		    }
		    else if(*it==9)
			    *it=0;	 
		    else
		    {
			    *it+=1;
			    return digits;
		    }
	    }
        
    }
};
int main()
{
	Solution *sol=new Solution;
	int array[]={9,9,9};
	vector<int> input(array,array+sizeof(array)/sizeof(int));
	
	vector<int> result=sol->plusOne(input);
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i];
	}
	cout<<endl;
	return 0;
}
