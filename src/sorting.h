#ifndef GUARD_grade_h
#define GUARD_grade_h

void selection_sort(std::vector<int>& numbers);
void insertion_sort(std::vector<int>& numbers);
bool compare(int a, int b);
std::vector<int> cut_vector(std::vector<int> numbers, int start);
void print_vector(std::vector<int> numbers, std::string sep);
int get_minimum(std::vector<int> values, int start);
void exchange(int item, int position, std::vector<int>& numbers);

#endif