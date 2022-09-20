#include<iostream>
using namespace std;
class Cancel {
private:
    string UserName;
    string TrainNumber;
    string Name;
    string Age;
    int SeatNo;
    string Mobile;
    int PNR;
public:
    Cancel(string username,string Trainnumber,string name, string age, int seatNo,string mobile, int pnr) {
        UserName = username;
        TrainNumber = Trainnumber;
        Name = name;
        Age = age;
        SeatNo = seatNo;
        Mobile = mobile;
        PNR = pnr;
    }
    string getUserName() {
        return UserName;
    }
    string getTrainNumber() {
        return TrainNumber;
    }
    string getName() {
        return Name;
    }
    string getAge() {
        return Age;
    }
    int getSeatNo() {
        return SeatNo;
    }
    string getMobile() {
        return Mobile;
    }
    int getPNR() {
        return PNR;
    }
    void setUserName(string username) {
        UserName = username;
    }
    void setTrainNumber(string Trainnumber) {
        TrainNumber = Trainnumber;
    }
    void setName(string name) {
        Name = name;
    }
    void setAge(string age) {
        Age = age;
    }
    void setSeatNo(int seatNo) {
        SeatNo = seatNo;
    }
    void setMobile(string mobile) {
        Mobile = mobile;
    }
    void setPNR(int pnr) {
        PNR = pnr;
    }
};