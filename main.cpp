// COMSC-210 | Lab 25 | Dan Pokhrel
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
using namespace std;
using namespace std::chrono;

const int CODES_SZ = 20000;
const int ROWS = 4, COL = 3;

// Prototypes
high_resolution_clock::time_point time_start();
int time_end(high_resolution_clock::time_point start);

int main() {
    vector<string> vec;
    list<string> lis;
    set<string> se;
    int results[ROWS][COL];

    // read file
    ifstream fin("codes.txt");
    string codes[CODES_SZ];
    int i = 0;
    while (fin.good()){
        string x; getline(fin, x);
        codes[i] = x;
        i++;
    }

    // read

    auto start = time_start();
    // ---------------------------------------------------------------
    for (int i = 0; i < CODES_SZ; i++)
        vec.push_back(codes[i]);
    results[0][0] = time_end(start);
    // ---------------------------------------------------------------

    start = time_start();
    // ---------------------------------------------------------------
    for (int i = 0; i < CODES_SZ; i++)
        lis.push_back(codes[i]);
    // ---------------------------------------------------------------
    results[0][1] = time_end(start);

    start = time_start();
    // ---------------------------------------------------------------
    for (int i = 0; i < CODES_SZ; i++)
        se.insert(codes[i]);
    // ---------------------------------------------------------------
    results[0][2] = time_end(start);

    // sort

    start = time_start();
    // ---------------------------------------------------------------
    sort(vec.begin(), vec.end());
    // ---------------------------------------------------------------
    results[1][0] = time_end(start);

    start = time_start();
    // ---------------------------------------------------------------
    lis.sort();
    // ---------------------------------------------------------------
    results[1][1] = time_end(start);
    
    results[1][2] = -1;

    // insert

    start = time_start();
    // ---------------------------------------------------------------
    vec.insert(vec.begin() + CODES_SZ/2, "TESTCODE");
    // ---------------------------------------------------------------
    results[2][0] = time_end(start);

    start = time_start();
    // ---------------------------------------------------------------
    list<string>::iterator it = lis.begin(); advance(it, CODES_SZ/2);
    lis.insert(it, "TESTCODE");
    // ---------------------------------------------------------------
    results[2][1] = time_end(start);

    start = time_start();
    // ---------------------------------------------------------------
    se.insert("TESTCODE");
    // ---------------------------------------------------------------
    results[2][2] = time_end(start);

    // delete

    start = time_start();
    // ---------------------------------------------------------------
    vec.erase(vec.begin() + CODES_SZ/2);
    // ---------------------------------------------------------------
    results[3][0] = time_end(start);

    start = time_start();
    // ---------------------------------------------------------------
    it = lis.begin(); advance(it, CODES_SZ/2);
    lis.erase(it);
    // ---------------------------------------------------------------
    results[3][1] = time_end(start);

    start = time_start();
    // ---------------------------------------------------------------
    se.erase("eohGGM1Q");
    // ---------------------------------------------------------------
    results[3][2] = time_end(start);

    // Output

    cout << " Operation    Vector      List       Set\n";

    cout << setw(10) << "Read";
    cout << setw(10) << results[0][0]
        << setw(10) << results[0][1]
        << setw(10) << results[0][2] << endl;

    cout << setw(10) << "Sort";
    cout << setw(10) << results[1][0]
        << setw(10) << results[1][1]
        << setw(10) << results[1][2] << endl;

    cout << setw(10) << "Insert";
    cout << setw(10) << results[2][0]
        << setw(10) << results[2][1]
        << setw(10) << results[2][2] << endl;

    cout << setw(10) << "Delete";
    cout << setw(10) << results[3][0]
        << setw(10) << results[3][1]
        << setw(10) << results[3][2] << endl;

    return 0;
}

high_resolution_clock::time_point time_start(){
    return high_resolution_clock::now();
}

int time_end(high_resolution_clock::time_point start){
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}