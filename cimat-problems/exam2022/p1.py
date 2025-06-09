def mediana(arr):
  arr.sort()
  N = len(arr)
  if len(arr) % 2 == 0:
    return (arr[N // 2] + arr[N // 2 - 1]) / 2
  else:
    return arr[N // 2]