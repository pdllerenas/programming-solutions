def zMatrix(n):
  return [[j-i for j in range(n)] for i in range(n)]

def main():
  print(zMatrix(7))

if __name__ == '__main__':
  main()