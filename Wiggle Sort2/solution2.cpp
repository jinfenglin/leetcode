#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int partition(vector<int>& nums,int left,int right){
			int pivot=right;
			int storeIndex=left;
			for(int i=left;i<right;i++){
				if(nums[i]<nums[pivot]){
					swap(nums,storeIndex,i);
					storeIndex+=1;
				}
			}
			swap(nums,storeIndex,pivot);
			return storeIndex;
		}
		void swap(vector<int>& nums,int indexA,int indexB){
			int tmp=nums[indexA];
			nums[indexA]=nums[indexB];
			nums[indexB]=tmp;
		}
		int quickSelect(vector<int>& nums,int kth,int left,int right){
			int point=partition(nums,left,right);
			if(kth>point)
				return quickSelect(nums,kth,point+1,right);
			else if(kth<point)
				return quickSelect(nums,kth,left,point-1);
			else
				return nums[kth];
		}
		float findMedia(vector<int> &nums){
			if(nums.size()%2){
				int mediaIndex=nums.size()/2;
				return quickSelect(nums,mediaIndex,0,nums.size()-1);
			}else{
				int mediaIndex=nums.size()/2;
				return (quickSelect(nums,mediaIndex,0,nums.size()-1)+quickSelect(nums,mediaIndex-1,0,nums.size()-1))/2.0;
			}
		}
		void wiggleSort(vector<int>& nums) {
			float media=findMedia(nums);
			vector<int> small,large;
			int mc=0;
			for(int i=0;i<nums.size();i++){
				int num=nums[i];
				if(num<media){
					small.push_back(num);
				}else if(num>media){
					large.push_back(num);
				}else{
					mc++;
				}
			}
			int dif=large.size()-small.size();
			mc-=abs(dif);
			vector<int> tmp;
			while(dif<0){
				large.push_back(int(media));
				dif++;
			}
			while(dif>0){
				//small.insert(small.begin(),int(media));
				tmp.push_back(int(media));
				dif--;
				
			}
			while(mc){
				//small.insert(small.begin(),int(media));
				tmp.push_back(int(media));
				mc--;
				if(mc){
					large.push_back(int(media));
					mc--;
				}
				
				
			}
			small.insert(small.begin(),tmp.begin(),tmp.end());
			/*for(int num:small)
				cout<<num;
			cout<<endl;
			for(int num:large)
				cout<<num;
			cout<<endl;*/
			for(int i=0;i<nums.size();i++){
				if(i%2==0)
					nums[i]=small[i/2];
				else
					nums[i]=large[i/2];	
			}
		
		}
};
int main(){
	vector<int> nums={1,1,1,1,2,2,2};
	Solution *sol=new Solution;
	//cout<<sol->quickSelect(nums,nums.size()/2,0,nums.size()-1)<<endl;
	sol->wiggleSort(nums);
	for(int num:nums)
		cout<<num<<endl;
}
