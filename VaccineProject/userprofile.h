#ifndef USERPROFILE_H
#define USERPROFILE_H
#include <iostream>
#include <QMainWindow>

namespace Ui {
class userprofile;
}
using namespace std;

class userprofile {
  public:
    string name, surname, vaccine, effect,sex;
    int age;

 public:
    userprofile();

    userprofile( string n, string s, string v, string e, string se , int a ){
        name = n;
        surname = s;
        vaccine = v;
        effect = e;
        sex = se;
        age = a;
    }
    int get_age(){
        return age;
    }
    string get_name(){
        return name;
    }
    string get_surname(){
        return surname;
    }
    string get_vaccine(){
        return vaccine;
    }
    string get_effect(){
        return effect;
    }
    string get_sex(){
        return sex;
    }

private:
    Ui::userprofile *ui;

};

#endif // USERPROFILE_H
