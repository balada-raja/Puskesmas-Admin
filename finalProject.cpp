#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct pasien
{
    string nama;
    int usia;
};
// Prototipe
void tambahPasien(const pasien &pasien);
void prosesAntrian();
void tampilArr(string arr[], int jumlah);
void daftar(string obatBebas[], string obatResep[], int jumlahB, int jumlahR);
void ambilObat(string obatBebas[], string obatResep[], int jumlahB, int jumlahR);
int tampilkanJumlahAntrian();
void daftarAntrian();
void vaksinasi();

queue<pasien> antrian;

int main()
{
    string obatBebas[] = {"Paracetamol", "Ibuprofen", "Antihistamin", "Aspirin"};
    int jumlahB = size(obatBebas);
    string obatResep[] = {"Antibiotik", "Metformin", "Insulin", "Propranolol", "Amlodipine"};
    int jumlahR = size(obatResep);

    int i = 1;
    int j, nomorPasien;

    // antrianKesehatan antri;
    do
    {
        int pilihMenu;
        cout << "Selamat datang dilayanan kesehatan" << endl;
        cout << " ========== Menu ========== " << endl;
        cout << "1. Tambah antrian " << endl;
        cout << "2. Tampilkan Obat yang tersedia " << endl;
        cout << "3. Ambil obat " << endl;
        cout << "4. Vaksinasi " << endl;
        cout << "5. proses pengecekkan " << endl;
        cout << "6. pasien dalam antrian " << endl;
        cout << "0. Keluar " << endl;
        cout << "Pilih sesuai angka : ";
        cin >> pilihMenu;

        switch (pilihMenu)
        {
        case 0:
            i = 0;
            break;

        case 1:
            j = 1;
            while (j == 1)
            {
                string nama;
                int usia;
                cout << "Nama pasien : ";
                cin.ignore();
                getline(cin, nama);
                cout << "usia pasien : ";
                cin >> usia;

                pasien tambah = {nama, usia};

                tambahPasien(tambah);

                cout << "Tambah pasien lagi? ketik y jika iya : ";
                char c;
                cin >> c;
                if (c == 'y')
                {
                    j = 1;
                }
                else
                {
                    j = 0;
                }
            }
            break;
        case 2:
            cout << "======================================" << endl;
            daftar(obatBebas, obatResep, jumlahB, jumlahR);
            break;

        case 3:
            ambilObat(obatBebas, obatResep, jumlahB, jumlahR);
            break;

        case 4:
            cout << "======================================" << endl;
            vaksinasi();
            break;
        case 5:
            cout << "======================================" << endl;
            prosesAntrian();
            break;

        case 6:
            cout << "======================================" << endl;
            cout << "Jumlah pasien dalam antrian : " << tampilkanJumlahAntrian() << endl;
            daftarAntrian();
            break;

        default:
            cout << "Masukkan sesuai angka yang tertera" << endl;
            break;
        }
    } while (i == 1);
    cout << "---------------------------------------------------------------------" << endl;

    cin.get();
    return 0;
}

// Menambah pasien ke dalam antrian
void tambahPasien(const pasien &pasien)
{
    antrian.push(pasien);
    cout << "Pasien " << pasien.nama << " telah ditambahkan ke dalam antrian." << endl;
}

// Mengambil dan memproses pasien dari depan antrian
void prosesAntrian()
{
    if (!antrian.empty())
    {
        pasien pasien = antrian.front();
        cout << "pasien: " << pasien.nama << "(Usia : " << pasien.usia << ")" << endl;
        const int panjang = 5;
        string layanan[panjang] = {"poli umum", "Poli gigi dan mulut", "poli KIA/KB", "MTBS dan Deteksi dini tumbuh kembang balita", "Imunisasi"};
        cout << "Pilih pengecekan pasien : \n";
        cout << "1. poli umum\n"
             << "2. poli gigi dan mulut \n"
             << "3. poli KIA/KB \n"
             << "4. MTBS dan Deteksi dini tumbuh kembang balita \n"
             << "5. Imunisasi\n";
        int pilihan;
        cout << "piih sesuai nomor : ";
        cin >> pilihan;
        cout << "pasien: " << pasien.nama << "(" << pasien.usia << ")"
             << "akan diproses pada layanan : " << layanan[pilihan - 1] << endl;
        antrian.pop();
    }
    else
    {
        cout << "Antrian kosong. Tidak ada pasien untuk diproses." << endl;
    }
}

