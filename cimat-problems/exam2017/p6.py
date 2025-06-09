def all_permutations(seq):
    if len(seq) <= 1:
        return [seq]
    perms = []
    for i in range(len(seq)):
        rest = seq[:i] + seq[i+1:]
        for p in all_permutations(rest):
            perms.append([seq[i]] + p)
    return perms

def minImbalance(C, S, weights):
  min_s = float('inf')
  AM = sum(weights) / C

  for perm in all_permutations(weights):
    s = 0
    for i in range(0, len(perm), 2):
      if i < len(perm) - 1:
        s += abs(perm[i] + perm[i+1] - AM)
      else:
        s += abs(perm[i] - AM)
    if s < min_s:
      min_s = s
  return min_s

def minImbalanceEfficient(C, S, weights):
  if S > 2*C:
    raise ValueError("S must be less than 2C.")
  s = 0
  AM = sum(weights) / C
  print(AM)
  if S < C:
    for i in range(len(weights)):
      s += abs(weights[i] - AM)
    return s
  elif S == 2*C:
    for i in range(len(weights)):
      s += abs(weights[-1-i] + weights[i] - AM)
    return s
  else:
    d = S % C
    w = sorted(weights)
    for i in range(C):
        print(w)
        if i < C - d:
          s += abs(w.pop() - AM)
        else:
          s += abs(w.pop() + w.pop(0) - AM)
    return s
           


def main():
  weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
  C, S = 3, len(weights)

  print(minImbalanceEfficient(C, S, weights))

if __name__ == '__main__':
  main()