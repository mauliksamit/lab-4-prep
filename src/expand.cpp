#include <cassert>  // assert
#include <cstddef>  // size_t
#include <cstdint>  // uint64_t, uint32_t

// Expands the binary representation of input by a factor of scale.
// e.g., expand(0b1111ull, 3) == 0b001001001001
uint64_t expand(uint64_t input, uint32_t scale) {

    assert(scale >= 1 && "Scale should be >=1");
    uint64_t output = 0;
    uint32_t shift_amount = 0;

    while (input > 0 && shift_amount< 64)
    {
        uint64_t current_bit = input & 1ULL;
        output |= (current_bit<< shift_amount);
        input >>= 1;
        shift_amount += scale;
    }

    return output;
}

int main() {
    assert(expand(0b1111ULL, 3) == 0b001001001001ULL);
    assert(expand(0b0101ULL, 2) == 0b00010001ULL);
    return 0;
}