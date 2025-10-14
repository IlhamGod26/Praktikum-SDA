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
 * @brief Fungsi untuk mencari nilai terkecil dalam sebuah BST.
 */
int findMinValue(Node* root) {
    // --- LENGKAPI KODE DI SINI ---
    
    // Pertama, cek apakah tree-nya kosong.
    // Jika ya, tidak ada nilai minimum, jadi kita kembalikan -1 sesuai permintaan soal.
    if (root == nullptr) {
        return -1;
    }
    
    // Buat pointer 'current' yang dimulai dari root.
    Node* current = root;
    
    // Sesuai sifat BST, nilai terkecil selalu ada di node paling kiri.
    // Jadi, kita lakukan perulangan untuk menelusuri ke kiri terus-menerus
    // selama anak kiri dari node 'current' masih ada (tidak nullptr).
    while (current->left != nullptr) {
        // Pindahkan pointer 'current' ke anak kirinya.
        current = current->left;
    }
    
    // Setelah perulangan berhenti, 'current' akan menunjuk ke node paling kiri,
    // yang berarti itu adalah node dengan nilai terkecil.
    // Kembalikan data dari node tersebut.
    return current->data;
    
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl; // Harusnya output: 20
    return 0;
}
