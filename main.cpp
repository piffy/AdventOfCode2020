#include <iostream>
#include <fstream>
#include <algorithm>

bool check(int lower, int upper, char ch, std::string basicString);
bool check2(int pos1, int pos2, char target, std::string str);

using namespace std;


int main() {
    std::ifstream input("data.txt");
    std::uintmax_t x;
    int n1, n2, count = 0, count2=0;
    char target, trash;
    std::string password;
    // La lettura è eticamente orribile. fscanf:fstream 1-0
    while (input >> n1 >> trash >> n2 >> target >> trash >> password) {
        //cout<<n1<<"-"<<n2<<" "<<target<<": "<<password<<endl
        count= check(n1, n2, target, password) ? count + 1 : count;
        count2= check2(n1, n2, target, password) ? count2 + 1 : count2;
    }
    cout<<count<<endl;
    cout<<count2<<endl;
    return EXIT_SUCCESS;

}


bool check(int lower, int upper, char ch, string basicString) {
    int count= std::count(basicString.begin(), basicString.end(), ch);
    if (count<lower || count>upper)
        return false;
    return true;
}

bool check2(int pos1, int pos2, char target, string str) {
    int c=0;
    if (str[pos1-1]==target) c++;
    if (str[pos2-1]==target) c++;
    return c==1;
}
