# Runtime

[![Build Status](https://github.com/pooriayousefi/runtime/actions/workflows/ci.yml/badge.svg)](https://github.com/pooriayousefi/runtime/actions/workflows/ci.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++20](https://img.shields.io/badge/C%2B%2B-20-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B20)
[![CMake](https://img.shields.io/badge/CMake-3.20%2B-green.svg)](https://cmake.org/)

A modern C++20 header-only module for high-precision execution time measurement. Runtime provides a simple, efficient, and type-safe way to measure function execution time with automatic return value handling.

## 🚀 Features

- **Header-Only Module**: C++20 module interface for clean imports
- **High Precision**: Uses `std::chrono::high_resolution_clock` for microsecond accuracy
- **Type Safety**: Automatic handling of void and non-void function returns
- **Perfect Forwarding**: Preserves value categories and const-correctness
- **Zero Overhead**: Template-based with compile-time optimizations
- **Cross-Platform**: Works on Linux (g++), macOS (clang++), and Windows (MSVC)

## 🎯 Quick Start

```cpp
import runtime;
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Measure void function
    auto sort_time = runtime([]() {
        std::vector<int> data{5, 2, 8, 1, 9, 3, 7, 4, 6};
        std::sort(data.begin(), data.end());
    });
    
    std::cout << "Sort time: " << sort_time << " seconds" << std::endl;
    
    // Measure function with return value
    auto [result, compute_time] = runtime([](int n) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += i * i;
        }
        return sum;
    }, 1000);
    
    std::cout << "Result: " << result << std::endl;
    std::cout << "Compute time: " << compute_time << " seconds" << std::endl;
    
    return 0;
}
```

## 📚 API Reference

### `runtime` Function Template

For **void functions**: Returns execution time as `double`
For **non-void functions**: Returns `std::pair<ReturnType, double>`

The function automatically detects return types and provides appropriate timing measurement with perfect forwarding.

## 🏗️ Building from Source

```bash
# Clone repository
git clone https://github.com/pooriayousefi/runtime.git
cd runtime

# Build with CMake
cmake --preset=default
cmake --build build/default
```

## 📄 License

This project is licensed under the MIT License - see the [LICENSE.txt](LICENSE.txt) file for details.

---

**Author**: [Pooria Yousefi](https://github.com/pooriayousefi)  
**Repository**: [https://github.com/pooriayousefi/runtime](https://github.com/pooriayousefi/runtime)
