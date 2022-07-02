#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

typedef std::vector<int>::iterator it_vec;

bool compare(int a, int b) {
    return a>b;
}

std::vector<int> cut_vector(std::vector<int> numbers, int start) {
    std::vector<int> result;
    it_vec lower = numbers.begin()+start;
    std::copy(lower, numbers.end(), std::back_inserter(result));

    return result;
}

void print_vector(std::vector<int> numbers, std::string sep) {
    for (const int& i: numbers) {
        std::cout<<i<<sep;
    }
    std::cout<<"\n";
}

int get_minimum(std::vector<int> values, int start) {
    std::vector<int> numbers = cut_vector(values, start);
    int minimum = numbers[0];
    int element;
    for (it_vec it= numbers.begin(); it<(numbers.end()-1); it++) {
        element = *(it+1);
        if (compare(minimum, element)) {
            minimum = element;
        }
    }

    return minimum;
}