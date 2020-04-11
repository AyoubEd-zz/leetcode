/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middleNode(head *ListNode) *ListNode {
	number_nodes := 0
	node := head

	for node != nil {
		number_nodes++
		node = node.Next
	}

	node = head

	for i := 1; i <= (number_nodes / 2); i++ {
		node = node.Next
	}

	return node
}
