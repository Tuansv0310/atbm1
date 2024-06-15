#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Hàm tính UCLN
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Hàm tìm phần tử nghịch đảo của một số trong modulo 26
int nghichDaoModulo(int a) {
    for (int x = 1; x < 26; x++) {
        if ((a * x) % 26 == 1)
            return x;
    }
    return -1;
}

// Hàm mã hóa Affine
string maHoaAffine(string message, int a, int b) {
    string encryptedMessage = "";
    for (char& c : message) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            encryptedMessage += static_cast<char>(((a * (c - base) + b) % 26) + base);
        } else {
            encryptedMessage += c;
        }
    }
    return encryptedMessage;
}

// Hàm giải mã Affine
string giaiMaAffine(string message, int a, int b) {
    string decryptedMessage = "";
    int a_inv = nghichDaoModulo(a);
    for (char& c : message) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            decryptedMessage += static_cast<char>((a_inv * ((c - base - b + 26) % 26)) % 26 + base);
        } else {
            decryptedMessage += c;
        }
    }
    return decryptedMessage;
}

int main() {
    string message;
    int a, b;

    while (true) {
        cout << "Lua chon chuc nang:\n";
        cout << "1. Nhap thong diep can ma hoa\n";
        cout << "2. Nhap khoa K (a, b)\n";
        cout << "3. Ma hoa thong diep\n";
        cout << "4. Giai ma thong diep\n";
        cout << "5. Thoat\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap thong diep can ma hoa: ";
                cin.ignore();
                getline(cin, message);
                break;
            case 2:
                cout << "Nhap khoa a (thoa man GCD(a, 26) = 1): ";
                cin >> a;
                while (gcd(a, 26) != 1) {
                    cout << "a khong thoa man GCD(a, 26) = 1. Nhap lai: ";
                    cin >> a;
                }
                cout << "Nhap khoa b: ";
                cin >> b;
                break;
            case 3:
                if (message.empty() || gcd(a, 26) != 1) {
                    cout << "Vui long nhap thong diep va khoa hop le truoc khi ma hoa.\n";
                } else {
                    cout << "Thong diep duoc ma hoa: " << maHoaAffine(message, a, b) << endl;
                }
                break;
            case 4:
                if (message.empty() || gcd(a, 26) != 1) {
                    string ms;
                    cout << "Nhap thong diep duoc ma hoa: ";
                    cin.ignore();
                    getline(cin, ms);
                    cout << "Nhap khoa a (thoa man GCD(a, 26) = 1): ";
                    cin >> a;
                    while (gcd(a, 26) != 1) {
                        cout << "a khong thoa man GCD(a, 26) = 1. Nhap lai: ";
                        cin >> a;
                    }
                    cout << "Nhap khoa b: ";
                    cin >> b;
                    cout << "Thong diep ban dau: " << giaiMaAffine(ms, a, b) << endl;
                } else {
                    cout << "Thong diep ban dau: " << giaiMaAffine(maHoaAffine(message, a, b), a, b) << endl;
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
