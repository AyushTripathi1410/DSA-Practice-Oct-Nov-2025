vector<int> Smallestonleft(int arr[], int n) {
    vector<int> ans;
    set<int> s;

    for (int i = 0; i < n; i++) {
        auto it = s.lower_bound(arr[i]);  
        
        if (it == s.begin()) {
            ans.push_back(-1);
        } else {
            it--;  
            ans.push_back(*it);
        }

        s.insert(arr[i]);  
    }

    return ans;
}
