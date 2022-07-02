#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#include "sorting.h"
// #include "utils.h"

int main() {
    std::vector<int> test{4,3,2,2,1};

    // int value = get_minimum(test, 2);

    // std::cout<<value<<std::endl;

    // exchange(5,0,test);

    selection_sort(test);

    // std::iter_swap(test.begin()+1, test.begin()+2);

    // std::string sep = "\n";

    // print_vector(test, sep);
    // insertion_sort(test);

    // print_vector(test);

    // std::vector<int> result = cut_vector(test, 0);

    // print_vector(result);

    return 0;
}