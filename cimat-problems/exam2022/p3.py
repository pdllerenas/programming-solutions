def occurrences(s, l):
  c = 0
  for i in range(len(l)):
    k = i
    for j in range(len(s)):
      if k == len(l):
        break
      if l[k] == s[j]:
        k += 1
        if j == len(s) - 1:
          c += 1
      else:
        break
  return c

L = "TATATOTA"
S = "ATA"

print(occurrences(S, L))
