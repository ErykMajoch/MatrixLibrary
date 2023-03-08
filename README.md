# A C++ 23 Matrix Library


<!--  

Transposition Submatrix

Square Matrices:
 - Diagonal Matrix
 - Lower Triangular Matrix
 - Upper Triangular Matrix

Inverse Matrices
 - Identity Matrix
 - Determinant


-->


## Roadmap
### Scalar Operations
| Addition | Subtraction | Multiplication | Division |
|:--------:|:-----------:|:--------------:|:--------:|
|   `+` ✅  |    `-` ✅    |      `*` ✅     |   `/` ✅  |
|  `+=` ✅  |    `-=` ✅   |     `*=` ✅     |  `/=` ✅  |

### Matrix Operations
| Addition | Subtraction | Multiplication |
|:--------:|:-----------:|:--------------:|
|`+` :construction:|`-` :construction:|`*` ✅|
|  `+=` :x:  |    `-=` :x:   |     `*=` :x:     |

### Matrix  Operations
| Identity Matrix | Determinant | Cofactor Matrix | Adjucate Matrix |
|:---------------:|:-----------:|:---------------:|:---------------:|
|       ✅       |     ✅     |       :x:       |       :x:       |

| Inverse |Transpose|
|:---------------:|:---------------:|
|       ✅       |       ✅       |
<!-- https://byjus.com/maths/adjoint-of-a-matrix/ -->

### Additional Utilities
|        Print       |
|:------------------:|
| ✅ |


## Building the project
These instructions assume that you're using C++ version 23 as well as CMake version >=3.1
```bash
# Clone the repository
git clone https://github.com/ErykMajoch/MatrixLibrary.git
cd MatrixLibrary

# Make a build directory
mkdir build && cd build

# Build and run the project
cmake .. && make
./MatrixLibrary
```
