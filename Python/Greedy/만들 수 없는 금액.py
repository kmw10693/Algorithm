n = int(input())

nums = list(map(int, input().split()))

nums.sort(reverse=True)

maxResult = sum(nums)
result = 0

for i in range(1, maxResult+1):
    init = i;

    for num in nums:
        if init >= num:
            init -= num
            
    if init > 0:
        result = i;
        break

if(result == 0):
    print(result + 1)
else:
    print(result)

