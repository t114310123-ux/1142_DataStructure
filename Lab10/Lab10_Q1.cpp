#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream> 
using namespace std;
vector<int> readFromFile(const string& filename) {//這裡是讀取input檔案的程式
    vector<int> arr;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "【錯誤】找不到檔案: " << filename << endl;
        return arr;
    }
    string line;
    if (getline(file, line)) {
        stringstream ss(line);
        string token;
        while (getline(ss, token, ',')) {
            if (!token.empty()) {
                arr.push_back(stoi(token)); 
            }
        }
    }
    file.close();
    return arr;
}
class MaxHeap {
public:
    vector<int> heap;
    void buildMaxHeap(vector<int>& arr) {
        heap = arr;
        for (int i = (heap.size() / 2) - 1; i >= 0; i--) {//這段是從TREE的葉子開始 往上做比較的判別
            heapify(i);
        }
    }
    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;//這裡是完整的binary tree 左子樹 = 2i+1 右=2i+2
        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;//如果左tree比當前parent 節點大 且左>右 larget 設為左tree的值
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;//如果右tree比當前parent 節點大 且左<右 larget 設為右tree的值
        }
        if (largest != i) {//如果發生兩種其中一種讓最大的不再是parent節點 就交換
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }
    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};
class MinHeap {
public:
    vector<int> heap;

    void buildMinHeap(vector<int>& arr) {
        heap = arr;
        for (int i = (heap.size() / 2) - 1; i >= 0; i--) {//這段是從TREE最後一個有小孩的節點開始 往上做比較的判別
            heapify(i);
        }
    }

    void heapify(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;//這裡是完整的binary tree 左子樹 = 2i+1 右=2i+2

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;//如果左tree比當前parent 節點小 且左<右 smallest 設為左tree的值
        }
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;//如果右tree比當前parent 節點小 且左>右 smallest 設為右tree的值
        }
        if (smallest != i) {//如果發生兩種其中一種讓最小的不再是parent節點 就交換
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }
    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};
int main() {
    string filename = "ww.txt";
    vector<int> arr = readFromFile(filename);
    if (arr.empty()) {
        cout << "\n讀取失敗，請確認 ww.txt 內是否有正確的資料。" << endl;
        system("pause");
        return -1;
    }
    cout << "Input Array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl << endl;
    MaxHeap maxHeap;
    maxHeap.buildMaxHeap(arr);
    cout << "Max Heap: ";
    maxHeap.printHeap();
    cout << endl;
    MinHeap minHeap;
    minHeap.buildMinHeap(arr);
    cout << "Min Heap: ";
    minHeap.printHeap();
    cout << endl;
    system("pause");
    return 0;
}
