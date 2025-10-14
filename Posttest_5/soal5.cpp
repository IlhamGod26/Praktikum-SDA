#include <iostream>

using namespace std;

// Struktur Node untuk Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi insert untuk membangun tree
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

/**
 * @brief Fungsi untuk melakukan pre-order traversal pada tree.
 */
void preOrderTraversal(Node* root) {

    // Base case untuk menghentikan rekursi.
    // Jika node yang dicek adalah nullptr, artinya sudah sampai ujung cabang.
    if (root == nullptr) {
        return;
    }

    // Aturan Pre-order traversal adalah (Root, Kiri, Kanan).
    // Langkah 1: Proses (cetak) data dari node saat ini terlebih dahulu.
    cout << root->data << " ";

    // Langkah 2: Panggil fungsi ini secara rekursif untuk anak kiri.
    // Ini akan menelusuri seluruh subtree kiri.
    preOrderTraversal(root->left);
    
    // Langkah 3: Setelah subtree kiri selesai, panggil fungsi ini untuk anak kanan.
    // Ini akan menelusuri seluruh subtree kanan.
    preOrderTraversal(root->right);

}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    cout << "Pre-order traversal dari tree adalah: ";
    preOrderTraversal(root); // Harusnya output: 50 30 20 40 70 60 80
    cout << endl;
    return 0;
}
