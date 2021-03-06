#ifndef GUARD_grade_h
#define GUARD_grade_h

void selection_sort(std::vector<int>& numbers);
void insertion_sort(std::vector<int>& numbers);
void shell_sort(std::vector<int>& numbers);
void merge_sort(std::vector<int>& numbers);
bool compare(int a, int b);
std::vector<int> cut_vector(std::vector<int> numbers, int start);
void print_vector(std::vector<int> numbers, std::string sep);
int get_minimum(std::vector<int> values, int start);
int partition(std::vector<int> numbers, int first, int last);
void quick_sort_helper(std::vector<int>& numbers, int first, int last);
void quick_sort(std::vector<int>& numbers);

#endif