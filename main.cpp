#include <iostream>
#include "Enclosure.h"
#include "Fish.h"
#include "Bird.h"
#include "Mammal.h"
#include "NameException.h"
#include "PredatorException.h"
#include "MaxCapacityException.h"

using namespace std;

int main() {
    // Створення вольєра
    Enclosure enclosure1(1, 2);

    try {
        // Спроба створити тварину без назви
        Fish* fish1 = new Fish("", false, false);
    }
    catch (const NameException& e) {
        cout << e.showMessage() << endl;
        // Повторне створення винятку
        throw;
    }
    catch (const ZooException& e) {
        cout << e.showMessage() << endl;
    }

    // Перевірка виключень під час додавання тварин до вольєра
    try {
        Fish* fish2 = new Fish("Goldfish", false, false);
        Bird* bird1 = new Bird("Eagle", true, 75.0);
        Mammal* mammal1 = new Mammal("Elephant", false, "Savannah");

        enclosure1.addAnimal(fish2);
        enclosure1.addAnimal(bird1);  // Цей рядок повинен викликати виняток PredatorException
    }
    catch (const ZooException& e) {
        cout << e.showMessage() << endl;
    }

    try {
        Mammal* mammal2 = new Mammal("Lion", true, "Savannah");
        enclosure1.addAnimal(mammal2);  // Цей рядок повинен викликати виняток MaxCapacityException
    }
    catch (const ZooException& e) {
        cout << e.showMessage() << endl;
    }

    return 0;
}
