#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// FIFO: replaces the page that entered memory earliest.
int fifoFaults(const vector<int>& pages, int capacity) {
    vector<int> frames;
    int faults = 0;
    int nextToReplace = 0;

    for (int page : pages) {
        if (find(frames.begin(), frames.end(), page) != frames.end()) {
            continue; // Page hit
        }

        ++faults;

        if (static_cast<int>(frames.size()) < capacity) {
            frames.push_back(page);
        } else {
            frames[nextToReplace] = page;
            nextToReplace = (nextToReplace + 1) % capacity;
        }
    }

    return faults;
}

// LRU: replaces the page that has not been used for the longest time.
int lruFaults(const vector<int>& pages, int capacity) {
    vector<int> frames;
    vector<int> lastUsed;
    int faults = 0;

    for (int i = 0; i < static_cast<int>(pages.size()); ++i) {
        int page = pages[i];
        auto it = find(frames.begin(), frames.end(), page);

        if (it != frames.end()) {
            lastUsed[it - frames.begin()] = i; // Update recent use
            continue;
        }

        ++faults;

        if (static_cast<int>(frames.size()) < capacity) {
            frames.push_back(page);
            lastUsed.push_back(i);
        } else {
            int leastRecentlyUsed =
                static_cast<int>(min_element(lastUsed.begin(), lastUsed.end())
                                 - lastUsed.begin());
            frames[leastRecentlyUsed] = page;
            lastUsed[leastRecentlyUsed] = i;
        }
    }

    return faults;
}

int main() {
    int n, capacity;

    cout << "Enter number of page references: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid number of references\n";
        return 1;
    }

    vector<int> pages(n);
    cout << "Enter page reference string: ";
    for (int i = 0; i < n; ++i) {
        if (!(cin >> pages[i])) {
            cout << "Invalid page reference input\n";
            return 1;
        }
    }

    cout << "Enter number of frames: ";
    if (!(cin >> capacity) || capacity <= 0) {
        cout << "Invalid number of frames\n";
        return 1;
    }

    cout << "\nFIFO page faults: " << fifoFaults(pages, capacity) << '\n';
    cout << "LRU page faults: " << lruFaults(pages, capacity) << '\n';

    return 0;
}
