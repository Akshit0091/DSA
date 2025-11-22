#include <iostream>
#include <vector>
using namespace std;

int circularTour(const vector<int>& petrol, const vector<int>& distance) {
    int n = petrol.size();
    int start = 0, totalSurplus = 0, currentSurplus = 0;

    for (int i = 0; i < n; i++) {
        int surplus = petrol[i] - distance[i];
        totalSurplus += surplus;
        currentSurplus += surplus;

        if (currentSurplus < 0) {
            start = i + 1;
            currentSurplus = 0;
        }
    }

    return (totalSurplus >= 0) ? start : -1;
}

int main() {
    vector<int> petrol = {4, 6, 7, 4};
    vector<int> distance = {6, 5, 3, 5};

    int startPoint = circularTour(petrol, distance);

    if (startPoint != -1)
        cout << "Start at petrol pump index: " << startPoint << endl;
    else
        cout << "No circular tour possible." << endl;

    return 0;
}
