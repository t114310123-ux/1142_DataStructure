class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        vector<int> hk;
        int max;
        int r;
        int a = houses.size();//設定a為房子數量
        int b = heaters.size();//設定b為加熱器數量
        for(int x = 0 ; x<a ;x++){//巢狀迴圈 內層是房子到每一個加熱器的最大距離
            r= abs(houses[x]-heaters[0]);
            for(int y=0 ;y<b ;y++){
                if(r>abs(houses[x]-heaters[y])){
                    r = abs(houses[x]-heaters[y]);
                }
            }
            hk.push_back(r);//總共有a個元素在hk陣列=房子數量
        }
        max = hk[0];
        for(int z = 0 ;z<hk.size();z++){//這裡是取最大的r
            if(hk[z]>max){
                max = hk[z];
            }
        }
        return max;//回傳r
    }
