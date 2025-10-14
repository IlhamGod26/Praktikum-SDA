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
 * @brief Fungsi untuk mencari nilai terbesar dalam sebuah BST.
 */
int findMaxValue(Node* root) {
 
    // Sama seperti mencari nilai terkecil, kita cek dulu apakah tree-nya kosong.
    // Jika kosong, kembalikan -1.
    if (root == nullptr) {
        return -1;
    }

    // Buat pointer 'current' yang dimulai dari root.
    Node* current = root;

    // Kebalikan dari nilai terkecil, nilai terbesar pada BST selalu ada di node paling kanan.
    // Kita lakukan perulangan untuk menelusuri ke kanan terus-menerus
    // selama anak kanan dari node 'current' masih ada (tidak nullptr).
    while (current->right != nullptr) {
        // Pindahkan pointer 'current' ke anak kanannya.
        current = current->right;
    }
    
    // Setelah perulangan berhenti, 'current' menunjuk ke node paling kanan.
    // Node ini berisi nilai terbesar dalam tree.
    // Kembalikan datanya.
    return current->data;

}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);
    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl; // Harusnya output: 80
    return 0;
}
