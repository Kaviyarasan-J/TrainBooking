#include<iostream>
#include<time.h>
using namespace std;
class Train {
private:
    string TrainNo;
    string TrainName;
    string FromStation;
    string ToStation;
    int FixedBerth;
    int AvlBerth;
    int NextSeat;
    int Fare;
    int* CancelledSeats=new int[1001];
    int CancelCount ;
    tm* Time;
    int EnableEdit;
public:
    Train(string Trainno, string Trainname, string Fromstation, string Tostation, int Fixedberth, int fare,tm* time) {
        TrainNo = Trainno;
        TrainName = Trainname;
        FromStation = Fromstation;
        ToStation = Tostation;
        FixedBerth = AvlBerth = Fixedberth;
        Fare = fare;
        NextSeat = 1;
        CancelCount = 0;
        Time = time;
        EnableEdit = 0;
    }
    int getAvlBerth() {
        return AvlBerth;
    }
    string getTrainNo() {
        return TrainNo;
    }
    string getTrainName() {
        return TrainName;
    }
    string getFromStation() {
        return FromStation;
    }
    string getToStation() {
        return ToStation;
    }
    int getFixedBerth() {
        return FixedBerth;
    }
    int getNextSeat() {
        return NextSeat;
    }
    int getFare() {
        return Fare;
    }
    int* getCancelledSeats() {
        return CancelledSeats;
    }
    int getCancelCount() {
        return CancelCount;
    }
    tm* getTime() {
        return Time;
    }
    int getEnableEdit() {
        return EnableEdit;
    }
    void setAvlBerth(int avlBerth) {
        AvlBerth = avlBerth;
    }
    void setTrainNo(string Trainno) {
        TrainNo = Trainno;
    }
    void setTrainName(string Trainname) {
        TrainName = Trainname;
    }
    void setFromStation(string Fromstation) {
        FromStation = Fromstation;
    }
    void setToStation(string Tostation) {
        ToStation = ToStation;
    }
    void setFixedBerth(int Fixedberth) {
        FixedBerth = Fixedberth;
    }
    void setNextSeat(int nextSeat) {
        NextSeat = nextSeat;
    }
    void setFare(int fare) {
        Fare = fare;
    }
    void setCancelledSeats(int* cancelledSeats) {
        CancelledSeats = cancelledSeats;
    }
    void setCancelledSeatswithIndex(int cancelledSeat, int index) {
        CancelledSeats[index] = cancelledSeat;
    }
    void setCancelCount(int cancelCount) {
        CancelCount = cancelCount;
    }
    void setTime(tm* time) {
        Time = time;
    }
    void setEnableEdit(int enableEdit) {
        EnableEdit = enableEdit;
    }
};