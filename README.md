# A C++ 23 Matrix Library

## Project Roadmap
### Scalar Operations
| Addition | Subtraction | Multiplication | Division |
|:--------:|:-----------:|:--------------:|:--------:|
|   `+` :heavy_check_mark:  |    `-` :heavy_check_mark:    |      `*` :heavy_check_mark:     |   `/` :heavy_check_mark:  |
|  `+=` :heavy_check_mark:  |    `-=` :heavy_check_mark:   |     `*=` :heavy_check_mark:     |  `/=` :heavy_check_mark:  |

### Matrix Operations
| Addition | Subtraction | Multiplication | Division |
|:--------:|:-----------:|:--------------:|:--------:|
|   `+` :construction:  |    `-` :construction:    |      `*` <span style="color:#00FF00">:heavy_check_mark:</span>     |   `/` :x:  |
|  `+=` :x:  |    `-=` :x:   |     `*=` :x:     |  `/=` :x:  |

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