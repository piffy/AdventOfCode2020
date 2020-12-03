#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int parte1(const std::vector<std::uintmax_t>& numeri )
{
    for(auto i = 0; i < numeri.size(); ++i )
    {
        for(auto j = 0; j < numeri.size(); ++j )
        {
            if(numeri[i] + numeri[j] == 2020 )
                return numeri[i] * numeri[j];
        }
    }
    return {};
}
long long int parte2(const std::vector<std::uintmax_t>& numeri )
{
    for(auto i = 0; i < numeri.size(); ++i )
    {
        for(auto j = 0; j < numeri.size(); ++j )
        {
            if(numeri[i] + numeri[j] >= 2020)
                continue;
            for (auto k = 0; k < numeri.size(); ++k)
            if(numeri[i] + numeri[j] + numeri[k]== 2020 )
                return numeri[i] * numeri[j] * numeri[k];
        }
    }
    return {};
}

int main() {

    std::vector<std::uintmax_t> numeri;
    std::ifstream Input("data.txt");
    std::uintmax_t x;
    while( Input >> x ) numeri.push_back(x);

    cout << parte1(numeri) << endl;
    cout << parte2(numeri) << endl;
    return EXIT_SUCCESS;

}