// Menampilkan jumlah pasien dalam antrian
int tampilkanJumlahAntrian()
{
    int ant = antrian.size();
    return ant;
}

void daftarAntrian()
{
    cout << "Data dalam antrian: \n";
    queue<pasien> antrianSalinan = antrian; // Membuat salinan antrian untuk menampilkan tanpa mengubah antrian asli
    while (!antrianSalinan.empty())
    {
        pasien pasien = antrianSalinan.front();
        cout << "Nama: " << pasien.nama << ", Usia: " << pasien.usia << "\n";
        antrianSalinan.pop();
    }
}

void daftar(string obatBebas[], string obatResep[], int jumlahB, int jumlahR)
{
    cout << "Daftar Obat tersedia" << endl;
    cout << "obat bebas : " << endl;
    tampilArr(obatBebas, jumlahB);
    cout << "obat Resep : " << endl;
    tampilArr(obatResep, jumlahR);
}

void tampilArr(string arr[], int jumlah)
{
    // Menampilkan elemen-elemen array
    for (int i = 0; i < jumlah; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}

void ambilObat(string obatBebas[], string obatResep[], int jumlahB, int jumlahR)
{
    if (!antrian.empty())
    {
        pasien pasien = antrian.front();
        cout << "pengambilan obat pasien atas nama " << pasien.nama << endl;
        int jumlah = 0;
        cout << "berapa obat yang ingin di ambil: ";
        cin >> jumlah;
        string obat[jumlah];
        cout << "Masukkan daftar obat yang ingin diambil : " << endl;
        for (int i = 0; i < jumlah; i++)
        {
            cout << i + 1 << ". ";
            cin >> obat[i];
        }
        bool ditemukan = false;
        for (int i = 0; i < jumlah; i++)
        {
            while (obat[i] == obatBebas[jumlahB])
            {
                ditemukan = true;
                break;
            }
            while (obat[i] == obatResep[jumlahR])
            {
                ditemukan = true;
                break;
            }
            if (ditemukan == false)
            {
                cout << "Obat " << obat[i] << " tidak tersedia \n";
            }
        }
        cout << "Pasien " << pasien.nama << " telah mengambil obat." << endl;
        antrian.pop();
    }
    else
    {
        cout << "Antrian kosong. Tidak ada pasien untuk diproses." << endl;
    }
}

void vaksinasi()
{
    if (!antrian.empty())
    {
        pasien pasien = antrian.front();
        cout << "Vaksinasi pasien atas nama " << pasien.nama << endl;
        string vaksin[] = {"polio", "hepatitis", "BCG", "campak", "rubella", "covid"};
        int jumlah = size(vaksin);
        cout << "Daftar vaksin yang tersedia : " << endl;
        tampilArr(vaksin, jumlah);
        cout << "Pilih vaksinasi : ";
        string input;
        cin >> input;
        bool ditemukan = false;
        for (int i = 0; i < jumlah; i++)
        {
            if (vaksin[i] == input)
            {
                ditemukan = true;
                cout << "Pasien " << pasien.nama << " melakukan vaksinasi" << endl;
                break;
            }
        }
        if (ditemukan == false)
        {
            cout << "vaksin " << input << "tidak tersedia \n";
        }
        antrian.pop();
    }
    else
    {
        cout << "Antrian kosong. Tidak ada pasien untuk diproses." << endl;
    }
}