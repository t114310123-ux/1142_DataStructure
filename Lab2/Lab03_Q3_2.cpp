int countElement(const vector<int>& arr, int target) {
    int count = 0; // 1 step (初始化 count)
    // 迴圈初始化：1 step (i = 0)
    for (int i = 0; i < arr.size(); i++) {
        // 迴圈判斷 (n + 1) 次
        // 迴圈遞增 (n) 次
        if (arr[i] == target) { // (n) 次比較
         //判斷1step
            count++; // (最糟情況 n 次，即所有元素都等於 target)
         //count+1 1step
        }
    }
    return count; // 1 step (回傳結果)
}
//3(initial return and i=0 and count =0)+2n(if+count)+n+1(判斷)+n(遞增) = 4+3n
Therefore, O(n) complexity
