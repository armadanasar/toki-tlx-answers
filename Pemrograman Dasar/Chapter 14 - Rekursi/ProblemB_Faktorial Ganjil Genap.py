#use DP
fact_result = []

#Init DP array
for i in range(5120):
	fact_result.append(0)

fact_result[0] = 1
fact_result[1] = 1

def factorialGG(n):
	if (n <= 0 or n == 1):
		return 1
	if fact_result[n] != 0:
		return fact_result[n]
	if n % 2 == 0:
		fact_result[n] = (n/2) * factorialGG(n-1)
		return fact_result[n]
	else:
		fact_result[n] =  n * factorialGG(n-1)
		return fact_result[n]
		
n = input()
print(int(factorialGG(int(n))))

"""
def factorialGGOld(n):
	if (n <= 0 or n == 1):
		return 1
	if n % 2 == 0:
		return (n/2) * factorialGG(n-1)
	else:
		return n * factorialGG(n-1)
		
for i in range(100):
	if i == 0:
		continue
	print(int(factorialGG(i)))

input()

for i in range(100):
	if i == 0:
		continue
	print(int(factorialGGOld(i)))
"""