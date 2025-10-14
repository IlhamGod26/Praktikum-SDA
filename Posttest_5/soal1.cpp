#include <iostream>

using namespace std;

// Struktur Node untuk Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor untuk membuat node baru saat dipanggil
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi insert untuk membangun tree secara rekursif
Node* insert(Node* root, int val) {
    // Jika tree atau subtree kosong, buat node baru sebagai root
    if (root == nullptr) {
        return new Node(val);
    }
    // Jika nilai lebih kecil, masukkan ke subtree kiri
    if (val < root->data) {
        root->left = insert(root->left, val);
    } 
    // Jika nilai lebih besar, masukkan ke subtree kanan
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

/**
 * @brief Fungsi untuk menghitung jumlah total node dalam tree.
 */
int countNodes(Node* root) {

    // Pengecekan dasar (base case) untuk menghentikan rekursi.
    // Jika node saat ini kosong (nullptr), berarti tidak ada node di sini.
    // Maka, kembalikan nilai 0.
    if (root == nullptr) {
        return 0;
    } 
    // Jika node tidak kosong, maka proses rekursi berjalan.
    // Jumlah node dihitung dengan cara:
    // 1 (untuk node yang sedang dicek)
    // + hasil dari pemanggilan fungsi countNodes untuk anak kiri (subtree kiri)
    // + hasil dari pemanggilan fungsi countNodes untuk anak kanan (subtree kanan)
    // Proses ini akan berlanjut sampai semua node dihitung.
    else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    cout << "Jumlah total node dalam tree adalah: " << countNodes(root) << endl; // Harusnya output: 4
    return 0;
}
