#include <iostream>
class ParkingSystem {
    int big, medium, small;

public:
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;

    }
    
    bool addCar(int carType) {
        switch (carType){
            case 1:
                return big > 0 and big-- >= 0;
                break;
            case 2:
                return medium > 0 and medium-- >= 0;
                break;
            case 3:
                return small > 0 and small-- >= 0;
                break;
            default:
                return false;
        }
    }
};

int main(){
    ParkingSystem* parkingSystem = new ParkingSystem(1, 1, 0);
    std::cout << parkingSystem->addCar(1) << std::endl; // return true because there is 1 available slot for a big car
    std::cout << parkingSystem->addCar(2) << std::endl;; // return true because there is 1 available slot for a medium car
    std::cout << parkingSystem->addCar(3) << std::endl;; // return false because there is no available slot for a small car
    std::cout << parkingSystem->addCar(1) << std::endl;; // return false because there is no available slot for a big car. It is already occupied.
    return 0;
}