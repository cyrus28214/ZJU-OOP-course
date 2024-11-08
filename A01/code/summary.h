#ifndef SUMMARY_H
#define SUMMARY_H

class Summary
{
    static const int NUM_COLS = 3;
public:
    int count;
    double average[NUM_COLS];
    int min[NUM_COLS], max[NUM_COLS];
    Summary();
    void add(int* row);
    void finalize();
};
#undef N

#endif // SUMMARY_H