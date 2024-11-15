#include "iostream"
#include "string"
#include "vector"
#include "limits"

#include "custom_lib.h"
// Incude other libs to perform operations

using namespace std;
using customlib::contains;
using customlib::get_validated_int;


const string EXIT_MESSAGE =         "Programı kapatmak için lütfen <enter>'a basın...\n";
const string INVALID_OPERATION =    "Geçersiz modül!\n";
const string MENU_MSG =             "Merhabalar, bu program içerisinde barındırdığı bir çok algoritma ve veri yapısını test edebilmeniz için geliştirilmiştir.\n"
                                    "İçerik:\n"
                                    "|-->Data Structures\n"
                                    "|\t|--> (1) Linked List\n"
                                    "|\t|--> (2) Queue\n"
                                    "|\t|--> (3) Stack\n"
                                    "|-->Sorting Algorithms\n"
                                    "|\t|--> (4) Bubble Sort\n"
                                    "|\t|--> (5) Merge Sort\n"
                                    "|-->Search Algorithms\n"
                                    "|\t|--> (6) Binary Search\n\n"
                                    "Çıkış için (0)\n";

int main(){
    vector<int> operations = {0, 1, 2, 3, 4, 5, 6};
    int op = 1, key = 1;

    while (key) {
        cout << MENU_MSG;
        do {
            op = get_validated_int("Lütfen bir modül seçiniz: ");
            if (!contains(operations, op))
                cout << INVALID_OPERATION;
            else break;
        } while (true);
        
        switch (op) {
            case 0:
                cout << EXIT_MESSAGE;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                key = 0;
                break;
            case 1:
                cout << "İşlem 1" << endl << endl;
                break;
            case 2:
                cout << "İşlem 2" << endl << endl;
                break;
            case 3:
                cout << "İşlem 3" << endl << endl;
                break;
            case 4:
                cout << "İşlem 4" << endl << endl;
                break;
            case 5:
                cout << "İşlem 5" << endl << endl;
                break;
            case 6:
                cout << "İşlem 6" << endl << endl;
                break;
            default:
                ;
        }
    }
    return 0;
}