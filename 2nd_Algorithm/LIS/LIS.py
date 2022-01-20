# DP 방식
length = int(input())
arr = list(map(int, input().split()))
dp = [1 for i in range(length)]

temp = 0

for index in range(len(arr)):
    for subIndex in range(index):
        if arr[index] > arr[subIndex]:
            dp[index] = max(dp[index], dp[subIndex]+1)

print(max(dp))

# Binary 방식
import bisect

length = int(input())
arr = list(map(int, input().split()))

dp = [arr[0]]

for index in range(length):
    if arr[index] > dp[-1]:
        dp.append(arr[index])
    else:
        idx = bisect.bisect_left(dp, arr[index])
        dp[idx] = arr[index]

print(len(dp))
for index in range(len(dp)):
    if index != len(dp)-1:
        print(dp[index], end=' ')
    else:
        print(dp[index])
