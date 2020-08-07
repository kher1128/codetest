def solution(strs, t):
    dp = {}
    for i in range(len(t)):
        dp[i] = float('inf')

    for i in range(len(t)-1, -1, -1):
        for k in range(1,6):
            if t[i:i+k] in strs:
                dp[i] = min(dp.get(i), dp.get(i+k, 0)+1)
    return dp.get(0) if dp.get(0) != float('inf') else -1
