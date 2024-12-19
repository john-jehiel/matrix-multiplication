import numpy as np
import os

def save_matrix_with_dimensions(filename, matrix):
    m, n = matrix.shape
    with open(filename, "w") as f:
        f.write(f"{m}\n")  
        f.write(f"{n}\n")  
        np.savetxt(f, matrix, fmt='%d')

def generate_matrices(size, folder):
    m, n, p = size - np.random.randint(0, 10), size, size + np.random.randint(0, 10)
    A = np.random.randint(0, 10, (m, n))  
    B = np.random.randint(0, 10, (n, p))  
    C = A @ B

    save_matrix_with_dimensions(f"{folder}/A.txt", A)
    save_matrix_with_dimensions(f"{folder}/B.txt", B)
    save_matrix_with_dimensions(f"{folder}/C.txt", C)

for size, unit in zip(range(700, 701), range(21, 22)):
    folder = f"Unit_test/unit_{unit}"
    os.makedirs(folder, exist_ok=True)  
    generate_matrices(size, folder)
