s = input()
result = 0

def check(arr):
    init = arr[0]
    for i in range(1, len(arr)):
        if (init != arr[i]):
          return False
    return True
    
def make(arr, num):

    result = 0
    for i in range(0, len(arr)):
    
      if(i < len(arr)-1):
          if(arr[i] == num and arr[i+1] != arr[i]):
            result += 1
      else:
          if(arr[i] == num):
              result += 1
    return result
    
if(check(s)):
    print(0)
else:
    t0 = make(s, str(0))
    t1 = make(s, str(1))
    
    print(min(t0, t1))
