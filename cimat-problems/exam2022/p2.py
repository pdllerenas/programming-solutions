
def kadane(v):
  currSum = 0
  maxSum = float('-inf')
  for i in range(len(v)):
    currSum += v[i]
    if (currSum > maxSum):
        maxSum = currSum
    if (currSum < 0):
        currSum = 0
  return maxSum

def maxSubmatrixSum(A):
  r = len(A)
  c = len(A[0])
  prefix = [[0 for _ in range(c)] 
            for _ in range(r)]
  for i in range(r):
    for j in range(c):
      if (j == 0):
        prefix[i][j] = A[i][j]
      else:
        prefix[i][j] = A[i][j] + prefix[i][j - 1]

  maxSum = float('-inf')
  
  for i in range(c):
    for j in range(i, c):
      v = []
      for k in range(r):
        el = 0
        if (i == 0):
          el = prefix[k][j]
        else:
          el = prefix[k][j] - prefix[k][i - 1]
        v.append(el)
      maxSum = max(maxSum, kadane(v))
  
  print(maxSum)

matrix = [ [ 1, -10, 3 ],
           [ -1, 1, 4 ],
           [ 0, 2, 7 ] ]
           
maxSubmatrixSum(matrix)