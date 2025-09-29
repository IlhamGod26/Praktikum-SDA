#include <iostream>
#include <string>
using namespace std;

struct Penerbangan {
    string kodePenerbangan;
    string tujuan;
    string status;
    Penerbangan* next;
    Penerbangan* prev;
};

int penerbanganCounter = 0;

void addLast(Penerbangan* &head, Penerbangan* &tail) {
    cin.ignore();
    Penerbangan* nodeBaru = new Penerbangan;
    cout << "Masukkan tujuan penerbangan: ";
    getline(cin, nodeBaru->tujuan);
    cout << "Masukkan status penerbangan (Tepat Waktu/Terlambat/Naik Pesawat): ";
    getline(cin, nodeBaru->status);

    if (penerbanganCounter == 0) {
        nodeBaru->kodePenerbangan = "JT-114";
    } else {
        nodeBaru->kodePenerbangan = "JT-114-" + to_string(penerbanganCounter);
    }
    penerbanganCounter++;

    nodeBaru->next = nullptr;
    nodeBaru->prev = nullptr;

    if (head == nullptr) {
        head = tail = nodeBaru;
    } else {
        tail->next = nodeBaru;
        nodeBaru->prev = tail;
        tail = nodeBaru;
    }
    cout << "Jadwal penerbangan " << nodeBaru->kodePenerbangan << " berhasil ditambahkan!\n";
}

void addMiddle(Penerbangan* &head, Penerbangan* &tail, int posisiTarget) {
    cin.ignore();
    Penerbangan* nodeBaru = new Penerbangan;
    cout << "Masukkan tujuan penerbangan: ";
    getline(cin, nodeBaru->tujuan);
    cout << "Masukkan status penerbangan (Tepat Waktu/Terlambat/Naik Pesawat): ";
    getline(cin, nodeBaru->status);

    if (penerbanganCounter == 0) {
        nodeBaru->kodePenerbangan = "JT-114";
    } else {
        nodeBaru->kodePenerbangan = "JT-114-" + to_string(penerbanganCounter);
    }
    penerbanganCounter++;

    nodeBaru->next = nullptr;
    nodeBaru->prev = nullptr;

    if (head == nullptr || posisiTarget <= 1) {
        nodeBaru->next = head;
        if (head != nullptr) head->prev = nodeBaru;
        head = nodeBaru;
        if (tail == nullptr) tail = nodeBaru;
    } else {
        int hitung = 1;
        Penerbangan* temp = head;
        while (temp->next != nullptr && hitung < posisiTarget - 1) {
            temp = temp->next;
            hitung++;
        }
        nodeBaru->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = nodeBaru;
        } else {
            tail = nodeBaru;
        }
        temp->next = nodeBaru;
        nodeBaru->prev = temp;
    }
    cout << "Jadwal penerbangan " << nodeBaru->kodePenerbangan << " berhasil disisipkan!\n";
}

void deleteFirst(Penerbangan* &head, Penerbangan* &tail) {
    if (head == nullptr) {
        cout << ">> Linked list kosong <<" << endl;
        return;
    }
    Penerbangan* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    cout << "Jadwal penerbangan " << temp->kodePenerbangan << " telah dihapus.\n";
    delete temp;
}

void editData(Penerbangan* head) {
    if (head == nullptr) {
        cout << ">> Linked list kosong <<" << endl;
        return;
    }
    cin.ignore();
    string kode;
    cout << "Masukkan kode penerbangan yang ingin diperbarui: ";
    getline(cin, kode);

    Penerbangan* temp = head;
    while (temp != nullptr && temp->kodePenerbangan != kode) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << ">> Kode penerbangan tidak ditemukan <<" << endl;
    } else {
        cout << "Status lama: " << temp->status << endl;
        cout << "Masukkan status baru (Tepat Waktu/Terlambat/Naik Pesawat): ";
        getline(cin, temp->status);
        cout << "Status penerbangan " << kode << " berhasil diubah menjadi "
             << temp->status << ".\n";
    }
}

