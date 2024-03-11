n = int(input())
k = list(map(int, input().split()))

for i in range(2, n):
    k[i] = max(k[i-2] + k[i], k[i-1]);
    
print(k[n-1])



