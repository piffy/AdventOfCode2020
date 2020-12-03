#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>

bool check(int lower, int upper, char ch, std::string basicString);

using namespace std;


int main() {
    std::ifstream input("data.txt");
    std::uintmax_t x;
    int minrep, maxrep, count = 0;
    char target, trash;
    std::string password;
    // La lettura è eticamente orribile. fscanf:fstream 1-0
    while (input >> minrep >> trash >> maxrep >> target >> trash >> password) {
        count= check(minrep, maxrep, target, password) ? count + 1 : count;
        //cout<<minrep<<"-"<<maxrep<<" "<<target<<": "<<password<<endl
    }
    cout<<count<<endl;

    return EXIT_SUCCESS;

}

bool check(int lower, int upper, char ch, string basicString) {
    int count= std::count(basicString.begin(), basicString.end(), ch);
    if (count<lower || count>upper)
        return false;
    return true;
}
