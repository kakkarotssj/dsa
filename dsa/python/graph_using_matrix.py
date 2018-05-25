def create_graph(no_of_nodes, edges, nodes):
    total_edges = len(edges)
    graph = [[0 for i in range(no_of_nodes)] for j in range(no_of_nodes)]
    for i in range(total_edges):
        edge = edges[i]
        node1, node2 = edge[0], edge[1]
        row = nodes.index(node1)
        col = nodes.index(node2)
        graph[row][col], graph[col][row] = 1, 1

    return graph


def print_graph(graph, no_of_nodes, nodes):
    for i in range(no_of_nodes+1):
        for j in range(no_of_nodes+1):
            if i == 0:
                if j == 0:
                    print " ",
                else:
                    print nodes[j-1],
            else:
                if j == 0:
                    print nodes[i-1],
                else:
                    print graph[i-1][j-1],
        print ""


def main():
    print "\t\t\t\t ***** DEMONSTRATING UNDIRECTED GRAPH USING ADJACENCY MATRIX ******"
    print "Enter nodes name: ",
    nodes = map(str, raw_input().split())

    print "Time to enter edges: "
    print "Enter node 1 and node 2 to draw an edge between node 1 and 2 and press enter to exit. "
    edges = []
    no_of_nodes = len(nodes)
    while True:
        node12 = raw_input()
        if node12 == "":
            break
        else:
            node1, node2 = map(str, node12.split())
            if node1 in nodes and node2 in nodes:
                edges.append([node1, node2])
            else:
                print "Node does not exist. Try again"

    graph = create_graph(no_of_nodes, edges, nodes)
    print_graph(graph, no_of_nodes, nodes)


if __name__ == "__main__":
    main()

