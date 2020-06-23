#include<iostream>
#include <string>
using namespace std;

class Mughals {
    protected:
    string name;
    int age;
    public:
        virtual void getData(int cardNumber)
        {
            cout << "from base class..." << endl;
        }
        virtual void putData()
        {
            cout << "from base class..." << endl;
        }
};

class Royal: public Mughals {
    int rashanCardNumber, battlesWon;

    public:
        void getData(int cardNumber) {
            rashanCardNumber = cardNumber;
            cout << "Please Enter Your Name : ";
            cin.ignore();
            getline(cin, name);
            while(name.length() < 1 || name.length() > 100 ) {
                cout << "Please Enter Your Name Again : ";
                cin.ignore();
                getline(cin, name);
            }
            cout << "Please Enter Your Age : ";
            cin >> age;
            while(age < 1 || age > 80 ) {
                cout << "Please Enter Your Age Again: ";
                cin >> age;
            }
            cout << "Please Enter Battles Won : ";
            cin >> battlesWon;
            while(battlesWon < 1 || battlesWon > 1000 ) {
                cout << "Please Enter Battles Won Again : ";
                cin >> battlesWon;
            }
        }
        void putData() {
            cout << name << " " << age << " " << battlesWon << " " << rashanCardNumber << endl;
        }
};

class Ordinary: public Mughals {
    int amount[6], rashanCardNumber;
    public:
        void getData(int cardNumber) {
            rashanCardNumber = cardNumber;
            cout << "Please Enter Your Name : ";
            cin.ignore();
            getline(cin, name);
            while(name.length() < 1 || name.length() > 100 ) {
                
                cout << "Please Enter Your Name Again : ";
                cin.ignore();
                getline(cin, name);
            }
            cout << "Please Enter Your Age : ";
            cin >> age;
            while(age < 1 || age > 80 ) {
                cout << "Please Enter Your Age Again: ";
                cin >> age;
            }
            cout << "Please Enter Amount in kgs of rice : ";
            cin >> amount[0];
            while(amount[0] < 1 || amount[0] > 1000 ) {
                cout << "Please Enter Amount in kgs of rice Again : ";
                cin >> amount[0];
            }
            cout << "Please Enter Amount in kgs of pulse : ";
            cin >> amount[1];
            while(amount[1] < 1 || amount[1] > 1000 ) {
                cout << "Please Enter Amount in kgs of pulse Again : ";
                cin >> amount[1];
            }
            cout << "Please Enter Amount in kgs of chicken : ";
            cin >> amount[2];
            while(amount[2] < 1 || amount[2] > 1000 ) {
                cout << "Please Enter Amount in kgs of chicken Again : ";
                cin >> amount[2];
            }
            cout << "Please Enter Amount in kgs of barley : ";
            cin >> amount[3];
            while(amount[3] < 1 || amount[3] > 1000 ) {
                cout << "Please Enter Amount in kgs of barley Again : ";
                cin >> amount[3];
            }
            cout << "Please Enter Amount in kgs of wheat : ";
            cin >> amount[4];
            while(amount[4] < 1 || amount[4] > 1000 ) {
                cout << "Please Enter Amount in kgs of wheat Again : ";
                cin >> amount[4];
            }cout << "Please Enter Amount in kgs of vegetable : ";
            cin >> amount[5];
            while(amount[5] < 1 || amount[5] > 1000 ) {
                cout << "Please Enter Amount in kgs of vegetable Again : ";
                cin >> amount[5];
            }
            
        }
        void putData() {
            cout << name << " " << age << " ";
            for(int i = 0; i < 6; i++) {
                cout << amount[i] << " ";
            }
            cout << rashanCardNumber << endl;
        }
};

int main() {
    int n;
    Mughals **p;
    cout << "Please enter number of inputs : ";
    cin >> n;
    p = new Mughals*[n];
    
    for(int i = 0; i < n; i++) {
        int type;
        cout << "Please enter type (1 for Royal and 2 for Ordinary): ";
        cin >> type;
        if(type == 1) {
            p[i] = new Royal();  
        } else {
            p[i] = new Ordinary();  
        }
        p[i]->getData(type);
    }
    cout << endl << endl;
    for (int i = 0; i < n; i++) {
        p[i]->putData();
    }
    return 0;
}