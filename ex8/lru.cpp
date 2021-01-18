#include "bits/stdc++.h"
int main()
{
    // data input
    std::vector<int> data{1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6};
    int frame = 3;

    // logic variables
    std::vector<std::vector<int>> result;
    result.assign(frame, std::vector<int>(data.size(), -1));
    std::vector<int> cache;
    cache.resize(data.size());

    //LRU
    for (int i = 0; i < data.size(); i++)
    {
        if (i != 0)
        {
            for (int l = 0; l < frame; l++)
            {
                result[l][i] = result[l][i - 1];
            }
        }
        bool isEmpty = false;
        for (int j = 0; j < frame; j++)
        {
            if (result[j][i] == -1)
                isEmpty = true;
        }
                std::cout << isEmpty;
        if (isEmpty == true)
            for (int j = 0; j < frame; j++)
            {
                if (result[j][i] == -1)
                {
                    result[j][i] = data[i];
                    cache.push_back(data[i]);
                    break;
                }
            }
        else
        {
            for (int k = 0; k < frame; k++)
            {
                if (result[k][i] == data[i])
                {
                    for (int l = 0; l < cache.size(); l++)
                    {
                        if (data[i] == cache[l])
                            cache.erase(cache.begin() + l);
                        cache.push_back(data[i]);
                    }
                    break;
                }
                else
                {
                    for (int l = 0; l < frame; l++)
                    {
                        if (cache[0] == result[l][i])
                            result[l][i] = data[i];
                        cache.erase(cache.begin());
                    }
                }
            }
        }
    }

    for (int i = 0; i < data.size(); i++)
    {
        std::cout << "[";
        for (int j = 0; j < frame; j++)
        {
            if (result[j][i] != -1)
                std::cout << result[j][i] << " ";
            else
                std::cout << " ";
        }
        std::cout << "]\n";
    }
    return 0;
}