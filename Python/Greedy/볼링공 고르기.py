n,m = map(int, input().split())
nums = list(map(int, input().split()))

arr = [0] * (m+1)

for i in nums:
    arr[i] += 1


dup = 0
for i in arr:
    if (i > 1):
        dup += 1
        
print(n*(n-1)//2 - dup)
