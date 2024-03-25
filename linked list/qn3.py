class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverseLinkedList(head):
    prev_node = None
    current_node = head
    
    while current_node:
        next_node = current_node.next  # Store the next node
        current_node.next = prev_node  # Reverse the pointer
        
        # Move prev_node and current_node one step forward
        prev_node = current_node
        current_node = next_node
    
    # At the end of the loop, prev_node will point to the new head
    return prev_node

# Helper function to print the linked list
def printLinkedList(head):
    current = head
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("None")

# Test
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)

print("Original list:")
printLinkedList(head)

reversed_head = reverseLinkedList(head)
print("Reversed list:")
printLinkedList(reversed_head)
