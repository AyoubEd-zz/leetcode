## Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

- - -

The main thing we should know know in order to solve this problem is how to build a linked list. Notice how we kept a pointer to the fake head of the linked list that we returned, and we kept building a new ListNode each each time, and linking it to our previous one.
