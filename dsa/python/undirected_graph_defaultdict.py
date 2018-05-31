from collections import defaultdict

class Graph:
	def __init__(self):
		self.graph = defaultdict(list)

	def addEdge(self, n1, n2):
		if n2 not in self.graph[n1]:
			self.graph[n1].append(n2)
			self.graph[n2].append(n1)
	
	def print_graph(self):
		for n1, n2 in self.graph.iteritems():
			print n1, n2

	def remove_edge(self, n1, n2):
		self.graph[n1].remove(n2)
		self.graph[n2].remove(n1)


graph = Graph()
graph.addEdge(0, 1)
graph.addEdge(0, 4)
graph.addEdge(1, 0)
graph.addEdge(1, 2)
graph.addEdge(1, 3)
graph.addEdge(1, 4)
graph.addEdge(2 ,1)
graph.addEdge(2, 3)
graph.addEdge(3, 1)
graph.addEdge(3, 1)
graph.addEdge(3, 4)
graph.addEdge(40, 0)
graph.addEdge(40, 1)
graph.addEdge(40, 3)

graph.print_graph()

print "Removing an edge between 0 and 40"
graph.remove_edge(0, 40)
graph.print_graph()

print "Adding an edge between 2 and 40"
graph.addEdge(2, 40)
graph.print_graph()