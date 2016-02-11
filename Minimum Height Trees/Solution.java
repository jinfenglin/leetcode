public class Solution {
	public List<Integer> findMinHeightTrees(int n, int[][] edges) {
		Map<Integer,List<Integer>> graph=new HashMap<Integer,List<Integer>>();
		List<Integer> res=new ArrayList<Integer>();
		int[] moniter= new int[n];
		for(int i=0;i<edges.length;i++){
			int from=edges[i][0],to=edges[i][1];
			if(!graph.containsKey(from)){
				graph.put(from,new ArrayList<Integer>());
			}
			if(!graph.containsKey(to)){
				graph.put(to,new ArrayList<Integer>());
			}
			graph.get(to).add(from);
			graph.get(from).add(to);
			moniter[from]++;
			moniter[to]++;
		}
		int count=n;
		int[] mask=new int[n];
		while(count>2){
			for(int i=0;i<n;i++){
				if(moniter[i]==1){
				    //System.out.print(i+" ");
					count--;
					moniter[i]=-1;
					List<Integer> wipeList=graph.get(i);
					for(int node:wipeList)
						mask[node]--;
				}
			}
			for(int i=0;i<n;i++){
			    moniter[i]+=mask[i];
			    mask[i]=0;
			}
			//System.out.println("");
		}
		for(int i=0;i<n;i++)
			if(moniter[i]>=0)
				res.add(i);
		return res;
	}

}


