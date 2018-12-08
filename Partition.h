#ifndef PARTITION_H
#define PARTITION_H
#include <vector>
#include <random>
using namespace std;

class Partition
{
    public:
        int partition(vector<int>&, int, int);
        int randomElement(int, int);
        int randomised_partition(vector<int>&, int, int);
};

#endif // PARTITION_H
