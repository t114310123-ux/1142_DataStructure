void printPairs(const vector<int>& arr) {
    // step++; (取得長度)
    int n = arr.size(); 
    // 外層迴圈初始化：step++ (i = 0)
    for (int i = 0; i < n; i++) {
        // 外層：(n+1)次判斷, n次遞增i++
         step++; //(i < n)每次迴圈的條件判斷
         step++; //(i++) 迴圈遞增
        // 內層迴圈初始化：n step (每次外層跑，內層 j = i + 1 都會重新初始化一次)
        for (int j = i + 1; j < n; j++) {
         step++; //(i < n)每次迴圈的條件判斷
         step++; //(i++) 迴圈遞增
            cout << arr[i] << "," << arr[j] << endl;
         step++; //(i++) 輸出
        }
    }
}
//內圈有3step(遞增 判斷 輸出)由(n-1)最開始到最後是1次又內圈只做n-1次(i+1開始)所以
內圈= (((n-1)+1)*(n-1))/2*3 外圈有n(遞增)+n+1(判斷)次 最後加上initial = 2
                        =((n*n-n)*3/2)+2n+3 
Therefore, O(n*n) complexity(指數)
