#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		vector<string> digits={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
		string digitToWords(int num){
			vector<string> Ten2Twenty={"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
			vector<string> ten_digit={"Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
			string res;
			int count=0;
			int hunder=num/100;
			int tens=(num%100)/10;
			int digit=num%10;

			if(hunder!=0)
			{
				res+=digits[hunder-1]+" Hundred";
			}
			switch(tens){				
				case 0: break;
				case 1:	{
						if(res.size()>0)
							res+=" ";
						if(digit!=0)
							res+=Ten2Twenty[digit-1];
						else
							res+=ten_digit[tens-1];
						return res;
					}
				default: {
						 if(res.size()>0)
							 res+=" ";
						 if(digit!=0)
							 res+=ten_digit[tens-1];
						 else{
							 res+=ten_digit[tens-1];
							 return res;
						 }
					 }
			}
			if(digit!=0){
				if(res.size()>0)
					res+=" ";
				res+=digits[digit-1];
			}
			return res;

		}
		string numberToWords(int num) {
			string res;
			if(num==0)
				return "Zero";
			vector<string> unit={"Thousand","Million","Billion","Trillion"};
			int count=0;
			while(num){
				int chunk=num%1000;
				num/=1000;
				if(count>0){
					string chunk_string=digitToWords(chunk);
					if(chunk_string.size()>0){
						if(res.size()>0)
							res=chunk_string+" "+unit[count-1]+" "+res;
						else
							res=chunk_string+" "+unit[count-1];
					}
				}
				else
					res=digitToWords(chunk)+res;
				count++;
			}
			return res;
		}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->numberToWords(12345)<<endl;
}
