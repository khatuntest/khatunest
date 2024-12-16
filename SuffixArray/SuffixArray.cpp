#include <algorithm>
#include "SuffixArray.h"

SuffixArray::SuffixArray(const char* s) {
    size = 0;
    while (s[size] != '\0') {
        size++; // Calculate the size of the input string
    }
    // Allocate memory for all required arrays
    str = new char[size];    // To hold the input string
    rank = new int[size];    // To hold the rank of suffixes
    suf = new int[size];     // To hold the suffix indices (suffix array)
    temp = new int[size];    // Temporary rank array for rank updates
    sufTemp = new int[size]; // Temporary array for merge sort
    // Copy the input string to the `str` array
    for (int i = 0; i < size; ++i) {
        str[i] = s[i];
    }
}

// Constructs the suffix array using the prefix doubling approach
void SuffixArray :: ConstructUsingPrefixDoubling() {
    // Initialize ranks and suffix indices
    for (int i = 0; i < size; ++i) {
        suf[i] = i;        // Suffix index starts at each position
        rank[i] = str[i];  // Initial rank is based on ASCII value of characters
    }
    // Iteratively build the suffix array using lengths of 1, 2, 4, ..., 2^k
    for (int len = 1; len < size; len *= 2) {
        // Perform merge sort on the suffix indices based on ranks
        MergeSort(suf, 0, size - 1, len);
        // Update temporary ranks after sorting
        temp[suf[0]] = 0; // First suffix always gets rank 0
        for (int i = 1; i < size; ++i) {
            temp[suf[i]] = temp[suf[i - 1]]; // Inherit previous rank
            if (compare(suf[i - 1], suf[i], len)) {
                temp[suf[i]]++; // Increment rank if the current suffix is different
            }
        }
        // Update ranks for the next iteration
        for (int i = 0; i < size; ++i) {
            rank[i] = temp[i];
        }
        // Optimization: If all ranks are unique, break early
        if (rank[suf[size - 1]] == size - 1)
            break;
    }
}

// Recursive merge sort function to sort suffix indices
void SuffixArray :: MergeSort(int* array, int left, int right, int len) {
    if (left >= right) return; // Base case: Single element
    int mid = (left + right) / 2;
    // Recursively sort left and right halves
    MergeSort(array, left, mid, len);
    MergeSort(array, mid + 1, right, len);
    // Merge the sorted halves
    Merge(array, left, mid, right, len);
}

// Merge function to combine two sorted halves
void SuffixArray :: Merge(int* array, int left, int mid, int right, int len) {
    int i = left, j = mid + 1, k = left;
    // Merge the elements based on the `compare` function
    while (i <= mid && j <= right) {
        if (compare(array[i], array[j], len)) {
            sufTemp[k++] = array[i++]; // Choose from the left half
        } else {
            sufTemp[k++] = array[j++]; // Choose from the right half
        }
    }
    // Copy remaining elements from the left half (if any)
    while (i <= mid) {
        sufTemp[k++] = array[i++];
    }
    // Copy remaining elements from the right half (if any)
    while (j <= right) {
        sufTemp[k++] = array[j++];
    }
    // Copy merged elements back into the original array
    for (int x = left; x <= right; ++x) {
        array[x] = sufTemp[x];
    }
}

// Comparison function for suffix indices
bool SuffixArray:: compare(int a, int b, int len) {
    // Compare the first segment of length `len`
    if (rank[a] != rank[b])
        return rank[a] < rank[b];

    // Compare the next segment of length `len` if the first segments are equal
    int rankA = (a + len < size) ? rank[a + len] : -1; // Out-of-bounds is treated as -1
    int rankB = (b + len < size) ? rank[b + len] : -1; // Out-of-bounds is treated as -1
    return rankA < rankB;
}

void SuffixArray :: Print(){
    for (int i = 0; i < size; ++i) {
        cout << suf[i] << " "; // Print each suffix index
    }
    cout << "\n";
}

// Destructor: Free the dynamically allocated memory
SuffixArray :: ~SuffixArray() {
    delete[] str;     // Free memory allocated for the string
    delete[] rank;    // Free memory allocated for rank array
    delete[] suf;     // Free memory allocated for suffix array
    delete[] temp;    // Free temporary rank array
    delete[] sufTemp; // Free temporary merge sort array
}