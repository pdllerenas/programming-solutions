def transpose(A):
    return [[A[j][i] for j in range(len(A))] for i in range(len(A[0]))]

def is_symmetric(A, tol=1e-8):
    n = len(A)
    for i in range(n):
        for j in range(i+1, n):
            if abs(A[i][j] - A[j][i]) > tol:
                return False
    return True

def cholesky_decomposition(A):
    n = len(A)
    
    # Symmetry check
    if not is_symmetric(A):
        raise ValueError("Matrix is not symmetric.")

    L = [[0] * n for _ in range(n)]

    for j in range(n):
        for i in range(j, n):
            if i == j:
                val = A[i][j] - sum(L[j][k] ** 2 for k in range(j))
                if val <= 0:
                    raise ValueError("Matrix is not positive definite.")
                L[j][j] = val ** 0.5
            else:
                val = A[i][j] - sum(L[i][k] * L[j][k] for k in range(j))
                L[i][j] = val / L[j][j]

    return L, transpose(L)

A = [[4., 2.], [2., 3.]]

try:
    L, U = cholesky_decomposition(A)
    print("L:")
    for row in L:
        print(row)

    print("U:")
    for row in U:
        print(row)
except ValueError as e:
    print("Decomposition failed:", e)
