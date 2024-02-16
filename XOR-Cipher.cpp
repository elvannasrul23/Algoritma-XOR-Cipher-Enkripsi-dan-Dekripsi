#include <iostream>
#include <string>
#include <sstream>

using namespace std; // Penggunaan namespace std

string xor_encrypt_decrypt(const string &input, const string &key) {
    string output = "";
    for (size_t i = 0; i < input.size(); ++i) {
        output += input[i] ^ key[i % key.size()];
    }
    return output;
}

string string_to_ascii(const string &input) {
    string output = "";
    for (char c : input) {
        output += to_string(static_cast<int>(c)) + " ";
    }
    return output;
}

int main() {
    string text;
    string key = "secret"; // Kunci tetap statis dalam contoh ini

    int choice;
    cout << "Pilih tindakan:\n";
    cout << "1. Enkripsi\n";
    cout << "2. Dekripsi\n";
    cout << "Masukkan pilihan (1 atau 2): ";
    cin >> choice;
    cin.ignore(); // Membersihkan buffer stdin

    string decrypted_text; // Pindahkan inisialisasi di sini

    switch (choice) {
        case 1: {
            cout << "Masukkan teks plaintext: ";
            getline(cin, text);
            cout << "Teks terenkripsi: " << string_to_ascii(xor_encrypt_decrypt(text, key)) << endl;
            break;
        }
        case 2: {
            cout << "Masukkan teks ciphertext (dalam bentuk nilai ASCII dipisahkan spasi): ";
            getline(cin, text);
            istringstream iss(text);
            int ascii_value;
            decrypted_text = ""; // Pindahkan inisialisasi di sini
            while (iss >> ascii_value) {
                decrypted_text += static_cast<char>(ascii_value);
            }
            cout << "Teks terdekripsi: " << xor_encrypt_decrypt(decrypted_text, key) << endl;
            break;
        }
        default:
            cout << "Pilihan tidak valid.\n";
            break;
    }

    return 0;
}
