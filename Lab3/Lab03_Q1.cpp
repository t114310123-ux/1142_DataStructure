class Solution {
public:
    int findLucky(vector<int>& arr) {//宣告公用函式findlucky，輸入為來自題目的資料:arr
         n++;
        int count[501] = {0}; //宣告陣列count有501名成員，皆等於0
         n++;
        int n = arr.size(); //變數n=arr資料的長度
         n++;
        for (int i = 0; i < n; i++) {//做n次
         n++;
            int num = arr[i];   //區域變數num = arr[第i個]
                 n++;
            if (num >= 1 && num <= 500) { //如果arr的第i個元素在1和501的範圍間
                count[num]++;        //陣列cout的第i位數值加一
                 n=+3;
            }
        }
        for (int i = 500; i >= 1; i--) {
                n++;
            if (count[i] == i) {//由第500末位開始倒數如果第i位的數有i個 就將第i的"i"回傳
                return i; 
                n++;
            }
        }
        return -1;//如果找不到就return-1
    }
};     //O(n)=3+(2+3)n+500*2 時間複雜度~=O(n)
