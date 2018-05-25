class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def create_node(self, other_node):
        if self.head is None:
            self.head = Node(other_node)
        else:
            temp = self.head
            while temp.next is not None:
                temp = temp.next
            temp.next = Node(other_node)

    def is_node(self, data):
        if self.head is None:
            return 0
        else:
            temp = self.head
            while temp is not None:
                if temp.data == data:
                    return 1
                temp = temp.next
            return 0


class Graph:
    def __init__(self):
        print "Enter nodes names: ",
        self.nodes = map(str, raw_input().split())
        self.total_nodes = len(self.nodes)
        self.arrayll = []

        self.create_structure()

    def create_structure(self):
        for i in range(self.total_nodes):
            ll = LinkedList()
            self.arrayll.append(ll)

        self.add_edges()

    def add_edges(self):
        print "Time to enter edges: "
        print "Enter node 1 and node 2 to draw an edge between node 1 and 2 and press enter to exit."

        while True:
            node12 = raw_input()
            if node12 == "":
                break
            else:
                node1, node2 = map(str, node12.split())
                if node1 in self.nodes and node2 in self.nodes:
                    node1_index = self.nodes.index(node1)
                    node2_index = self.nodes.index(node2)

                    if not self.arrayll[node1_index].is_node(node2):
                        self.arrayll[node1_index].create_node(node2)
                        self.arrayll[node2_index].create_node(node1)
                    # NOT USING IF CONDITION AGAIN BECAUSE OF UNDIRECTED GRAPH PROPERTY i.e
                    # IF NODE1 DOESN'T HAVE NODE2 IN HIS LL THEN NODE2 WON'T HAVE IT EITHER

                else:
                    print "Node does not exist. Try again"

    def print_graph(self):
        for i in range(len(self.nodes)):
            print "Adjacency list of vertex " + str(self.nodes[i])
            temp = self.arrayll[i].head
            print "head -> ",
            while temp is not None:
                if temp.next is None:
                    print temp.data
                else:
                    print temp.data + " -> ",
                temp = temp.next
            print ""

    def add_new_node(self):
        self.arrayll.append(LinkedList())

        print "Enter new node: "
        new_node = raw_input()
        self.nodes.append(new_node)
        self.add_edges()


def main():
    print " \t\t\t\t\t ***** DEMONSTRATING UNDIRECTED GRAPH USING ADJACENCY LIST "
    graph = Graph()
    graph.print_graph()

    print "Adding new node"
    graph.add_new_node()
    graph.print_graph()


if __name__ == "__main__":
    main()
