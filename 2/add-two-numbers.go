/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{0, nil}
	res_list := head

	val, dig := 0, 0

	for l1 != nil || l2 != nil || val != 0 {
		if l1 != nil {
			val += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			val += l2.Val
			l2 = l2.Next
		}

		dig = val % 10
		val = val / 10

		res_list.Next = &ListNode{dig, nil}
		res_list = res_list.Next
	}

	return head.Next
}
