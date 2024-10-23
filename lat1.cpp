#include <iostream>  // Untuk menggunakan fungsi input-output
#define SIZE 6       // Mendefinisikan ukuran maksimum dari queue

using namespace std;

// Kelas CircularQueue untuk implementasi queue
class CircularQueue {
private:
    int items[SIZE], front, rear;  // Array queue dan penunjuk front serta rear

public:
    CircularQueue() {  // Konstruktor untuk menginisialisasi queue
        front = -1;    // Awalnya front di-set ke -1 menandakan queue kosong
        rear = -1;     // rear juga di-set ke -1
    }

    bool isFull() {  // Fungsi untuk memeriksa apakah queue penuh
        if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
            return true;  // Jika kondisi terpenuhi, queue penuh
        }
        return false;  // Jika tidak, queue tidak penuh
    }

    bool isEmpty() {  // Fungsi untuk memeriksa apakah queue kosong
        if (front == -1) {
            return true;  // Jika front == -1, queue kosong
        }
        return false;  // Jika tidak, queue tidak kosong
    }

    void enqueue(int element) {  // Fungsi untuk menambahkan elemen ke queue
        if (isFull()) {
            cout << "Antrian penuh" << endl;  // Jika penuh, cetak pesan dan return
        } else {
            if (front == -1) front = 0;  // Jika queue awalnya kosong, set front ke 0
            rear = (rear + 1) % SIZE;    // Menghitung posisi rear secara circular
            items[rear] = element;       // Menyimpan elemen ke dalam queue
            cout << "Nomor antrian anda " << element << endl;  // Menampilkan elemen yang dimasukkan
        }
    }

    int dequeue() {  // Fungsi untuk menghapus elemen dari queue
        int element;
        if (isEmpty()) {
            cout << "Antrian Kosong";  // Jika kosong, cetak pesan dan return
            return (-1);
        } else {
            element = items[front];  // Mengambil elemen dari posisi front
            if (front == rear) {  // Jika hanya ada satu elemen
                front = -1;  // Mengosongkan queue
                rear = -1;
            } else {
                front = (front + 1) % SIZE;  // Mengupdate posisi front secara circular
            }
            cout << "Nomor antrian " << element << " dipanggil" << endl;
			cout << endl;  // Menampilkan elemen yang dihapus
            return (element);
        }
    }

    void display() {  // Fungsi untuk menampilkan elemen-elemen dalam queue
        int i;
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;  // Jika kosong, cetak pesan
            cout << endl;
        } else {
            cout << "Daftar antrian : ";
            for (i = front; i != rear; i = (i + 1) % SIZE)
                cout << items[i] << " ";  // Menampilkan elemen-elemen queue secara circular
	            cout << items[i] << endl;  // Menampilkan elemen rear
	            cout << endl;
        }
    }
    
     void clear() {
        front = -1;
        rear = -1;
        cout << "Antrian telah dikosongkan." << endl;
    }
};


int main() {
    CircularQueue q;  // Membuat objek CircularQueue
	
	int pilih, element;
	
	do {
		cout << "PROGRAM SISTEM ANTRIAN" << endl;
		cout << "======================" << endl;
		cout << "Menu : " << endl; 
		cout << "1.Ambil antrian" << endl;
		cout << "2.Panggil antrian" << endl;
		cout << "3.Cek antrian" << endl;
		cout << "4.Kosongkan antrian" << endl;
		cout << "5.Exit" << endl; 
		
		cout << "Masukan pilihan menu : ";
		cin >> pilih;
		
		
		switch(pilih) {
			case 1:
				cout << "Pilih No.Antrian(1-6): ";
				cin >> element;
				q.enqueue(element);
				cout << endl;
				break;
			case 2:
				q.dequeue();
				break;		
			case 3:
				q.display();
				break;
			case 4:
				q.clear();
				break;
			case 5:
				cout << "Anda keluar dari program antrian";
				break;
			default:
				break;
		};
	} while (pilih != 5);
	
    return 0;
}

