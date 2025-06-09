def is_point_in_polygon(poly_x, poly_y, x, y):
  n = len(poly_x)
  inside = False
  j = n - 1

  for i in range(n):
    xi, yi = poly_x[i], poly_y[i]
    xj, yj = poly_x[j], poly_y[j]
    if yi == yj != y:
      j = i
      continue
    if ((yi > y) != (yj > y)) and (x < (y - yi) * (xj - xi) / (yj - yi) + xi):
      inside = not inside
    j = i

  return inside

def main():
  pol_ver_x = [0, 0, 100, 100]
  pol_ver_y = [0, 100, 100, 0]
  point_x = 100
  point_y = 50
  print(is_point_in_polygon(pol_ver_x, pol_ver_y, point_x, point_y))


if "__main__" == __name__:
  main()