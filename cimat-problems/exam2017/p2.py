def get_mean(prev, x, count):
  return ((count - 1) * prev + x) / (count)

def get_variance(prev, x, count, mean):
  return prev + (x - mean)**2 / count - prev / (count - 1)

def main():
  count = 0
  mean = 0
  variance = 0
  while True:
    n = float(input())
    count += 1
    if n == -1:
      return 0
    if count == 1:
      mean = n
    else:
      n_mean = get_mean(mean, n, count)
      variance = get_variance(variance, n, count, mean)
      mean = n_mean
    print(mean, variance)

if __name__ == '__main__':
  main()

    