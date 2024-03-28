n = int(input())
nums = list(map(int, input().split()))

nums.sort(reverse = True)

ans = 1
t = nums[0]

for i in nums:
    if t > 0:
        t = t-1
        continue
    else:
        t = i
        ans += 1
        t = t-1
    

print(ans)