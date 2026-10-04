#include<chrono>
#include<cstdint>
#include<iostream>

int main() {
       using clock = std::chrono::steady_clock;
       constexpr std::uint64_t N = 10000000;
       
       std::uint64_t sink = 0;
    
       auto start = clock::now();
       for (std::uint64_t i = 0; i < N; ++i) {
        sink += clock::now().time_since_epoch().count();
    }
    auto end = clock::now();

    double total_ns = std::chrono::duration<double, std::nano>(end - start).count();

    std::cout << "calls:        " << N << "\n";
    std::cout << "avg per call: " << total_ns / N << " ns\n";
    std::cout << "(sink: " << sink << ")\n";
    return 0;
}
