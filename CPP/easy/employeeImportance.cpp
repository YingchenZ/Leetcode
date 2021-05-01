#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

class Employee {
public:
    int id;
    int importance;
    std::vector<int> subordinates;
};


int getImportance(std::vector<Employee*> employees, int id) {
    std::unordered_map<int , Employee*> table = {};
    for(int i = 0; i < employees.size(); i++){
        table[employees[i]->id] = employees[i];
    }
    std::queue<int> list = {};
    int total = 0;
    list.push(id);
    while(!list.empty()){
        int empId = list.front();
        list.pop();
        Employee* emp = table[empId];
        total += emp->importance;
        for(int id : emp->subordinates){
            list.push(id);
        }
    }
    return total;

}

// Employee List = [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]]
// For Employee 1  Total importance = 11

int main(){
    Employee* emp1 = new Employee();
    emp1->id = 1;
    emp1->importance = 5;
    emp1->subordinates = {2,3};

    Employee* emp2 = new Employee();
    emp2->id = 2;
    emp2->importance = 3;
    emp2->subordinates = {};

    Employee* emp3 = new Employee();
    emp3->id = 3;
    emp3->importance = 3;
    emp3->subordinates = {};

    std::vector<Employee*> test = {emp1, emp2, emp3};
    int id = 1;
    std::cout << "Employee List = [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]]" << std::endl;
    std::cout << "For Employee " << id << "\tTotal importance = "<< getImportance(test, id)<< std::endl;
    return 0;
}