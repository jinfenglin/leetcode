#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string intToRoman(int num) {
        char char_list[]= {'M','D','C','L','X','V','I'};
	int num_list[] = {1000,500,100,50,10,5,1};
	string result;
	while(num){
		for(int i=0;i<7;i++){
			int count=num/num_list[i];
			if(count and count<4){
				result.append(count,char_list[i]);
				num-=count*num_list[i];
				break;
			}else if(count==0){
				if(num>=num_list[i]-num_list[i+2] and i%2==0)
				{
					result.append(1,char_list[i+2]);
					result.append(1,char_list[i]);
					num-=num_list[i]-num_list[i+2];
					break;
				}
				else if(num>=num_list[i]-num_list[i+1] and i%2==1){
					result.append(1,char_list[i+1]);
					result.append(1,char_list[i]);
					num-=num_list[i]-num_list[i+1];
					break;
				}
			}		
		}
	}
	return result;
    }
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->intToRoman(3900)<<endl;
	
}
