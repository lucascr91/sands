#include<iostream>
#include<vector>
#include<algorithm>

typedef std::vector<int>::iterator it_vec;

bool compare(int a, int b);
std::vector<int> cut_vector(std::vector<int> numbers, int start);
void print_vector(std::vector<int> numbers, std::string sep);
int get_minimum(std::vector<int> values, int start);
void exchange(int item, int position, std::vector<int>& numbers);

void selection_sort(std::vector<int>& numbers) {
    int i = 0;
    int minimum;
    std::string space = " ";
    while(i<numbers.size()) {
        minimum = get_minimum(numbers, i);
        it_vec it_min = std::find(numbers.begin()+i, numbers.end(), minimum);
        std::iter_swap(it_min, numbers.begin()+i);
        i++;
    }
}

void insertion_sort(std::vector<int>& numbers) {
    int n = numbers.size();
    int i= 1;
    int j;

    while (i<n) {
        j=i;
        while (j>0 && compare(numbers[j-1], numbers[j])) {
            exchange(numbers[j], j-1, numbers);
            j=j-1;
        }
        i++;
    }
}