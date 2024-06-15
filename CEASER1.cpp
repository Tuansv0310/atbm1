#include <iostream>
#include <string>

using namespace std;

// Hàm mã hóa Caesar
string maHoa(string message, int key) {
    string encryptedMessage = "";
    for (size_t i = 0; i < message.length(); ++i) {
        char c = message[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            encryptedMessage += static_cast<char>((c - base + key) % 26 + base);
        } else {
            encryptedMessage += c;
        }
    }
    return encryptedMessage;
}

// Hàm gi?i mã Caesar
string giaiMa(string message, int key) {
    return maHoa(message, 26 - key); // Ð? gi?i mã, s? d?ng khóa ngu?c l?i
}

int main() {
    string message;
    int key;

    while (true) {
        cout << "Lua chon chuc nang:\n";
        cout << "1. Nhap thong diep can ma hoa\n";
        cout << "2. Nhap khoa K\n";
        cout << "3. Ma hoa thong diep\n";
        cout << "4. Giai ma thong diep\n";
        cout << "5. Thoat\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap thong diep can ma hoa: ";
                cin.ignore(); // B? qua ký t? xu?ng dòng còn l?i trong b? d?m
                getline(cin, message);
                break;
            case 2:
                cout << "Nhap khoa K: ";
                cin >> key;
                break;
            case 3:
                if (message.empty() || key == 0) {
                    cout << "Vui long nhap thong diep va khoa truoc khi ma hoa.\n";
                } else {
                    cout << "Thong diep duoc ma hoa: " << maHoa(message, key) << endl;
                }
                break;
            case 4:
                if (message.empty() || key == 0) {
                    string ms;
                    cout << "Nhap thong diep duoc ma hoa: ";
                    cin.ignore(); // B? qua ký t? xu?ng dòng còn l?i trong b? d?m
                    getline(cin, ms);
                    cout << "Nhap khoa k: ";
                    cin >> key;
                    cout << "Thong diep ban dau: " << giaiMa(ms, key) << endl;
                } else {
                    cout << "Thong diep ban dau: " << giaiMa(maHoa(message, key), key) << endl;
                }
                break;
            case 5:
                cout << "Tam biet!\n";
                return 0;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    }

    return 0;
}

