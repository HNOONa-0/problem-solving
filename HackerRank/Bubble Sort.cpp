void countSwaps(vector<int>& v) {

    int swap_cnt = 0, n = v.size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1; j++){
            if (v[j] > v[j + 1]){
                swap(v[j], v[j + 1]);
                swap_cnt++;
            }
        }
    }
    cout << "Array is sorted in " << swap_cnt << " swaps." << endl;
    cout << "First Element: " << v.front() << endl;
    cout << "Last Element: " << v.back() << endl;
}
