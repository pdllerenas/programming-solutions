def rotate(M):
  r = len(M)
  c = len(M[0])
  res = [[0 for _ in range(r)] for _ in range(c)]
  for i in range(r):
    for j in range(c):
      res[j][c - 1 - i] = M[i][j]
  return res

def pretty(M):
  for i in range(len(M)):
    print(M[i])

def main():
  
  M = [[10, 50, 70, 0], [200, 200, 170, 200], [0, 45, 120, 156], [2, 78, 89, 20]]
  pretty(M)
  pretty(rotate(M))

if __name__ == "__main__": main()