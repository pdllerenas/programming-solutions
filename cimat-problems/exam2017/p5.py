def eigenvalue(A, x):
  Ax = []
  for row in A:
    Ax.append(sum(row[i] * x[i] for i in range(len(x))))

  lam = 0
  for y, z in zip(Ax, x):
    if z == 0 and y != 0:
      return 0
    elif lam == 0:
      lam = y / z
    elif lam != y / z:
      return 0

  return lam

def main():
  print(eigenvalue([[5, -3], [6, -4]], [1, 2]))

if __name__ == "__main__":
  main()