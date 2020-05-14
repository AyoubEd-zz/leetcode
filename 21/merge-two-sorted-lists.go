/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{0, nil}
	l := head

	for l1 != nil || l2 != nil {
		l.Next = &ListNode{0, nil}
		l = l.Next
		val := 0
		if l2 == nil || (l1 != nil && l1.Val < l2.Val) {
			val = l1.Val
			l1 = l1.Next
		} else {
			val = l2.Val
			l2 = l2.Next
		}
		l.Val = val
	}

	return head.Next
}
