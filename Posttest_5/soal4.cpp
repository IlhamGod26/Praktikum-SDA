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
 * @brief Fungsi untuk melakukan post-order traversal pada tree.
 */
void postOrderTraversal(Node* root) {

    // Base case untuk rekursi. Jika node saat ini kosong,
    // hentikan proses untuk cabang ini dan kembali.
    if (root == nullptr) {
        return;
    }

    // Aturan Post-order traversal adalah (Kiri, Kanan, Root).
    // Langkah 1: Panggil fungsi ini secara rekursif untuk anak kiri.
    // Ini akan menelusuri seluruh subtree kiri terlebih dahulu sampai ke daun.
    postOrderTraversal(root->left);

    // Langkah 2: Setelah subtree kiri selesai, panggil fungsi ini untuk anak kanan.
    // Ini akan menelusuri seluruh subtree kanan.
    postOrderTraversal(root->right);

    // Langkah 3: Setelah anak kiri dan kanan sudah dikunjungi,
    // barulah kita proses (cetak) data dari node saat ini (root dari subtree).
    cout << root->data << " ";

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
    cout << "Post-order traversal dari tree adalah: ";
    postOrderTraversal(root); // Harusnya output: 20 40 30 60 80 70 50
    cout << endl;
    return 0;
}
