import random

def radar_pos(p, r):
  if p[1]**2 > r**2:
    raise ValueError("Point is out of range, no solution can be found.")
  return (p[0] - (r**2 - p[1]**2)**0.5, p[0] + (r**2 - p[1]**2)**0.5)

def cover(P, r):
  # Assume P[0] is minimal
  P = sorted(P, key=lambda x: x[0])
  print(P)
  try:
    radar = radar_pos(P[0], r)
    print(radar)
    count = 1
    for island in P:
      new_radar = radar_pos(island, r)
      print(new_radar)
      if radar[1] >= new_radar[0]:
        continue
      else:
        radar = new_radar
        count += 1

    return count

  except ValueError:
    return -1


def main():
  p = (1,4)
  r = 6
  num_points = 100,000
  x_range = (-1000, 1000)
  y_range = (0, 6)

  P = [(random.uniform(*x_range), random.uniform(*y_range)) for _ in range(num_points)]
  print(cover(P, r))

if __name__ == "__main__":
  main()