#include<iostream>
#include<vector>
#include "../src/sorting.h"

bool test_selection_sort(std::vector<int> test_vector, std::vector<int> result) {
    selection_sort(test_vector);
    
    return test_vector==result;
}

#define IS_TRUE(x) { if (!(x)) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; }

void test() {
    std::vector<int> test_vector = {13,54,6,8,2,4,2,1,57};
    std::vector<int> result = {1, 2, 2, 4, 6, 8, 13, 54, 57};
    IS_TRUE(test_selection_sort(test_vector, result));
}

int main(void) {
    test();
}