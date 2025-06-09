def f(x):
  return (x + 1) % 8

def cycle(f):
  x = 1
  vals = [x] 
  while f(x) not in vals:
    vals.append(f(x))
    x = f(x)
  return (vals.index(f(x)), len(vals) - vals.index(f(x)))

def main():
  print(cycle(f))

if __name__ == "__main__":
  main()  