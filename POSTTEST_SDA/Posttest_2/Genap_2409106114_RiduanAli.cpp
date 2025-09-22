#include <iostream>
#include <string>
using namespace std;

struct Penerbangan {
    string kodePenerbangan;
    string tujuan;
    string status;
    Penerbangan* next;
};

int penerbanganCounter = 0;

void addLast(Penerbangan *&head) {
    cin.ignore();
    Penerbangan* nodeBaru = new Penerbangan;
    cout << "Masukkan tujuan penerbangan: ";
    getline(cin, nodeBaru->tujuan);
    cout << "Masukkan status penerbangan (Tepat Waktu/Terlambat/Naik Pesawat): ";
    getline(cin, nodeBaru->status);

    if (penerbanganCounter == 0) {
        nodeBaru->kodePenerbangan = "JT-114"; // tiga digit terakhir NIM
    } else {
        nodeBaru->kodePenerbangan = "JT-114-" + to_string(penerbanganCounter);
    }
    penerbanganCounter++;

    nodeBaru->next = nullptr;

    if (head == nullptr) {
        head = nodeBaru;
    } else {
        Penerbangan* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nodeBaru;
    }
    cout << "Jadwal penerbangan " << nodeBaru->kodePenerbangan << " berhasil ditambahkan!\n";
}

void addMiddle(Penerbangan *&head, int posisiTarget) {
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

    if (posisiTarget <= 1 || head == nullptr) {
        nodeBaru->next = head;
        head = nodeBaru;
        cout << "Jadwal penerbangan " << nodeBaru->kodePenerbangan << " ditambahkan di posisi 1!\n";
    } else {
        int hitung = 1;
        Penerbangan* temp = head;
        while (temp->next != nullptr && hitung < posisiTarget - 1) {
            temp = temp->next;
            hitung++;
        }
        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
        cout << "Jadwal penerbangan " << nodeBaru->kodePenerbangan
             << " disisipkan di posisi " << posisiTarget << "!\n";
    }
}

void deleteFirst(Penerbangan *&head) {
    if (head == nullptr) {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }
    Penerbangan* temp = head;
    head = head->next;
    cout << "Jadwal penerbangan " << temp->kodePenerbangan << " telah dihapus.\n";
    delete temp;
}

void editData(Penerbangan *&head) {
    if (head == nullptr) {
        cout << ">> LinkedList kosong <<" << endl;
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

void display(Penerbangan *head) {
    if (head == nullptr) {
        cout << ">> Linked list kosong <<" << endl;
        return;
    }
    cout << "\nDaftar Jadwal Penerbangan:\n";
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


void clearList(Penerbangan *&head) {
    Penerbangan* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    cout << "Linked list berhasil dikosongkan." << endl;
}

void showMenu() {
    Penerbangan* head = nullptr;
    int choice;
    do {
        cout << "\n+============================================================+\n";
        cout << "|             FLIGHT SCHEDULE SYSTEM - AEROTRACK             |\n";
        cout << "|              [Riduan Ali - 2409106114]                     |\n";
        cout << "+============================================================+\n";
        cout << "| 1. Tambah Jadwal Penerbangan                               |\n";
        cout << "| 2. Sisipkan Jadwal Penerbangan                             |\n";
        cout << "| 3. Hapus Jadwal Paling Awal                                |\n";
        cout << "| 4. Update Status Penerbangan                               |\n";
        cout << "| 5. Tampilkan Semua Jadwal                                  |\n";
        cout << "| 0. Keluar                                                  |\n";
        cout << "+============================================================+\n";
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1: addLast(head); break;
            case 2: addMiddle(head, 5); break; 
            case 3: deleteFirst(head); break;
            case 4: editData(head); break;
            case 5: display(head); break;
            case 0:
                cout << "Terima kasih telah menggunakan AeroTrack!\n";
                clearList(head);
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
