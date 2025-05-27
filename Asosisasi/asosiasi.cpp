#include <iostream>
#include <vector>
using namespace std;

class dokter;
class pasien {     //Asosiasi
    public:
        string nama;
        vector<dokter*> daftar_dokter;
        pasien(string pNama): nama(pNama) {
            cout << "Pasien \"" << nama << "\" ada\n";
        }
        ~pasien() {
            cout << "Pasien \"" << nama << "\" tidak ada\n";
        }

        void tambahkanDokter(dokter*);
        void cetakDokter();
};

class dokter {
    public:
        string nama;
        vector<pasien*> daftar_pasien;

        dokter(string pNama): nama(pNama) {
            cout << "Dokter \"" << nama << "\" ada\n";
        }
        ~dokter() {
            cout << "Dokter \"" << nama << "\" tidak ada\n";
        }
        void tambahkanPasien(pasien*);
        void cetakPasien();
};

void pasien::tambahkanDokter(dokter* pDokter) {
    daftar_dokter.push_back(pDokter);
}

void pasien::cetakDokter() {
    cout << "Daftar dokter yang menangani pasien \"" << this->nama << "\":\n";
    for (auto& a : daftar_dokter) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

void dokter::tambahkanPasien(pasien* pPasien) {
    daftar_pasien.push_back(pPasien);
}

void dokter::cetakPasien() {
    cout << "Daftar pasien dari dokter \"" << this->nama << "\":\n";
    for (auto& a : daftar_pasien) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

int main() {
    dokter* varDokter1 = new dokter("dr. Budi");
    dokter* varDokter2 = new dokter("dr.Tono");
    pasien* varPasien1 = new pasien("Andi");
    pasien* varPasien2 = new pasien("Lia");

    varDokter1->tambahkanPasien(varPasien1);
    varDokter1->tambahkanPasien(varPasien2);
    varDokter2->tambahkanPasien(varPasien1);

    varPasien1->tambahkanDokter(varDokter1);
    varPasien2->tambahkanDokter(varDokter1);
    varPasien1->tambahkanDokter(varDokter2);

    varDokter1->cetakPasien();
    varDokter2->cetakPasien();
    varPasien1->cetakDokter();
    varPasien2->cetakDokter();

    delete varPasien1;
    delete varPasien2;
    delete varDokter1;
    delete varDokter2;
    
    return 0;
}