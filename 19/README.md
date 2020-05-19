## Remove Nth Node From End of List

Given a linked list, remove the n-th node from the end of list and return its head.

- - -

We create two pointers such that the distance between the two is N. This way when we move the second pointer to the last position of the linked list, the first pointer is going to point at the N-1th node and this way we can change it's next node to the N+1th one.<br><br>
There's a little issue here. In the case where we have to remove the first element of the linked list, we are going to encounter a runtime error if we try to distance the two pointers by N. We solve this by creating a dummy Linked List that will have N+1 element with the first element(arbitrary) pointing at the first element of the original Linked List.
