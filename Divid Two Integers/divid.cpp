#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

class Solution {
	public:
		int divide(int dividend, int divisor) {
			unsigned int dvd = abs(dividend); 
			unsigned int dvs = abs(divisor);
			unsigned int save_dvs=dvs;
			unsigned int count=0;
			int add=1;

			bool flag=true;
			if(dividend<0)
				flag=!flag;
			if(divisor<0)
				flag=!flag;
			while(dvd){
				//cout<<"dvd:"<<dvd<<" dvs:"<<dvs<<endl;
				cout<<"count:"<<count<<endl;
				if(dvd<save_dvs)
					dvd=0;
				else{
					if(dvd>=dvs){
						dvd-=dvs;
						dvs+=dvs;
						count+=add;
						add+=add;
					}
					else{
						add=1;
						dvs=save_dvs;
					}
				}

			}
			if(count>INT_MAX and flag)
				count=INT_MAX;
			if(!flag)
				count=-count;
			return count;		

		}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->divide(INT_MIN,1)<<endl;
}
