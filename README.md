# 🚀 Parallel TSP Solver

**A high-performance multi-threaded Traveling Salesman Problem solver implemented in C++**

## 📋 Description

This project implements an efficient solution to the classic Traveling Salesman Problem using parallel computing techniques. The solver uses multiple threads to explore different starting cities simultaneously, finding the optimal tour that visits all cities exactly once with minimum total distance.

## ✨ Features

- **Multi-threaded Architecture**: Leverages parallel processing to speed up computation
- **Optimal Solution Finding**: Explores all possible permutations to guarantee the best route
- **Thread-Safe Operations**: Uses mutex locks to prevent race conditions
- **Dynamic Distance Matrix**: Configurable city distances for different problem instances
- **Performance Monitoring**: Tracks and displays the best tour cost and path
- **Clean Output Formatting**: Easy-to-read results with visual tour representation

## 🏗️ Technical Implementation

### Core Components

- **Distance Matrix**: Represents travel costs between all city pairs
- **Permutation Generator**: Creates all possible tour combinations
- **Thread Pool**: Distributes workload across multiple CPU cores
- **Cost Calculator**: Computes total travel distance for each tour
- **Result Aggregation**: Thread-safe collection of optimal solutions

### Algorithm Approach

1. **Initialization**: Set up distance matrix and create thread pool
2. **Work Distribution**: Assign each thread a different starting city
3. **Parallel Exploration**: Generate and evaluate all permutations concurrently
4. **Cost Optimization**: Track minimum cost tour across all threads
5. **Result Compilation**: Aggregate best solution from all threads

## 🚀 Getting Started

### Prerequisites

- C++11 or later compiler
- Threading support (pthread)
- Standard Template Library (STL)

### Compilation

```bash
g++ -std=c++11 -pthread ex.cpp -o tsp_solver
```

### Execution

```bash
./tsp_solver
```

## 📊 Sample Output

```
Distance Matrix:
     0  1  2  3
0 |  0  5 40 11 
1 |  5  0  9  6 
2 | 40  9  0  8 
3 | 11  6  8  0 

Best tour cost: 28
Best path: 0 → 1 → 3 → 2 → 0
```

## 🔧 Configuration

Modify the following constants in `ex.cpp` to customize your problem:

- **N**: Number of cities in the problem
- **D[N][N]**: Distance matrix between cities

```cpp
const unsigned int N = 4;
const unsigned int D[N][N] = {
    {0, 5, 40, 11}, 
    {5, 0, 9, 6}, 
    {40, 9, 0, 8}, 
    {11, 6, 8, 0}
};
```

## 📈 Performance Characteristics

- **Time Complexity**: O(n!) for complete exploration
- **Space Complexity**: O(n) per thread
- **Scalability**: Near-linear speedup with number of CPU cores
- **Optimal for**: Small to medium-sized TSP instances (≤ 10 cities)

## 🎯 Use Cases

- **Educational**: Understanding parallel algorithm design
- **Benchmarking**: Testing multi-core performance
- **Research**: Baseline for TSP algorithm comparisons
- **Learning**: Practical threading and synchronization examples



## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to check the issues page or submit a pull request.

---

