input_str = input()
queries = input_str.split(" ")


#print(queries[0] + "\n" + queries[1])
result = queries[0]

while queries[1] in result:
	result = result.replace(queries[1], "")
	#print(result + '\n')
	#print(input_str + '\n')

print(result)