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

int partition(std::vector<int>& numbers, int first, int last) {
    int pivot_value = numbers[first];
    int temp;

    int leftmark = first+1;
    int rightmark = last;

    bool done = false;

    while (!done) {
        while (leftmark<= rightmark && numbers[leftmark]<= pivot_value) {
            leftmark = leftmark+1;
        }
        while (numbers[rightmark]>= pivot_value && rightmark>= leftmark) {
            rightmark = rightmark-1;
        }

        if (rightmark<leftmark) {
            done=true;
        } else {
            temp = numbers[leftmark];
            numbers[leftmark] = numbers[rightmark];
            numbers[rightmark] = temp;
        }
    }
    temp = numbers[first];
    numbers[first] = numbers[rightmark];
    numbers[rightmark] = temp;

    return rightmark;
}

void quick_sort_helper(std::vector<int>& numbers, int first, int last) {
    if (first<last) {
        int splitpoint = partition(numbers, first, last);

        quick_sort_helper(numbers, first, splitpoint-1);
        quick_sort_helper(numbers, splitpoint+1, last);
    }
}