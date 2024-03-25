class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def detectCycle(head):
    if not head or not head.next:
        return None
    
    slow = head
    fast = head
    
    # Determine if there's a cycle
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        
        if slow == fast:
            break
    else:
        return None  # No cycle
    
    # Reset one pointer to head and move both at the same speed
    slow = head
    while slow != fast:
        slow = slow.next
        fast = fast.next
    
    return slow

# Test cases
# Example 1
head1 = ListNode(3)
head1.next = ListNode(2)
head1.next.next = ListNode(0)
head1.next.next.next = ListNode(-4)
head1.next.next.next.next = head1.next  # Cycle
print(detectCycle(head1).val)  # Output: 2

# Example 2
head2 = ListNode(1)
head2.next = ListNode(2)
head2.next.next = head2  # Cycle
print(detectCycle(head2).val)  # Output: 1

# Example 3
head3 = ListNode(1)
print(detectCycle(head3))  # Output: None
