Algorithm:
Sort activities by finish time (ascending order).
Select the first activity (earliest finishing).
Iterate through remaining activities:
If an activity starts after or when the previous one finishes, select it.
Continue until all activities are considered.
Return the selected activities.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start, end;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

void activitySelection(vector<Activity> activities) {
    sort(activities.begin(), activities.end(), compare);

    cout << "Selected activities:\n";
    int lastEnd = 0;
    for (auto act : activities) {
        if (act.start >= lastEnd) {
            cout << "Activity (" << act.start << ", " << act.end << ")\n";
            lastEnd = act.end;
        }
    }
}

int main() {
    vector<Activity> activities = {{1, 3}, {2, 5}, {0, 6}, {8, 9}, {5, 7}, {5, 9}};

    activitySelection(activities);

    return 0;
}
