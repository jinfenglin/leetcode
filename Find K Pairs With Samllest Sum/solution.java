c class Solution {
    public List<int[]> kSmallestPairs(int[] nums1, int[] nums2, int k) {
            PriorityQueue<Entry> pQueue = new PriorityQueue<Entry>();
	            List<int[]> res = new ArrayList<int[]> ();
		            if(nums1.length==0 || nums2.length==0 )
			                return res;
					        for(int i=0;i<nums2.length;i++){
						            pQueue.add(new Entry(nums1[0]+nums2[i],0,i));
							            }
								            for(int i=0;i<k && i<nums1.length * nums2.length;i++){
									                Entry entry = pQueue.poll();
											            int[] tmp = new int[2];
												                tmp[0] = nums1[entry.x];
														            tmp[1] = nums2[entry.y];
															                res.add(tmp);
																	            if(entry.x+1<nums1.length)
																		                    pQueue.add(new Entry(nums1[entry.x+1]+nums2[entry.y],entry.x+1,entry.y));
																				            }
																					            return res;
																						        }
																							}
																							class Entry implements Comparable<Entry> {
																							    public int sum,x,y;
																							        public Entry(int sum, int x,int y){
																								        this.sum=sum;
																									        this.x=x;
																										        this.y=y;
																											    }
																											        
																												    @Override
																												        public int compareTo(Entry entry){
																													        return this.sum - entry.sum;
																														    }
																														    }
