#include <iostream> 
#include <string> 
#include <vector> 

struct AnimalInfo {                    // by default, all member variables are public
    std::string name = "";
    std::string origin = "";
    int lifeExpectancy = 0;
    float weight = 0;
};

void PrintAnimalInfo(AnimalInfo info) {
    std::cout << "Name: " << info.name << std::endl;
    std::cout << "Origin: " << info.origin << std::endl;
    std::cout << "Life Expectancy: " << info.lifeExpectancy << std::endl;
    std::cout << "Weight: " << info.weight << std::endl;
}

class Animal {
    public:
        AnimalInfo GetAnimalInfo() const { return animalInfo; };           // getter which returns animalInfo
    protected:
        AnimalInfo animalInfo;
};

class Lion final : public Animal {              // "Lion" class inherits properties from Animal class
    public:
        Lion() {                        // constructor for "Lion" class
            animalInfo.name = "Lion";
            animalInfo.origin = "Africa";
            animalInfo.lifeExpectancy = 12;
            animalInfo.weight = 190;
        }
};

class Tiger final : public Animal {             // "Tiger" class inherits properties from Animal class
    public:
        Tiger() {                       // constructor for "Tiger" class
            animalInfo.name = "Tiger";
            animalInfo.origin = "Africa";
            animalInfo.lifeExpectancy = 17;
            animalInfo.weight = 220;
        }
};

class Bear final : public Animal {              // "Bear" class inherits properties from Animal class
    public:
        Bear() {                        // constructor for "Bear" class
            animalInfo.name = "Bear";
            animalInfo.origin = "Eurasia";
            animalInfo.lifeExpectancy = 22;
            animalInfo.weight = 270;
        }
};

int main() {
    std::vector<Animal*> animals;           // vector array which points to the "Animal" class
    animals.push_back(new Lion());          // inserts properties of "Lion" class into "animals" vector
    animals.push_back(new Tiger());         // inserts properties of "Tiger" class into "animals" vector
    animals.push_back(new Bear());          // inserts properties of "Bear" class into "animals" vector

    std::cout << "*** Welcome to Animal Encyclopedia! ***\n";

    bool bIsRunning = true;
    while (bIsRunning) {
        std::cout << "\n\nSelect an animal for more information:\n";

        for (size_t i = 0; i < animals.size(); ++i) {
            std::cout << i << ") " << animals[i]->GetAnimalInfo().name << std::endl;
        }

        std::cout << "\n-1) Quit Application\n";
        std::string input;
        int userChoice;
        std::cout << "\nWhich animal's info do you want? ";
        getline(std::cin, input);
        userChoice = std::stoi(input);

        if (userChoice == -1) {
            std::cout << "\n\n\nExiting Application...\nThanks for using our \"Animal Encyclopedia\"!\n\n\n";
            bIsRunning = false;
        } else if (userChoice < -1 || userChoice > ((int)animals.size() - 1)) {
            std::cout << "\n\nInvalid number! Please enter a valid number between 0 and 2, inclusive.\n";
        } else {
            std::cout << std::endl;
            PrintAnimalInfo(animals[userChoice]->GetAnimalInfo());          // print animal info
        }
    } 

    for (size_t i = 0; i < animals.size(); ++i) {           // cleanup to preserve memory
        delete animals[i];
        animals[i] = nullptr;
    }
    animals.clear();

    return 0;
}