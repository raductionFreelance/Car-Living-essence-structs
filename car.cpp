#include <iostream>
#include<string>
#include <vector>
using namespace std;

struct car{
    string color;
    string model;
    int number;
};

void addNewCar(vector<car>& cars, string color, string model, int number){
    car car(color, model, number);
    cars.push_back(car);
}

void printCar(vector<car>& cars, int number){
    for (int i=0; i<cars.size(); i++){
        if (cars[i].number==number){
            cout << cars[i].model << " " << cars[i].color << " " << cars[i].number << endl;
        }
    }
}

void editCar(vector<car>& cars, int number){
    for (int i=0; i<cars.size(); i++){
        if (cars[i].number==number){
            cout << "Введіть новий колір: ";
            cin >> cars[i].color;
            
            cout << "Введіть новий модель: ";
            cin >> cars[i].model;
            
            cout << "Введіть новий номер(5-значний): ";
            cin >> cars[i].number;
        }
    }
}

void printAllCars(vector<car>& cars){
    for (int i=0; i<cars.size(); i++){
        cout << cars[i].model << " " << cars[i].color << " " << cars[i].number << endl;
    }
}

int main(int argc, const char * argv[]) {
    vector<car> cars;
    
    addNewCar(cars, "Red", "BMW", 12345);
    addNewCar(cars, "Black", "Audi", 23456);
    addNewCar(cars, "Blue", "Toyota", 34567);
    addNewCar(cars, "White", "Mercedes", 45678);
    addNewCar(cars, "Green", "Skoda", 56789);
    addNewCar(cars, "Silver", "Tesla", 67890);
    addNewCar(cars, "Yellow", "Lada", 78901);
    addNewCar(cars, "Orange", "Mazda", 89012);
    addNewCar(cars, "Purple", "Honda", 90123);
    addNewCar(cars, "Gray", "Nissan", 11223);

    cout << "Усі авто:\n";
    printAllCars(cars);

    cout << "\nПошук авто з номером 67890:\n";
    printCar(cars, 67890);

    cout << "\nРедагування авто з номером 67890:\n";
    editCar(cars, 67890);

    cout << "\nПісля редагування:\n";
    printAllCars(cars);
    
    return 0;
}
