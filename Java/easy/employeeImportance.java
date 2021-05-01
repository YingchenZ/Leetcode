import java.util.*;


class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
};


class Solution {
    public static int getImportance(List<Employee> employees, int id) {
        HashMap<Integer , Employee> empTable = new HashMap<>();

        for(int i = 0; i < employees.size(); i++){
            empTable.put(employees.get(i).id, employees.get(i));
        }

        Queue<Integer> list = new LinkedList<>();
        list.add(id);
        int total = 0;
        while(list.size() != 0){
            int empId = list.poll();
            total += empTable.get(empId).importance;
            List<Integer> sub = empTable.get(empId).subordinates;
            for(int i = 0; i < sub.size(); i++){
                list.add(sub.get(i));
            }
        }
        return total;
    }

    // Employee List = [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]]
    // For Employee 1  Total importance = 11

    public static void main(String[] args){
        Employee emp1 = new Employee();
        emp1.id = 1;
        emp1.importance = 5;
        emp1.subordinates = Arrays.asList(2,3);
    
        Employee emp2 = new Employee();
        emp2.id = 2;
        emp2.importance = 3;
        emp2.subordinates = Arrays.asList();
    
        Employee emp3 = new Employee();
        emp3.id = 3;
        emp3.importance = 3;
        emp3.subordinates = Arrays.asList();
        
        List<Employee> test = Arrays.asList(emp1, emp2, emp3);
        int id = 1;
        System.out.println("Employee List = [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]]");
        System.out.println("For Employee " + id + "\tTotal importance = " + getImportance(test, id));
    }
}