#include <vector>
#include "Animal.h"
#include "PredatorException.h"
#include "MaxCapacityException.h"

class Enclosure {
private:
    int number;
    int maxAnimals;
    int currentAnimals;
    vector<Animal*> animals;

public:
    Enclosure(int number, int maxAnimals)
        : number(number), maxAnimals(maxAnimals), currentAnimals(0) {}

    int getNumber() const { return number; }
    void setNumber(int number) { this->number = number; }

    int getMaxAnimals() const { return maxAnimals; }
    void setMaxAnimals(int maxAnimals) { this->maxAnimals = maxAnimals; }

    int getCurrentAnimals() const { return currentAnimals; }

    void addAnimal(Animal* animal) {
        if (currentAnimals >= maxAnimals) {
            throw MaxCapacityException();
        }

        for (auto existingAnimal : animals) {
            if (existingAnimal->getIsPredator() != animal->getIsPredator()) {
                throw PredatorException();
            }
        }

        animals.push_back(animal);
        currentAnimals++;
    }

    void delAnimal(const string& name) {
        for (auto it = animals.begin(); it != animals.end(); ++it) {
            if ((*it)->getName() == name) {
                animals.erase(it);
                currentAnimals--;
                break;
            }
        }
    }

    Animal* findAnimal(const string& name) {
        for (auto animal : animals) {
            if (animal->getName() == name) {
                return animal;
            }
        }
        return nullptr;
    }
};
