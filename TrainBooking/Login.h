#include<iostream>
using namespace std;
class Login {
private:
    string Name;
    string Mobile;
    string Password;
    string Email;
public:
    Login(string name, string mobile, string password, string email) {
        Name = name;
        Mobile = mobile;
        Password = password;
        Email = email;
    }
    string getName() {
        return Name;
    }
    string getMobile() {
        return Mobile;
    }
    string getPassword() {
        return Password;
    }
    string getEmail() {
        return Email;
    }
    void setName(string name) {
        Name = name;
    }
    void setMobile(string mobile) {
        Mobile = mobile;
    }
    void setPassword(string password) {
        Password = password;
    }
    void setEmail(string email) {
        Email = email;
    }

};