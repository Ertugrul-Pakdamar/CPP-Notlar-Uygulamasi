#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string dosyaAdi, icerik;
    char secim;

    cout << "Kaydedilecek dosyanin adini girin: ";
    cin >> dosyaAdi;

    ifstream dosyaOku(dosyaAdi);
    if (dosyaOku.is_open()) {
        while (getline(dosyaOku, icerik)) {
            cout << icerik << endl;
        }
        dosyaOku.close();
    } else {
        cout << "Dosya bulunamadi. Yeni bir dosya olusturulacak." << endl;
    }

    cout << "Metin eklemek ister misiniz? (E/H): ";
    cin >> secim;

    if (secim == 'E' || secim == 'e') {
        cout << "Metni girin (Satir sonu icin 'q' girin):\n";
        cin.ignore();
        while (getline(cin, icerik)) {
            if (icerik == "q")
                break;
            icerik += '\n';
            ofstream dosyaYaz(dosyaAdi, ios::app);
            dosyaYaz << icerik;
            dosyaYaz.close();
        }
        cout << "Metin kaydedildi." << endl;
    }

    cout << "Program sona eriyor." << endl;

    return 0;
}
