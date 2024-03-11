n = int(input())

arr = [0] * 100000

arr[1] = 1
arr[2] = 3

for i in range(3, 1002):
    arr[i] = arr[i-1] + 2*arr[i-2]
    
print(arr[n] % 796796)