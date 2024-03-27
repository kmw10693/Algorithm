from collections import deque
import copy

v = int(input())

# 진입 차수
indegree = [0] * (v+1)

# 각 노드에 연결된 간선 정보를 담기 위한 연결 리스트 초기화
graph = [[] for i in range(v+1)]

# 각 강의 시간을 0으로 초기화
time = [0] * (v+1)

for i in range(1, v+1):
    nums = list(map(int, input().split()))
    time[i] = nums[0]
    
    for j in nums[1:-1]:
        graph[j].append(i)
        indegree[i] +=1
        
def topology_sort():
    result = copy.deepcopy(time)
    q = deque()
    
    for i in range(1, v+1):
        if indegree[i] == 0:
            q.append(i)
            
    while q:
        now = q.popleft()
        
        for i in graph[now]:
            result[i] = result[now] + time[i]
            indegree[i] -=1
            
            if indegree[i] == 0:
                q.append(i)
                
    for i in range(1, v+1):
        print(result[i])
        
        
topology_sort()
    
    