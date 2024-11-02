# H3 - LinkedLists

## C++ Performance Comparison: `std::vector` vs. `std::list`

This project compares the performance of `std::vector` and `std::list` in C++ for four basic operations:

- Insert at the beginning
- Insert at the end
- Remove from the beginning
- Remove from the end

Tests are run with increasing numbers of elements (1 million, 2 million, and 3 million) to observe performance differences as the data size grows.

### How to Run

1. **Compile the Code**:

   ```bash
   g++ -std=c++17 -O2 -o test_performance test_performance.cpp
   ```

2. **Execute the Program**:
   ```bash
   ./test_performance
   ```

The program will print the time (in milliseconds) for each operation and display a progress bar.

### Results

| **Operation**             | **Data Structure** | **1M Elements** | **2M Elements** | **3M Elements** |
| ------------------------- | ------------------ | --------------- | --------------- | --------------- |
| **Insert at Beginning**   | Vector             | 32,684 ms       | 131,162 ms      | 323,436 ms      |
|                           | List               | 75 ms           | 135 ms          | 192 ms          |
| **Insert at End**         | Vector             | 17 ms           | 19 ms           | 29 ms           |
|                           | List               | 58 ms           | 112 ms          | 171 ms          |
| **Remove from Beginning** | Vector             | 32,294 ms       | 132,063 ms      | 333,213 ms      |
|                           | List               | 29 ms           | 56 ms           | 90 ms           |
| **Remove from End**       | Vector             | 5 ms            | 9 ms            | 15 ms           |
|                           | List               | 30 ms           | 52 ms           | 91 ms           |

### Summary

- **Vector** performs well for end insertions and removals but is slow at the beginning.
- **List** handles both beginning and end operations efficiently due to its structure.

## Performance Analysis of `for` Loop vs. `Iterator while` Loop with 100,000,000 Elements

#### Summary of Results

| **Run** | **For Loop Time (ms)** | **Iterator Loop Time (ms)** |
| ------- | ---------------------- | --------------------------- |
| 1       | 536                    | 505                         |
| 2       | 565                    | 529                         |
| 3       | 558                    | 505                         |
| 4       | 547                    | 540                         |
| 5       | 541                    | 523                         |

#### Average Times

- **Average For Loop Time**:
  - (536 + 565 + 558 + 547 + 541) / 5 = **549.4 ms**
- **Average Iterator Loop Time**:
  - (505 + 529 + 505 + 540 + 523) / 5 = **520.4 ms**

#### Observations

The **iterator loop** consistently performs better on average (520.4 ms) compared to the **for loop** (549.4 ms) across multiple runs.

### Conclusion

The testing with 100,000,000 elements suggests that **iterators may provide better performance in certain scenarios, particularly with large datasets**.
