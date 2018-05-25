def create_graph(edges, nodes):
    graph = {}
    for i in range(len(nodes)):
        graph[nodes[i]] = []

    for i in range(len(edges)):
        for j in range(2):
            if j == 0:
                if edges[i][j+1] in graph[edges[i][j]]:
                    continue
                else:
                    graph[edges[i][j]].append(edges[i][j+1])
            else:
                if edges[i][j-1] in graph[edges[i][j]]:
                    continue
                else:
                    graph[edges[i][j]].append(edges[i][j-1])

    return graph


def print_graph(graph):
    print graph.items()


def main():
    graph = {}
    print "\t\t\t\t ***** DEMONSTRATING UNDIRECTED GRAPH USING DICTIONARY ******"
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

    graph = create_graph(edges, nodes)
    print_graph(graph)


if __name__ == "__main__":
    main()

