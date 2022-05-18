/* 
    each Person will containe name, pointer to his father and to all of his chilldern
*/

#pragma once
#include <string>
#include <vector>


using namespace std;

namespace ariel{

    class OrgChart{

        class Person{

            public:
                //constructors
                Person(){}; //default
                Person(string name);
                
                //instance variables
                string name;
                Person *father;
                vector<Person *> chilldern;

                //methods
                void add_child(Person *child);
                void set_name(string name);
                string get_name();
                Person *get_father();
                vector<Person *> get_chilldren();
        };

        public:
            class Iterator{

            public:
                //constructors
                Iterator(){};  //default
                Iterator(Person *root, string order);

                size_t curr_pos;
                Person *curr_var;
                int size();

                //operators
                Iterator &operator++();
                Iterator &operator++(int);
                string operator*();
                friend bool operator!=(const Iterator &first, const Iterator &second);
                string *operator->();
            };

            OrgChart() {};
            Person root;
            bool root_exist;
            OrgChart &add_root(string name);
            OrgChart &add_sub(string father, string son);
            friend ostream &operator<<(ostream &out, const OrgChart &chart);

            Iterator begin();
            Iterator end();
            Iterator begin_level_order();
            Iterator end_level_order();
            Iterator begin_reverse_order();
            Iterator reverse_order();
            Iterator begin_preorder();
            Iterator end_preorder();
    };

};
