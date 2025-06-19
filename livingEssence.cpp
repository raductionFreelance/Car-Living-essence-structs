#include <iostream>
#include<string>
#include <vector>
using namespace std;

union AdditionalData {
    int fly_speed;
    bool hoosed;
    int iq;
};

struct essence{
    int number; //по порядку
    int speed;
    string type;
    string color;
    
    AdditionalData data;
};

void editInfo(vector<essence>& essences, int number){
    cout << "Введіть швидкіть руху: ";
    cin >> essences[number-1].speed;
    
    cout << "Введіть тип: ";
    cin >> essences[number-1].type;
    
    cout << "Введіть колір: ";
    cin >> essences[number-1].color;
    
    if (essences[number-1].type == "птах") {
        cout << "Введіть швидкість польоту: ";
        cin >> essences[number-1].data.fly_speed;
    }else if (essences[number-1].type == "худоба"){
        cout << "Введіть чи аарнокопитне: ";
        cin >> essences[number-1].data.hoosed;
    }else if (essences[number-1].type == "людина"){
        cout << "Введіть рівень iq: ";
        cin >> essences[number-1].data.iq;
    }
}

void print(vector<essence>& essences){
    for (int i=0; i<essences.size(); i++){
        cout << essences[i].speed << " " << essences[i].type << " " <<  essences[i].color << " ";
        if (essences[i].type == "птах") {
            cout << essences[i].data.fly_speed << endl;
        }else if (essences[i].type == "худоба"){
            cout << essences[i].data.hoosed << endl;
        }else if (essences[i].type == "людина"){
            cout << essences[i].data.iq << endl;
        }
    }
}

void search(vector<essence>& essences, AdditionalData& data, string type){
    for (int i=0; i<essences.size(); i++){
        if (essences[i].type != type) continue;
        
        if ("птах" == type) {
            if (data.fly_speed==essences[i].data.fly_speed){
                cout << essences[i].speed << " " << essences[i].type<< " " << essences[i].color << " " << essences[i].data.fly_speed << endl;
            }
        }else if ("худоба" == type){
            if (data.hoosed==essences[i].data.hoosed){
                cout << essences[i].speed << " " << essences[i].type << essences[i].color << " " << essences[i].data.hoosed << endl;
            }
        }else if ("людина" == type){
            if (data.iq==essences[i].data.iq){
                cout << essences[i].speed << " " << essences[i].type << essences[i].color << " " << essences[i].data.iq << endl;
            }
        }
    }
}

int main() {
    vector<essence> essences = {
        {1, 60, "птах",   "жовтий",    {.fly_speed = 120}},
        {2, 55, "птах",   "синій",     {.fly_speed = 110}},
        {3, 50, "птах",   "червоний",  {.fly_speed = 100}},
        {4, 30, "худоба", "бурий",     {.hoosed = true}},
        {5, 25, "худоба", "чорний",    {.hoosed = false}},
        {6, 28, "худоба", "білий",     {.hoosed = true}},
        {7,  5, "людина", "зелений",   {.iq = 130}},
        {8,  6, "людина", "срібний",   {.iq = 110}},
        {9,  4, "людина", "рожевий",   {.iq = 140}},
        {10,40,"худоба", "сіро-бура",  {.hoosed = false}}
    };

    cout << "Початковий список:\n";
    print(essences);

    cout << "\nРедагуємо елемент №3 (введіть нові дані):\n";
    editInfo(essences, 3);

    cout << "\nПісля редагування:\n";
    print(essences);

    AdditionalData key{};
    key.fly_speed = 110;
    search(essences, key, "птах");
    key.hoosed    = true;
    search(essences, key, "худоба");
    key.iq        = 130;
    search(essences, key, "людина");

    return 0;
}

