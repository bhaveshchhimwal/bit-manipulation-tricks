#include <bits/stdc++.h>
using namespace std;

// Swap two integers using XOR (works when a and b are different memory locations)
void swapXOR(int &a, int &b) {
    if (&a == &b) return; // swapping same variable would zero it out with XOR trick
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

// XOR of all numbers from 1 to n (works for n >= 0)
long long xorUptoN(long long n) {
    switch (n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        default: return 0;
    }
}
// XOR of numbers from L to R inclusive
long long xorRange(long long L, long long R) {
    if (L > R) return 0; // empty range
    return xorUptoN(R) ^ xorUptoN(L - 1);
}

// Check if the i-th bit (0-indexed) is set in n
bool isIthBitSet(long long n, int i) {
    if (i < 0 || i >= 63) return false; // avoid undefined behavior for too-large shifts
    long long mask = 1LL << i;
    return (n & mask) != 0;
}

// Return value with i-th bit set
long long setIthBit(long long n, int i) {
    if (i < 0 || i >= 63) return n;
    long long mask = 1LL << i;
    return n | mask;
}

// Return value with i-th bit cleared
long long clearIthBit(long long n, int i) {
    if (i < 0 || i >= 63) return n;
    long long mask = ~(1LL << i);
    return n & mask;
}

// Toggle i-th bit
long long toggleIthBit(long long n, int i) {
    if (i < 0 || i >= 63) return n;
    long long mask = 1LL << i;
    return n ^ mask;
}

// Remove the last (lowest) set bit and return new value
long long removeLastSetBit(long long n) {
    return n & (n - 1);
}

// Check whether n is a power of two (positive powers only)
bool isPowerOfTwo(long long n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
}

// Count set bits using n & (n-1) trick (Brian Kernighan's algorithm)
int countSetBits(long long n) {
    int count = 0;
    while (n != 0) {
        n &= (n - 1);
        ++count;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
