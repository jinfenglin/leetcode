public class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
            if(x+y<z)
	                return false;
			        return z==0 || z%gcd(x,y) == 0;
				    }
				        public int gcd(int x ,int y){
					        if(y==0)
						            return x;
							            else
								                return gcd(y,x%y);
										    }
										    }
