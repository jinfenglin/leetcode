class Solution {
	public:
		vector<string> fullJustify(vector<string>& words, int maxWidth) {
			vector<string> vec;
			for(int i=0;i<words.size();){
				int total_len=0;
				int count=0;
				string tmp="";
				while(i<words.size() and total_len+words[i].size()+count<=maxWidth ){
					total_len+=words[i].size();
					count++;
					i++;
				}
				int space= count!=1? (maxWidth-total_len)/(count-1):(maxWidth-total_len);
				int extra= count!=1? maxWidth-total_len-(count-1)*space:0;
				//cout<<count<<" "<<space<<" "<<extra<<endl;
				for(int j=0;j<count;j++){
					tmp+=words[i-count+j];
					if(i==words.size()){
						if(j!=count-1)
							tmp+=" ";
						else{
						    //cout<<"len:"<<maxWidth-total_len-count+1<<endl;
						    if (maxWidth-total_len-count+1)
							    tmp+=string(maxWidth-total_len-count+1,' ');
						}
					}
					else
					{
						if(j!=count-1 or count==1)
						{
							if(extra){
								tmp+=string(space+1,' ');
								extra--;
							}else
								tmp+=string(space,' ');
						}
					}
				}
				vec.push_back(tmp);
			}
			return vec;
		}
};

