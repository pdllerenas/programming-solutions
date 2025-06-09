PI = 3.14159

def sin(x, n):
  x_squared = x * x
  factorial = 1
  curr_x = x
  sum = x
  sign = 1
  for i in range(1, n):
    sign *= -1
    curr_x *= x_squared
    factorial *= (2*i + 1) * (2*i)
    sum += sign * curr_x / factorial
  return sum

def main():
  print(sin(PI, 20))
  print(sin(PI, 100))
  print(sin(PI, 1000))


if __name__ == "__main__":
  main()