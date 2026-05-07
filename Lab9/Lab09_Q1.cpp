#include <iostream>
using namespace std;
// 定義樹的節點
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
// 定義二元搜尋樹
class BinarySearchTree {
private:
    TreeNode* root;
    // 插入
    TreeNode* insert(TreeNode* node, int val) {
        if (node == nullptr) {//如果指標指向NULL表示沒有值，可以存放NODE
            return new TreeNode(val);//回傳
        }
        if (val < node->data) {//如果被插入的NODE>本次給的VAL
            node->left = insert(node->left, val);//大於放左下
        } else if (val > node->data) {//如果被插入的NODE<本次給的VAL
            node->right = insert(node->right, val);//小於放右下
        }
        return node;//用於遞迴
    }
    // 搜尋-------------------------------------------------------------------
    bool search(TreeNode* node, int target) {
        if (node == nullptr) return false;
        if (node->data == target) return true;
        if (target < node->data) return search(node->left, target);
        return search(node->right, target);
    }
    // 中序輸出---------------------------------------------------------------
    void inOrderTraversal(TreeNode* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }
    // 尋找最小值節點 (刪除時尋找後繼者)
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left != nullptr) {//找到
            node = node->left;
        }
        return node;
    }
    // 刪除節點-----------------------------------------------------
    TreeNode* deleteNode(TreeNode* node, int val) {
        //沒找到節點
        if (node == nullptr) return nullptr;
        //尋找目標節點
        if (val < node->data) {
            // 要刪除的值比較小，往左走
            node->left = deleteNode(node->left, val);
        } else if (val > node->data) {
            // 要刪除的值比較大，往右走
            node->right = deleteNode(node->right, val);
            //找到要刪除的
        } else {
            if (node->left == nullptr) {
                // 如果左邊是空的，把右子樹往上提
                TreeNode* temp = node->right;
                delete node; 
                return temp; // 回傳右子樹地址給父節點接住
            } else if (node->right == nullptr) {
                // 如果右邊是空的，把左子樹往上提
                TreeNode* temp = node->left;
                delete node; 
                return temp; // 回傳左子樹地址給父節點接住
            }
            // 右子樹的最小值來當繼承者
            // 1. 呼叫 findMin 進入右子樹直到找到左葉
            TreeNode* temp = findMin(node->right);
            //繼承到當前節點
            node->data = temp->data;
            //這時樹中會有兩個重複的值，所以要去右子樹把原本後繼節點刪除
            node->right = deleteNode(node->right, temp->data);
        }
        // 完成判斷回傳節點
        return node;
    }
    //------------------------------------------------------------------
public:
    BinarySearchTree() : root(nullptr) {}
    void insert(int val) {
        root = insert(root, val);
    }
    bool search(int target) {
        return search(root, target);
    }
    void displayInOrder() {
        inOrderTraversal(root);
        cout << endl;
    }
    void deleteValue(int val) {
        root = deleteNode(root, val);
    }
};
int main() {
    BinarySearchTree bst;//宣告2元搜尋樹
    int values[] = {7, 1, 4, 2, 8, 13, 12, 11, 15, 9, 5};
    int n = sizeof(values) / sizeof(values[0]);//設定N為初始TREE節點的數量
    for (int i = 0; i < n; ++i) {//加入樹中
        bst.insert(values[i]);
    }
    int key;
    cout << "請輸入要搜尋/新增的鍵值: ";
    cin >> key;//key為輸入的新增/搜尋值
    if (bst.search(key)) {
        cout << "值 " << key << " 已存在於樹中，未新增。" << endl;
    } else {
        cout << "值 " << key << " 不存在，將加入樹中。" << endl;
        bst.insert(key);
    }
    cout << "中序結果: ";
    bst.displayInOrder();
    int deleteKey;
    cout << "請輸入要刪除的數: ";
    cin >> deleteKey;
    if(bst.search(deleteKey)){
        bst.deleteValue(deleteKey);
    cout << "刪除後的樹: ";
    bst.displayInOrder();
    }
    else{
    cout << "不在樹中";
    }
    return 0;
}
