import java.util.*;
class UndirectedGraphNode {
	int label;
	List<UndirectedGraphNode> neighbors;
	UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
};
public class Solution {
	public UndirectedGraphNode cloneGraph(UndirectedGraphNode node){
		if(node==null)
			return null;
		Queue<UndirectedGraphNode> myq= new LinkedList<UndirectedGraphNode>();
		Map<UndirectedGraphNode,UndirectedGraphNode> mymap=new HashMap<UndirectedGraphNode,UndirectedGraphNode>();
		myq.add(node);
		mymap.put(node, new UndirectedGraphNode(node.label));
		while(!myq.isEmpty()){
			UndirectedGraphNode head=myq.remove();
			UndirectedGraphNode cur_node= mymap.get(head);
			for(UndirectedGraphNode nb:head.neighbors){
				if(mymap.containsKey(nb)){
					cur_node.neighbors.add(mymap.get(nb));
				}else{
					myq.add(nb);
					UndirectedGraphNode new_node= new UndirectedGraphNode(nb.label);
					mymap.put(nb,new_node);
					cur_node.neighbors.add(new_node);
				}
			}

		}
		return mymap.get(node);	
	}
	/*public static void main(String [] args) throws Exception {
		UndirectedGraphNode n1= new UndirectedGraphNode(1);
		UndirectedGraphNode n2= new UndirectedGraphNode(2);
		UndirectedGraphNode n3= new UndirectedGraphNode(3);

		n1.neighbors.add(n2);
		n2.neighbors.add(n3);
		n3.neighbors.add(n3);
		Solution sol= new Solution();
		System.out.println(sol.cloneGraph(n1).neighbors.size());
	}*/
};
