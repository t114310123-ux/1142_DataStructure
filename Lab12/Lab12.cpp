#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream> // 處理字串拆解

// 定義商品結構體
struct things {
    std::string a;   // 商品名稱 (例如: instant noodles)
    int popular;     // 銷量
    int days;        // 日期
};

int main()
{
    std::ifstream inputFile("test.txt");


    if (!inputFile) {
        std::cerr << "錯誤：無法開啟 test.txt 檔案！" << std::endl;
        return 1;
    }

    // 2. 讀取第一行的商品數量
    int count = 0;
    inputFile >> count;

    // 清除讀完數字後留在緩衝區的「換行符號」
    // 如果不加這行，接下來的第一個 getline() 會讀到空行
    std::string dummy;
    std::getline(inputFile, dummy);

    // 動態配置結構體陣列
    std::vector<things> all(count);

    // 3. 開始逐行讀取
    for (int i = 0; i < count; i++) {
        std::string line;

        // 抓取整行資料，這時候 "instant noodles 5 10" 會被整串抓進來
        if (!std::getline(inputFile, line)) {
            break;
        }

        // 利用 stringstream 把這一行字串變成可以切割的串流//這是GPT說的我有點搞不懂串流
        std::stringstream ss(line);
        std::vector<std::string> words;
        std::string temp;

        // 把這一行所有的單字用「空格」切開，依序存入 words 陣列
        // 例如會切成：["instant", "noodles", "5", "10"]
        while (ss >> temp) {
            words.push_back(temp);
        }

        if (words.size() < 3) continue;



        // 抓出最後一個碎片，轉成整數存入銷量
        all[i].popular = std::stoi(words.back());
        words.pop_back(); // 拿走銷量

        // 抓出此時的最後一個碎片，轉成整數存入日期
        all[i].days = std::stoi(words.back());
        words.pop_back(); // 拿走日期

        // 【還原商品名稱】
        // 剩下的碎片就是商品名稱了 (可能包含空格)
        std::string name = "";
        for (size_t j = 0; j < words.size(); j++) {
            name += words[j];
            if (j < words.size() - 1) {
                name += " "; // 補回中間被切斷的空格
            }
        }
        all[i].a = name; // 成功把 "instant noodles" 存入結構體
    }
    // 4. 關閉檔案
    inputFile.close();

    // 5. 輸出結果，驗證是否精準讀取成功
    std::cout << "==============================" << std::endl;
    std::cout << " 成功讀取 " << count << " 筆商品資料：" << std::endl;
    std::cout << "==============================" << std::endl;

    for (int i = 0; i < count; i++) {
        std::cout << "讀取資料\n";
        std::cout << "商品 " << i + 1 << " -> "
            << "名稱: [" << all[i].a << "], "
            << "日期: " << all[i].days << " 天, "
            << "銷量: " << all[i].popular << " 個"
            << std::endl;
    }


    int time = count;
    // BOBBLE排序法 每一次迴圈會從沒排序的產生一次最大的放到右邊//這部份是我獨自完成的
    for (int j = 0; j < count - 1; j++) {
        for (int i = 0; i < count - j - 1; i++) {

            if (all[i].days > all[i + 1].days) {//日期優先

                things temp = all[i];
                all[i] = all[i + 1];
                all[i + 1] = temp;
            }
            else if (all[i].days == all[i + 1].days) {//同日期人氣高人氣優先

                if ((all[i].popular < all[i + 1].popular)) {
                    things temp = all[i];
                    all[i] = all[i + 1];
                    all[i + 1] = temp;
                }
            }

        }
    }
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";

    for (int x = 0; x < count; x++) {//全部輸出
        std::cout << all[x].a << "\n";
    }
    return 0;
}
