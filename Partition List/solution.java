tion for singly-linked list.
 * public class ListNode {
  *     int val;
   *     ListNode next;
    *     ListNode(int x) { val = x; }
     * }
      */
      public class Solution {
          public ListNode partition(ListNode head, int x) {
	          ListNode lessHead= new ListNode(0);
		          ListNode greaterHead= new ListNode(0);
			          ListNode lessPtr=lessHead;
				          ListNode greaterPtr = greaterHead;
					          while(head!=null){
						              if(head.val<x){
							                      lessPtr.next=head;
									                      head=head.next;
											                      lessPtr=lessPtr.next;
													                      lessPtr.next=null;
															                  }else{
																	                  greaterPtr.next=head;
																			                  head=head.next;
																					                  greaterPtr=greaterPtr.next;
																							                  greaterPtr.next=null;
																									              }
																										              }
																											              lessPtr.next=greaterHead.next;
																												              return lessHead.next;
																													          }
																														  }
