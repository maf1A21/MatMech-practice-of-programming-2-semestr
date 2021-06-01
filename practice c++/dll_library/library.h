#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
using namespace std;

void insertion_sort(std::vector <int> &vec);
void min_sort(std::vector<int> &vec);
void random_sort(std::vector<int> &vec);
void qsort(int beg, int end, std::vector<int> &vec);

#endif // LIBRARY_H
