#include "OrgChart.hpp"

namespace ariel{

    OrgChart::Person::Person(string name){
        this-> name = name;
    };

    OrgChart &OrgChart::add_root(string name){
        if(this-> root_exist){
            this-> root.name = name;
        }
        else{
            this-> root = Person(name);
        }
        this-> root_exist = true;
        return *this;
    };

    OrgChart &OrgChart::add_sub(string father, string son){
        return *this;
    };

    ostream &operator<<(ostream &out, const OrgChart &chart){
        return out;
    };
    
    OrgChart::Iterator OrgChart::begin(){
        return Iterator();
    };
    
    OrgChart::Iterator OrgChart::end(){ 
        return Iterator();
    };
    
    OrgChart::Iterator OrgChart::begin_level_order(){
        return Iterator();
    };
    
    OrgChart::Iterator OrgChart::end_level_order(){
        return Iterator();
    };
    
    OrgChart::Iterator OrgChart::begin_reverse_order(){
        return Iterator();
    };
    
    OrgChart::Iterator OrgChart::reverse_order(){
        return Iterator();
    };
    
    OrgChart::Iterator OrgChart::begin_preorder(){
        return Iterator();
    };
    
    OrgChart::Iterator OrgChart::end_preorder(){
        return Iterator();
    };


    OrgChart::Iterator::Iterator(Person *root, string order){};

    bool operator!=(const OrgChart::Iterator &first, const OrgChart::Iterator &second){
        return false;
    };

    OrgChart::Iterator &OrgChart::Iterator::operator++(){
        return *this;
    };

    OrgChart::Iterator &OrgChart::Iterator::operator++(int){
        return *this;
    };

    string *OrgChart::Iterator::operator->(){
        return &curr_var->name;
    };
    
    string OrgChart::Iterator::operator*(){
        return "";
    };
    
    int OrgChart::Iterator::size(){
        return 0;
    };

};
