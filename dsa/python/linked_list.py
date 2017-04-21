class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def add_node(self, data):
        x = Node(data)
        return x

    def print_list(self, x):
        while (x):
            print x.data
            x = x.next


l = LinkedList()
l.head = Node(1)
l.head.next = l.add_node(2)
third_node = Node(3)
l.head.next.next = third_node

l.print_list(l.head)
