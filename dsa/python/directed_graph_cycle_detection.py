from collections import defaultdict


class Graph:
	def __init__(self, v):
		self.graph = defaultdict(list)
		self.v = v

	def print_graph(self):
		for n1, n2 in self.graph.items():
			print n1, n2

	def add_edge(self, n1, n2):
		self.graph[n1].append(n2)

	def is_cyclic(self):
		visited = [False] * self.v
		recur = [False] * self.v

		for node in range(self.v):
			if not visited[node] and len(self.graph[node]) > 0:
				if self.is_cyclic_util(node, visited, recur):
					print "Cycle is present"
					return

		print "No cycles present"

	def is_cyclic_util(self, node, visited, recur):
		visited[node] = True
		recur[node] = True

		for i in self.graph[node]:
			if not visited[i]:
				if len(self.graph[i]) > 0:
					if self.is_cyclic_util(i, visited, recur):
						return True
			else:
				if recur[i]:
					return True
		recur[node] = False
		return False

print "Enter number of vertices "
v = input()
graph = Graph(v)
graph.add_edge(2, 0)
graph.add_edge(2, 3)
graph.add_edge(0, 2)
graph.add_edge(0, 1)
graph.add_edge(1, 2)
graph.add_edge(3, 3)

graph.print_graph()

graph.is_cyclic()