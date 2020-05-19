/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	dum := &ListNode{0, head}
	first := dum
	second := dum

	for i := 0; i <= n; i++ {
		second = second.Next
	}

	for second != nil {
		first = first.Next
		second = second.Next
	}

	first.Next = first.Next.Next
	return dum.Next
}
