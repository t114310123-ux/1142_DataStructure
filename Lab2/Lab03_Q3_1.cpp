
void copyArray(const vector<int>& source, vector<int>& dest) {
    // 迴圈初始化：step++;// (i = 0)
    for (int i = 0; i < source.size(); i++) {
        // 每次迴圈的操作：
         step++;// (條件判斷 i < source.size())
        step++ //(索引遞增 i++)
        dest[i] = source[i]; 
        step++//(賦值操作：讀取 source 並寫入 dest)
    }
}
//迴圈會有n次的賦值還有n次遞增與n+1次的判斷 加上前面的初始化 共有3n+2次Therefore, O(n) complexity
