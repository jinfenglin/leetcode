#include <iostream>
using namespace std;
int patition(int *array,int start,int end);
void sort(int start,int end,int *array);
/*int patition(int *array,int start,int end){
	//cout<<end<<endl;
	int k=(start+end)/2;
	int pivot=array[k];
	while(start<end){
		while(start<k and array[start]<=pivot)
			start++;
		swap(array[start],array[k]);
		k=start;
		while(end>k and array[end]>=pivot)
			end--;
		swap(array[end],array[k]);
		k=end;
	}
	for(int i=0;i<sizeof(array);i++)
		cout<<array[i]<<" ";
	cout<<endl;

	return end;
}*/

int patition(int *array,int start,int end){
	int pivot=array[end];
	while(start<end){
		while(array[start]<=array[end] and start<end)
			start++;
		swap(array[start],array[end]);
		while(array[end]>=array[start] and start<end)
			end--;
		swap(array[start],array[end]);
	}
	return end;
}
void sort(int start,int end,int *array){
	if(start>=end)
		return;
	int point=patition(array,start,end);
	cout<<point<<endl;
	sort(start,point-1,array);
	sort(point+1,end,array);
}
int main(){
	int array[]={4,3,1,4,5,7,8 };
	for(int i=0;i<sizeof(array)/4;i++)
		cout<<array[i]<<" ";
	cout<<endl;

	sort(0,sizeof(array)/4-1,array);
	for(int i=0;i<sizeof(array)/4;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	
}
