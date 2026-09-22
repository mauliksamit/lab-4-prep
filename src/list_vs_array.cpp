#include <cstddef>  // size_t

#include "timer.h"
#include <list>
#include <vector>
#include <random>
#include <iostream>
constexpr size_t SIZE = 16000000;


int main() {
    // test here...
    std::vector<uint64_t> random_vector;
    std::vector<uint64_t> random_vector_reserve;
    random_vector_reserve.reserve(16000000);
    std::list<uint64_t> random_list;
    std::mt19937_64 rng(0);
    uint64_t vector_sum = 0;
    uint64_t list_sum = 0;

    Timer timing;

    for (int i = 0; i < 16000000; i++)
    {
        random_vector.push_back(rng());
    };

    auto vector_population_time = timing.click<Timer::Micros>();

    rng.seed(0);
    timing.restart();

    for (int i = 0; i < 16000000; i++)
    {
        random_vector_reserve.push_back(rng());
    };

    auto vector_reserve_population_time = timing.click<Timer::Micros>();

    rng.seed(0);
    timing.restart();

    for (int i = 0; i < 16000000; i++)
    {
        random_list.push_back(rng());
    };

    auto list_population_time = timing.click<Timer::Micros>();

    timing.restart();

    for (const auto& num: random_vector)
    {
        vector_sum += num;
    }

    auto vector_sum_time = timing.click<Timer::Micros>();
    vector_sum = 0;
    timing.restart();

    for (const auto& num: random_vector_reserve)
    {
        vector_sum += num;
    }
    auto vector_reserve_sum_time = timing.click<Timer::Micros>();

    timing.restart();

    for (const auto& num: random_list)
    {
        list_sum += num;
    }
    auto list_sum_time = timing.click<Timer::Micros>();

    std::cout<< "Vector Population Time: " << vector_population_time << std::endl;
    std::cout<< "Vector Reserved Population Time: " << vector_reserve_population_time << std::endl;
    std::cout<< "List Population Time: " << list_population_time << std::endl;
    std::cout<< "Vector Sum: " << vector_sum <<", Vector Sum Time: " << vector_sum_time << std::endl;
    std::cout<<  "Vector Reserved Sum: " << vector_sum<< ", Vector Reserved Sum Time: " << vector_reserve_sum_time << std::endl;
    std::cout<<  "List Sum: " << list_sum << ", List Time: " << list_sum_time << std::endl;





    return 0;
}
