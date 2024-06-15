#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Hàm tính d?nh th?c c?a ma tr?n 2x2
int dinhThuc(vector<vector<int> >& matrix) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

// Hàm tìm ph?n t? ngh?ch d?o c?a m?t s? trong modulo 26
int nghichDaoModulo(int a) {
    for (int x = 1; x < 26; x++) {
        if ((a * x) % 26 == 1)
            return x;
    }
    return -1;
}

// Hàm mã hóa thông di?p
string maHoaThongDiep(string message, vector<vector<int> >& key) {
    string encryptedMessage = "";
    for (size_t i = 0; i < message.length(); i += 2) {
        int x = message[i] - 'A';
        int y = message[i + 1] - 'A';
        int newX = (key[0][0] * x + key[0][1] * y) % 26;
        int newY = (key[1][0] * x + key[1][1] * y) % 26;
        encryptedMessage += ('A' + newX);
        encryptedMessage += ('A' + newY);
    }
    return encryptedMessage;
}

// Hàm gi?i mã thông di?p
string giaiMaThongDiep(string message, vector<vector<int> >& key) {
    string decryptedMessage = "";
    int det = dinhThuc(key);
    int invDet = nghichDaoModulo(det);
    // Tính ma tr?n ngh?ch d?o c?a ma tr?n khóa
    vector<vector<int> > invKey = {{key[1][1], -key[0][1]}, {-key[1][0], key[0][0]}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            invKey[i][j] *= invDet;
            invKey[i][j] = (invKey[i][j] % 26 + 26) % 26; // Ð?m b?o k?t qu? không âm
        }
    }
    decryptedMessage = maHoaThongDiep(message, invKey);
    return decryptedMessage;
}

int main() {
    string message;
    vector<vector<int> > key(2, vector<int>(2));

    while (true) {
        cout << "Lua chon chuc nang:\n";
        cout << "1. Nhap thong diep can ma hoa\n";
        cout << "2. Nhap ma tran khoa K\n";
        cout << "3. Ma hoa thong diep\n";
        cout << "4. Giai ma thong diep\n";
        cout << "5. Thoat\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap thong diep can ma hoa (chi su dung chu cai in hoa): ";
                cin.ignore();
                getline(cin, message);
                break;
            case 2:
                cout << "Nhap ma tran khoa K (2x2):\n";
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        cin >> key[i][j];
                    }
                }
                break;
            case 3:
                if (message.empty() || (key[0][0] == 0 && key[0][1] == 0 && key[1][0] == 0 && key[1][1] == 0)) {
                    cout << "Vui long nhap thong diep va khoa truoc khi ma hoa.\n";
                } else {
                    cout << "Thong diep duoc ma hoa: " << maHoaThongDiep(message, key) << endl;
                }
                break;
            case 4:
                if (message.empty() || (key[0][0] == 0 && key[0][1] == 0 && key[1][0] == 0 && key[1][1] == 0)) {
                    string ms;
                    cout << "Nhap thong diep duoc ma hoa: ";
                    cin.ignore();
                    getline(cin, ms);
                    cout << "Nhap ma tran khoa K (2x2):\n";
                    for (int i = 0; i < 2; i++) {
                        for (int j = 0; j < 2; j++) {
                            cin >> key[i][j];
                        }
                    }
                    cout << "Thong diep ban dau: " << giaiMaThongDiep(ms, key) << endl;
                } else {
                    cout << "Thong diep ban dau: " << giaiMaThongDiep(maHoaThongDiep(message, key), key) << endl;
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
