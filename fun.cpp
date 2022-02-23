#include "header.h"
#include <math.h>

void fill_peaks(const std::vector<int>& numbers, std::vector<int>& peaks_indx)
{
    for(size_t i = 1; i < numbers.size() - 1; ++i)
    {
        if(numbers[i-1] < numbers[i] && numbers[i] > numbers[i+1])
        {
            peaks_indx.push_back(i);
        }
    }
}


int solution(std::vector<int>& numbers)
{
    if(numbers.size() < 3)
        return 0;
        
    std::vector<int> peaks_indx;
    fill_peaks(numbers, peaks_indx);

    if(peaks_indx.size() <= 2)
        return peaks_indx.size();


    int dist = peaks_indx.back() - peaks_indx[0] + 1;
    int max_flags = std::floor(std::sqrt(dist)) + 1;

    while(max_flags >= 2)
    {
        int cnt = 1;
        int curr_indx = peaks_indx[0];
        for (size_t j = 1; j < peaks_indx.size(); ++j)
        {
            if(curr_indx + max_flags <= peaks_indx[j])
            {
                curr_indx = peaks_indx[j];
                ++cnt;
            }
        }

        if(cnt >= max_flags)
            break;

        --max_flags;
    }

    return max_flags;
}


