import itertools

string = raw_input()
temp = []
for i in range(len(string)):
	temp += list(itertools.combinations(string, i+1))

print temp

subsets = []
for i in range(len(temp)):
	temp2 = []
	for j in range(len(temp[i])):
		temp2.append(temp[i][j])
	subsets.append(''.join(temp2))

print subsets

