#include<iostream>
#include<string>
using namespace std;
class Book{
private:
    string UserName;
    string TrainNumber;
    int PNR;
    string* Name = new string[101];
    string* Age = new string[101];
    string* Mobile = new string[101];
    int* SeatNo = new int[101];
    int NoOfTickets;
    string* Status;
public:
    Book(string username,string Trainnumber,int pnr,string* name, string* age,string* mobile, int* seatNo,int noOfTickets,string* status) {
        UserName = username;
        TrainNumber = Trainnumber;
        PNR = pnr;
        Name = name;
        Age = age;
        Mobile = mobile;
        SeatNo = seatNo;
        Status = status;
        NoOfTickets = noOfTickets;
    }
    string getUserName() {
        return UserName;
    }
    string getTrainNumber() {
        return TrainNumber;
    }
    int getPNR() {
        return PNR;
    }
    string getName(int index) {
        return Name[index];
    }
    string getAge(int index) {
        return Age[index];
    }
    string getMobile(int index) {
        return Mobile[index];
    }
    int getSeatNo(int index) {
        return SeatNo[index];
    }
    int getNoOfTickets() {
        return NoOfTickets;
    }
    string getStatus(int index) {
        return Status[index];
    }
    void setUserName(string username) {
        UserName = username;
    }
    void setTrainNumber(string Trainnumber) {
        TrainNumber = Trainnumber;
    }
    void setName(string name,int index) {
        Name[index] = name;
    }
    void setAge(string age,int index) {
        Age[index] = age;
    }
    void setMobile(string mobile, int index) {
        Mobile[index] = mobile;
    }
    void setSeatNo(int seatNo,int index) {
        SeatNo[index] = seatNo;
    }
    void setPNR(int pnr) {
        PNR = pnr;
    }
    void setStatus(string status,int index) {
        Status[index] = status;
    }
};