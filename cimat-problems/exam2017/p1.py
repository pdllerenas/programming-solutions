def compress(A, n, m):
  res = []
  for i in range(0, n, 2):
    means = []
    for j in range(0, m, 2):
      if i + 1 < n and j + 1 < n:
        means.append((A[i][j] + A[i+1][j+1]) / 2)
      else:
        means.append(A[i][j])
    res.append(means)
  return res

def compression(A, n, m, c):
  res = A
  n_dim = n
  m_dim = m
  for _ in range(c):
    res = compress(A, n_dim, m_dim)
    n_dim = len(res)
    m_dim = len(res[0])
  return res


def main():
  A = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
  print(compression(A, 4, 4, 1))

if __name__ == "__main__":
  main()