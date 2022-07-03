#include<iostream>
#include<vector>
#include<algorithm>

typedef std::vector<int>::iterator it_vec;

bool compare(int a, int b);
std::vector<int> cut_vector(std::vector<int> numbers, int start);
void print_vector(std::vector<int> numbers, std::string sep);
int get_minimum(std::vector<int> values, int start);

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
            it_vec it  = numbers.begin()+ j;
            std::iter_swap(it, numbers.begin()+j-1);
            // exchange(numbers[j], numbers.begin()+j-1, numbers);
            j=j-1;
        }
        i++;
    }
}

void shell_sort(std::vector<int>& numbers) {
    int N = numbers.size();
    int h = 1;

    while (h<N/3) {
        h = 3*h +1;
    }

    while (h>=1) {
        for (int i = h; i<N; i++) {
            for (int j=i; j>=h && compare(numbers[j-h], numbers[j]); j-=h) {
                it_vec it_j = numbers.begin() + j; 
                it_vec it_jh = numbers.begin() + (j-h);
                std::iter_swap(it_jh, it_j); 
            }
        }
        h = h/3;
    }
}

void merge_sort(std::vector<int>& numbers) {
    int N = numbers.size();
    if (N>1) {
        int mid = N/2;
        std::vector<int> lefthalf;
        std::vector<int> righthalf;
        std::copy(numbers.begin(), numbers.begin()+mid, std::back_inserter(lefthalf));
        std::copy(numbers.begin()+mid, numbers.end(), std::back_inserter(righthalf));

        merge_sort(lefthalf);
        merge_sort(righthalf);

        int i =0, j=0, k=0, n=lefthalf.size(), m=righthalf.size();

        while (i<n && j<m) {
            if (lefthalf[i]<righthalf[j]) {
                numbers[k]=lefthalf[i];
                i++;
            } else {
                numbers[k]=righthalf[j];
                j++;
            }
            k++;
        }

        while (i<n) {
            numbers[k]=lefthalf[i];
            i++;
            k++;
        }

        while (j<m) {
            numbers[k]=righthalf[j];
            j++;
            k++;
        }
    }
}