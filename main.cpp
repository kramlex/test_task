#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>

using namespace std;

const int maxLength = 1e3;
const int multiplyPossibleSizes = 3;

vector<vector<int>> createArrays(int n) {
    auto possibleSizes = vector<int> (n * multiplyPossibleSizes,0);

    for(int i = 0; i < n * 3; i++)
        possibleSizes[i] = i+1;

    shuffle(possibleSizes.begin(), possibleSizes.end(), random_device());

    vector<vector<int>> arrays(n);
    for(int i = 0; i < n; i++){
        arrays[i].resize(possibleSizes[i]);
        for(int j = 0; j < possibleSizes[i]; j++){
            arrays[i][j] = rand() % maxLength;
        }
        if(i % 2) sort(arrays[i].rbegin(), arrays[i].rend());
        else sort(arrays[i].begin(), arrays[i].end());
    }
    return arrays;
}

int main() {
    int n;
    cin >> n;
    auto arrays = createArrays(n);

    // output
    for( auto i: arrays){
        for(auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