void displayForward(Penerbangan* head) {
    if (head == nullptr) {
        cout << ">> Linked list kosong <<" << endl;
        return;
    }
    cout << "\nDaftar Jadwal Penerbangan (Dari Depan):\n";
    cout << "+---------------------------------------------------------------+\n";
    cout << "| Kode Penerbangan | Tujuan             | Status                |\n";
    cout << "+---------------------------------------------------------------+\n";
    Penerbangan* temp = head;
    while (temp != nullptr) {
        cout << "| " << temp->kodePenerbangan << string(17 - temp->kodePenerbangan.length(), ' ')
             << "| " << temp->tujuan << string(19 - temp->tujuan.length(), ' ')
             << "| " << temp->status << string(20 - temp->status.length(), ' ') << "|\n";
        temp = temp->next;
    }
    cout << "+---------------------------------------------------------------+\n";
}

void displayReverse(Penerbangan* tail) {
    if (tail == nullptr) {
        cout << ">> Linked list kosong <<" << endl;
        return;
    }
    cout << "\nDaftar Jadwal Penerbangan (Dari Belakang):\n";
    cout << "+---------------------------------------------------------------+\n";
    cout << "| Kode Penerbangan | Tujuan             | Status                |\n";
    cout << "+---------------------------------------------------------------+\n";
    Penerbangan* temp = tail;
    while (temp != nullptr) {
        cout << "| " << temp->kodePenerbangan << string(17 - temp->kodePenerbangan.length(), ' ')
             << "| " << temp->tujuan << string(19 - temp->tujuan.length(), ' ')
             << "| " << temp->status << string(20 - temp->status.length(), ' ') << "|\n";
        temp = temp->prev;
    }
    cout << "+---------------------------------------------------------------+\n";
}

void searchDetail(Penerbangan* head) {
    if (head == nullptr) {
        cout << ">> Linked list kosong <<" << endl;
        return;
    }
    cin.ignore();
    string key;
    cout << "Masukkan kode penerbangan atau tujuan: ";
    getline(cin, key);

    Penerbangan* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->kodePenerbangan == key || temp->tujuan == key) {
            cout << "\n=== Detail Penerbangan ===\n";
            cout << "Kode   : " << temp->kodePenerbangan << endl;
            cout << "Tujuan : " << temp->tujuan << endl;
            cout << "Status : " << temp->status << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (!found) cout << ">> Data tidak ditemukan <<" << endl;
}

void clearList(Penerbangan* &head, Penerbangan* &tail) {
    while (head != nullptr) {
        Penerbangan* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

void showMenu() {
    Penerbangan* head = nullptr;
    Penerbangan* tail = nullptr;
    int choice;
    do {
        cout << "\n+============================================================+\n";
        cout << "|             FLIGHT SCHEDULE SYSTEM - AEROTRACK             |\n";
        cout << "|                   [Riduan Ali - 2409106114]                |\n";
        cout << "+============================================================+\n";
        cout << "| 1. Tambah Jadwal Penerbangan                              |\n";
        cout << "| 2. Sisipkan Jadwal Penerbangan                            |\n";
        cout << "| 3. Hapus Jadwal Paling Awal                               |\n";
        cout << "| 4. Update Status Penerbangan                              |\n";
        cout << "| 5. Tampilkan Semua Jadwal                                 |\n";
        cout << "| 6. Tampilkan Semua Jadwal dari Belakang                   |\n";
        cout << "| 7. Cari Detail Jadwal Penerbangan                         |\n";
        cout << "| 0. Keluar                                                 |\n";
        cout << "+============================================================+\n";
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1: addLast(head, tail); break;
            case 2: addMiddle(head, tail, 5); break;
            case 3: deleteFirst(head, tail); break;
            case 4: editData(head); break;
            case 5: displayForward(head); break;
            case 6: displayReverse(tail); break;
            case 7: searchDetail(head); break;
            case 0:
                cout << "Terima kasih telah menggunakan AeroTrack!\n";
                clearList(head, tail);
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
        if (choice != 0) {
            cout << "Tekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }
    } while (choice != 0);
}

int main() {
    showMenu();
    return 0;
}
