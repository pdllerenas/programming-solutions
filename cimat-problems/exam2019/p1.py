def reverseBase10(N):
  return int(str(N)[::-1])

def reverseBase10v2(N):
  res = 0
  while N > 0:
    res = res * 10 + N % 10
    N //= 10
  return res

def main():
  print(reverseBase10(12345))
  print(reverseBase10v2(12345))

if __name__ == "__main__": main()