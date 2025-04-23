#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct pw {
    int p; 
    int w; 
    
    
    bool operator<(const pw& other) const {
        return w < other.w || (w == other.w && p < other.p);
    }

    bool operator==(const pw& other) const {
        return w == other.w && p == other.p;
    }
};


vector<pw> merge_purge(const vector<pw>& S_prev, const vector<pw>& S_new) {
    vector<pw> merged;
    
     // MERGE  ( S^i = merge(S^{i-1}, S^{i-1}_i))
    merge(S_prev.begin(), S_prev.end(),
          S_new.begin(), S_new.end(),
          back_inserter(merged));
    
    // PURGE step (remove dominated pairs)
    vector<pw> purged;
    int max_p = -1;
    
    for (const auto& pair : merged) {
        if (pair.p > max_p) {  // Keep only non-dominated (p,w) pairs
            purged.push_back(pair);
            max_p = pair.p;
        }
    }
    
    return purged;
}

vector<vector<pw>> solve_knp(int n, const vector<int>& p, const vector<int>& w, int W) {
    vector<vector<pw>> S(n + 1);  // S^0 to S^n
    
 
    S[0] = {{0, 0}};
    
    // Build S^i sets iteratively 
    for (int i = 1; i <= n; i++) {
        // Create S^{i-1}_i = {(p + p_i, w + w_i) | (p,w) ∈ S^{i-1}}
        vector<pw> S_i_prev;
        for (const auto& pair : S[i-1]) {
            int new_p = pair.p + p[i-1];
            int new_w = pair.w + w[i-1];
            
            if (new_w <= W) {  
                S_i_prev.push_back({new_p, new_w});
            }
        }
        
        // S^i = merge_purge(S^{i-1}, S^{i-1}_i)
        S[i] = merge_purge(S[i-1], S_i_prev);
    }
    
    return S;
}

vector<int> trace_knp(const vector<vector<pw>>& S, int n, const vector<int>& p, const vector<int>& w) {
    vector<int> x(n, 0);  
    pw current = S[n].back();  
    
   
    for (int i = n; i >= 1; i--) {
        pw possible_prev = {current.p - p[i-1], current.w - w[i-1]};
        
        // Check if (p_x, w_x) ∈ S^{i-1}
        if (find(S[i-1].begin(), S[i-1].end(), possible_prev) != S[i-1].end()) {
            x[i-1] = 1;  // x_i = 1 as in your notes
            current = possible_prev;
        }
        // else x_i remains 0 (from initialization)
    }
    
    return x;
}

int main() {
   
    int n = 4;     
    vector<int> p = {1, 2, 3, 4};  
    vector<int> w = {2, 3, 4, 5};  
    int W = 10;      
    
    auto S = solve_knp(n, p, w, W);
    
    if (S[n].empty()) {
        cout << "No feasible solution!" << endl;
    } else {
        auto optimal = S[n].back();
        cout << "Optimal solution:" << endl;
        cout << "Total profit p = " << optimal.p << endl;
        cout << "Total weight w = " << optimal.w << endl;
        
        auto x = trace_knp(S, n, p, w);
        cout << "Selected items (x_i values): ";
        for (int val : x) cout << val << " ";
        cout << endl;
    }
    
    return 0;
}