#include <iostream>
#include <vector>
#include "library.h"

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> vec(n), vec_q_sorted, vec_random_sorted, vec_min_sorted, ins_vec_sorted;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    cout << " results " << endl;

    vec_q_sorted = vec;
    cout << "qsort: ";
    qsort(0, vec_q_sorted.size()-1, vec_q_sorted);
    for (int i = 0; i < vec_q_sorted.size(); i++) cout << vec_q_sorted[i] << " ";
    cout << endl;

    vec_min_sorted = vec;
    cout << "min sort: ";
    min_sort(vec_min_sorted);
    for (int i = 0; i < vec_min_sorted.size(); i++) cout << vec_min_sorted[i] << " ";
    cout << endl;

    ins_vec_sorted = vec;
    cout << "insertion sort: ";
    insertion_sort(ins_vec_sorted);
    for (int i = 0; i < ins_vec_sorted.size(); i++) cout << ins_vec_sorted[i] << " ";
    cout << endl;

    vec_random_sorted = vec;
    cout << "random sort: ";
    random_sort(vec_random_sorted);
    for (int i = 0; i < vec_random_sorted.size(); i++) cout << vec_random_sorted[i] << " ";
    cout << endl;
    return 0;
}
