#include <iostream>
#include<Windows.h>
#include<time.h>
#include<list>

#include"Train.h"
#include"Login.h"
#include"Book.h"
#include"Cancel.h"

using namespace std;

list<Login>AdminDetails;
list<Login>UserDetails;
list<Train>TrainDetails;
list<Book>BookedDetails;
list<Cancel>CancelledDetails;

list<Login>::iterator login;
list<Train>::iterator train;
list<Book>::iterator book;
list<Cancel>::iterator cancel;

void Create();
void LoginAcc();
void Admin();
void User();

int FindAdmin(string);
int FindUser(string);

void UpdateTrain();
void AddTrain();
void EditTrain();
void RemoveTrain();
void RemoveTrain(string);

void ExtendBerth();
void FindTrain();
void SearchTrain();

int FindTrainFunc(string);
int SearchTrainFunc(string, string, string, int);
void UpdateStatus(string,string);

int getPNRNO();
int getSeatNo(string);

void ViewAllTrains();
void ViewAllBooked();
void ViewAllCancelled();
void ViewAllBookings();

void IncrementAvlBerth(string );
void AddToCancelledSeats(string , int );

void BookTicket();
void CancelTicket();

int CheckTime(tm*);

void Mainmenu();
void Processmenu();

string USERNAME;
int choice;
int PNR = 1001;


int main() {
    int choice;
    system("color a");
    while (1) {
        cout << "\t\t\t\t\t\t\t\t[ Train Ticket Booking System ]" << endl << endl;
        cout << "\t\t\t\t\t=====================================================" << endl;
        cout << "\t\t\t\t\t\t\t[1] Create" << endl;
        cout << "\t\t\t\t\t\t\t[2] Login" << endl;
        cout << "\t\t\t\t\t\t\t[3] Exit" << endl;
        cout << "\t\t\t\t\t=====================================================" << endl;
        cout << "option>>";
        cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            Create();
            Mainmenu();
            break;
        case 2:
            system("cls");
            LoginAcc();
            Mainmenu();
            break;
        case 3:
            system("cls");
            cout << "\t\t\t\t\t\t[ Thank You ]" << endl;
            return 0;
        default:
            cout << "\t\t\t\t\t\t[ Enter Valid Option ]" << endl;
            break;
        }
    }
}


void Processmenu() {
repeat:
    cout << endl;
    int choice;
    cout << "[Go to Process Menu Press 1]" << endl << "Option>>";
    cin >> choice;
    if (choice == 1) {
        system("cls");
        return;
    }
    else {
        goto repeat;
    }
}
void Mainmenu() {
repeat:
    cout << endl;
    int choice;
    cout << "[Go to Main Menu Press 1]" << endl << "Option>>";
    cin >> choice;
    if (choice == 1) {
        system("cls");
        return;
    }
    else {
        goto repeat;
    }
}
int* DeleteFirstElement(int* arr, int Size) {
    int* newArr = new int[Size - 1];
    for (int i = 1; i < Size; i++) {
        newArr[i - 1] = arr[i];
    }
    return newArr;
}

void Create() {
    cout << "\t\t\t\t\t\t\t\t[ Create ]" << endl << endl;
    string Name, Mobile, Password, EMail,Passcode;
    cout << "\t\t\t\t\t\t\t[ Select Type ]" << endl << endl;
    cout << "\t\t\t\t\t\t[1] - Admin       [2] - User   " << endl << endl;
    cout << "option>>";
    cin >> choice;
    system("cls");
    switch (choice) {
    case 1:
    repeatAdmin:
        cout << endl << "[ Enter Name ]: ";
        cin >> Name;
        if (FindAdmin(Name) == 1) {
            cout << "[ Try Different Name ]" << endl;
            goto repeatAdmin;
        }
        cout << "[ Enter Mobile ]: ";
        cin >> Mobile;
        cout << "[ Enter Password ]: ";
        cin >> Password;
        cout << "[ Enter E-Mail ]: ";
        cin >> EMail;
        repeatpasscode:
        cout << "Enter Passcode: ";
        cin >> Passcode;
        if (Passcode == "admin") {
            AdminDetails.push_back(Login(Name, Mobile, Password, EMail));
            cout << "\t\t\t\t\t\t\t[ Admin Account Created Successfull ]" << endl;
            return;
        }
        else {
            cout << "\t\t\t\t\t\t\t[ You Have Entered Wrong Passcode ]" << endl;
            repeat:
            cout << "[1] Try Again " << endl;
            cout << "[2] Main Menu " << endl;
            cin >> choice;
            if (choice == 1) {
                goto repeatpasscode;
            }
            else if (choice == 2) {
                return;
            }
            goto repeat;
        }
    case 2:
    repeatUser:
        cout << endl << "[ Enter Name ]: ";
        cin >> Name;
        if (FindUser(Name) == 1) {
            cout << "[ Try Different Name ]" << endl;
            goto repeatUser;
        }
        cout << "[ Enter Mobile ]: ";
        cin >> Mobile;
        cout << "[ Enter Password ]: ";
        cin >> Password;
        cout << "[ Enter E-Mail ]: ";
        cin >> EMail;
        UserDetails.push_back(Login(Name, Mobile, Password, EMail));
        cout << "\t\t\t\t\t\t\t\t[ Created Successfully ]" << endl;
        return;
    default:
        cout << "\t\t\t\t\t\t\t[ Enter Valid Option ]" << endl;
    }

}
void LoginAcc() {
    cout << "\t\t\t\t\t\t\t\t[ Login ]" << endl << endl;
    cout << "\t\t\t\t\t\t\t[ Select Type ]" << endl << endl;
    cout << "\t\t\t\t\t\t[1] - Admin       [2] - User   " << endl;
    cout << "option>>";
    cin >> choice;
    system("cls");
    string Password;
    cout << "[ Enter User Name ]: ";
    cin >> USERNAME;
    cout << "[ Enter Password ]: ";
    cin >> Password;
    if (choice == 1) {
        for (login = AdminDetails.begin(); login != AdminDetails.end(); login++) {
            if (login->getName() == USERNAME && login->getPassword() == Password) {
                cout << "\t\t\t\t\t\t\t[ Login Successfully ]" << endl;
                system("cls");
                Admin();
                return;
            }
        }
    }
    if (choice == 2) {
        for (login = UserDetails.begin(); login != UserDetails.end(); login++) {
            if (login->getName() == USERNAME && login->getPassword() == Password) {
                cout << "\t\t\t\t\t\t\t[ Login Successfully ]" << endl;
                system("cls");
                User();
                return;
            }
        }
    }
    cout << "[ User Name or Pasword Incorrect ]" << endl;

}
void Admin() {
    cout << "\t\t\t\t\t\t\t\t\t\t[ Admin Mode ]" << endl << endl;
    while (1) {
        cout << "\t\t\t\t\t===========================================================================" << endl;
        cout << "\t\t\t\t\t\t\t\t[1] Add Train" << endl;
        cout << "\t\t\t\t\t\t\t\t[2] Extend Train Berth" << endl;
        cout << "\t\t\t\t\t\t\t\t[3] Find Train" << endl;
        cout << "\t\t\t\t\t\t\t\t[4] View All Trains" << endl;
        cout << "\t\t\t\t\t\t\t\t[5] View All Bookings" << endl;
        cout << "\t\t\t\t\t\t\t\t[6] View All CancelledBookings" << endl;
        cout << "\t\t\t\t\t\t\t\t[7] Remove Train" << endl;
        cout << "\t\t\t\t\t\t\t\t[8] Update Train Details " << endl;
        cout << "\t\t\t\t\t\t\t\t[9] Edit Train " << endl;
        cout << "\t\t\t\t\t\t\t\t[10] Log out" << endl;
        cout << "\t\t\t\t\t=====================================================================================" << endl;
        cout << "option>>";
        cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            AddTrain();
            Processmenu();
            break;
        case 2:
            system("cls");
            ExtendBerth();
            Processmenu();
            break;
        case 3:
            system("cls");
            FindTrain();
            Processmenu();
            break;
        case 4:
            system("cls");
            ViewAllTrains();
            Processmenu();
            break;
        case 5:
            system("cls");
            ViewAllBooked();
            Processmenu();
            break;
        case 6:
            system("cls");
            ViewAllCancelled();
            Processmenu();
            break;
        case 7:
            system("cls");
            RemoveTrain();
            Processmenu();
            break;
        case 8:
            system("cls");
            UpdateTrain();
            Processmenu();
            break;
        case 9:
            system("cls");
            EditTrain();
            Processmenu();
            break;
        case 10:
            system("cls");
            return;
        default:
            system("cls");
            cout << "\t\t\t\t\t\t\t[ Enter Valid Option ]" << endl;
        }
    }
}
void User() {
    cout << "\t\t\t\t\t\t\t\t\t\t[ User ]" << endl << endl;
    while (1) {
        cout << "\t\t\t\t\t===========================================================================" << endl;
        cout << "\t\t\t\t\t\t\t\t[1] Search Train" << endl;
        cout << "\t\t\t\t\t\t\t\t[2] Book Ticket" << endl;
        cout << "\t\t\t\t\t\t\t\t[3] Cancel Ticket" << endl;
        cout << "\t\t\t\t\t\t\t\t[4] View All Book History" << endl;
        cout << "\t\t\t\t\t\t\t\t[5] Log Out" << endl;
        cout << "\t\t\t\t\t===========================================================================" << endl;
        cout << "option>>";
        cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            SearchTrain();
            Processmenu();
            break;
        case 2:
            system("cls");
            BookTicket();
            Processmenu();
            break;
        case 3:
            system("cls");
            CancelTicket(); 
            Processmenu();
            break;
        case 4:
            system("cls");
            ViewAllBookings();
            Processmenu();
            break;
        case 5:
            system("cls");
            return;
        default:
            cout << "\t\t\t\t\t\t\t\t[ Enter Valid Option ]" << endl;
        }
    }
}

int FindAdmin(string UserName) {
    for (login = AdminDetails.begin(); login != AdminDetails.end(); login++) {
        if (login->getName() == UserName) {
            return 1;
        }
    }
    return 0;
}
int FindUser(string UserName) {
    for (login = UserDetails.begin(); login != UserDetails.end(); login++) {
        if (login->getName() == UserName) {
            return 1;
        }
    }
    return 0;
}

int getSeatNo(string Trainnumber) {
    for (train = TrainDetails.begin(); train != TrainDetails.end(); train++) {
        if (train->getTrainNo() == Trainnumber) {
            int* arr = train->getCancelledSeats();
            int Seatno, Size = train->getCancelCount();
            int AvlBerth = train->getAvlBerth();
            if (Size > 0) {
                Seatno = arr[0];
                arr = DeleteFirstElement(arr, Size);
                train->setCancelledSeats(arr);
                train->setCancelCount(Size - 1);
                train->setAvlBerth(AvlBerth - 1);
                return Seatno;
            }
            int nextSeat = train->getNextSeat();
            train->setNextSeat(nextSeat + 1);
            train->setAvlBerth(AvlBerth - 1);
            return nextSeat;
        }
    }
    return 0;
}
int getPNRNO() {
    return PNR++;
}

int CheckTime(tm* Time) {
    time_t curr_time;
    curr_time = time(NULL);
    tm* curr = localtime(&curr_time);
    if ((curr->tm_year+1900) < Time->tm_year) {      //Year  
        return 1;
    }
    else if ((curr->tm_year + 1900) > Time->tm_year) {      //Year      
        return 0;
    }
    else if (((curr->tm_year + 1900) == Time->tm_year) && (curr->tm_mon+1) < Time->tm_mon) {    //month    
        return 1;
    }
    else if (((curr->tm_year + 1900) == Time->tm_year) && (curr->tm_mon + 1) > Time->tm_mon) {    //month  
        return 0;
    }
    else if ((curr->tm_mon + 1) == Time->tm_mon && curr->tm_mday < Time->tm_mday) {       //Day
        return 1;
    }
    else if ((curr->tm_mon + 1) == Time->tm_mon && curr->tm_mday > Time->tm_mday) {       //Day 
        return 0;
    }
    else if (curr->tm_mday == Time->tm_mday && curr->tm_hour < Time->tm_hour) {      //Hour   
        return 1;
    }
    else if (curr->tm_mday == Time->tm_mday && curr->tm_hour < Time->tm_hour) {      //Hour    
        return 0;
    }
    else if(curr->tm_hour == Time->tm_hour && curr->tm_min < Time->tm_min) {      //min  
        return 1;
    }
    else {
        return 0;
    }
}

void UpdateTrain() {
    for (train = TrainDetails.begin(); train != TrainDetails.end(); train++) {
        tm* Time = train->getTime();
        string Trainnumber = train->getTrainNo();
        if (CheckTime(Time) == 0) {
            UpdateStatus(Trainnumber, "Travel");
            cout << "[ Message Updated ]" << endl;
            cout << "[ Train Number ]: " << Trainnumber << endl;
            train->setEnableEdit(1);
        }
    }
    cout << "\t\t\t\t\t\t\t[ Updated Successfully ]" << endl;
    return;
}

void BookTicket() {
    cout << "\t\t\t\t\t\t\t[ Book ]" << endl << endl;
    string Trainnumber, FromStation, ToStation;
    int NoOfTickets;
    cout << "[ Enter Train Number ]: ";
    cin >> Trainnumber;
    cout << "[ Enter From Station ]: ";
    cin >> FromStation;
    cout << "[ Enter To Station ]: ";
    cin >> ToStation;
    cout << "[ Enter No.Of.Tickets ]: ";
    cin >> NoOfTickets;
    cout << endl;
    
    if (SearchTrainFunc(Trainnumber, FromStation, ToStation, NoOfTickets) == 1) {
        string* Name = new string[NoOfTickets];
        string* Age = new string[NoOfTickets];
        string* Mobile = new string[NoOfTickets];
        string* Status = new string[NoOfTickets];
        int* SeatNo = new int[NoOfTickets];
        int PNR;
        for (int index = 0; index < NoOfTickets; index++) {
            cout << endl << "[ Enter Passenger Detail : " << index + 1 << " ]" << endl << endl;
            cout << "[ Enter Name ]: ";
            cin >> Name[index];
            cout << "[ Enter Age ]: ";
            cin >> Age[index];
            cout << "[ Enter Mobile ]: ";
            cin >> Mobile[index];
            Status[index] = "Booked";
            SeatNo[index] = getSeatNo(Trainnumber);
        }
        PNR = getPNRNO();
        BookedDetails.push_back(Book(USERNAME, Trainnumber, PNR, Name, Age, Mobile, SeatNo, NoOfTickets, Status));
        cout << "\t\t\t\t\t\t\t[ Booked Successfully ]" << endl;
    }
    else {
        cout << "\t\t\t\t\t\t\t[ Booking Not Successfull ]" << endl;
    }
}
void CancelTicket() {
    cout << "\t\t\t\t\t\t\t[ Cancel Ticket ]" << endl << endl;
    int PNR;
    string Name, Mobile;
    cout << "[ Enter PNR ]: ";
    cin >> PNR;
    cout << "[ Enter Passenger Name ]: ";
    cin >> Name;
    cout << "[ Enter Mobile ]: ";
    cin >> Mobile;
    cout << endl;
    for (book = BookedDetails.begin(); book != BookedDetails.end(); book++) {
        if (book->getUserName() == USERNAME && book->getPNR() == PNR) {
            for (int i = 0; i < book->getNoOfTickets(); i++) {
                if (book->getName(i) == Name && book->getMobile(i) == Mobile) {
                    cout << "\t\t\t\t\t========================================================================================" << endl;
                    cout << "\t\t\t\t\t\t\t\t[ Passenger List : " << i + 1 << " ]" << endl;
                    cout << "\t\t\t\t\t\t\t[ Train No ]: " << book->getTrainNumber() << endl;
                    cout << "\t\t\t\t\t\t\t[ Name ]: " << book->getName(i) << endl;
                    cout << "\t\t\t\t\t\t\t[ Age ]: " << book->getAge(i) << endl;
                    cout << "\t\t\t\t\t\t\t[ Mobile ]: " << book->getMobile(i) << endl;
                    cout << "\t\t\t\t\t\t\t[ Seat No ]: " << book->getSeatNo(i) << endl;
                    cout << "\t\t\t\t\t\t\t[ Status ]: " << book->getStatus(i) << endl;
                    cout << "\t\t\t\t\t========================================================================================" << endl << endl;
                    cout << "[ Press 1 -> To Confirm ] " << endl;
                    cout << "option>>";
                    cin >> choice;
                    if (choice == 1) {
                        book->setStatus("Cancelled", i);
                        IncrementAvlBerth(book->getTrainNumber());
                        AddToCancelledSeats(book->getTrainNumber(), book->getSeatNo(i));
                        CancelledDetails.push_back(Cancel(USERNAME, book->getTrainNumber(), Name, book->getAge(i), book->getSeatNo(i), Mobile, PNR));
                        cout << "\t\t\t\t\t\t\t[ Cancelled Successfully ]" << endl;
                        return;
                    }
                }
            }
            if (choice != 0) {
                cout << "\t\t\t\t\t\t\t[ Cancellation Not Successfull ]" << endl;
                return;
            }
        }
    }
    cout << "\t\t\t\t\t\t\t[ Data Not Found ]" << endl;
}
void ViewAllBookings() {
    cout << "\t\t\t\t\t\t\t[ View All Bookings ]" << endl;
    int index = 1;
    for (book = BookedDetails.begin(); book != BookedDetails.end(); book++) {
        if (book->getUserName() == USERNAME) {
            cout << "\t\t\t\t\t========================================Book.No: " << index++ << " ===================================" << endl;
            cout << "\t\t\t\t\t\t\t[ PNR ]: " << book->getPNR() << endl;
            cout << "\t\t\t\t\t\t\t[ Train No ]: " << book->getTrainNumber() << endl;
            cout << "\t\t\t\t\t\t\t[ No Of Tickets ]: " << book->getNoOfTickets() << endl;
            for (int i = 0; i < book->getNoOfTickets(); i++) {
                cout << "\t\t\t\t\t=================================================================================================" << endl;
                cout << "\t\t\t\t\t\t\t\t[ Passenger List : " << i + 1 << " ]" << endl;
                cout << "\t\t\t\t\t\t\t[ Name ]: " << book->getName(i) << endl;
                cout << "\t\t\t\t\t\t\t[ Age ]: " << book->getAge(i) << endl;
                cout << "\t\t\t\t\t\t\t[ Mobile ]: " << book->getMobile(i) << endl;
                cout << "\t\t\t\t\t\t\t[ Seat No ]: " << book->getSeatNo(i) << endl;
                cout << "\t\t\t\t\t\t\t[ Status ]: " << book->getStatus(i) << endl;
                cout << "\t\t\t\t\t=================================================================================================" << endl << endl;
            }
            cout << "\t\t\t\t\t===========================================================================================================" << endl;
        }
    }
    if (index == 1) {
        cout << "\t\t\t\t\t\t\t[ No Booking Found ]" << endl;
    }
}  

void AddTrain() {
    cout << "\t\t\t\t\t\t\t[ Add Train ]" << endl << endl;
    string Trainnumber, Trainname, FromStation, ToStation;
    tm* settime = new tm;
    int FixedBerth, Fare;
    cout << "[ Enter Train Number ]: ";
    cin >> Trainnumber;
    if (FindTrainFunc(Trainnumber) == 1) {
        cout << "[ Train Already Added ]" << endl;
        return;
    }
    cout << "[ Enter Train Name ]: ";
    cin >> Trainname;
    cout << "[ Enter From Station ]: ";
    cin >> FromStation;
    cout << "[ Enter To Station ]: ";
    cin >> ToStation;
    cout << "[ Enter Fixed Berth ]: ";
    cin >> FixedBerth;
    cout << "[ Enter Fare ]: ";
    cin >> Fare;
    cout << "[ Enter Departure Date (dd/mm/yy) ] : " ;
    cin >> settime->tm_mday >> settime->tm_mon >> settime->tm_year;
    cout << "[ Enter Departure Time (HH:MM:SS) ] : ";
    cin >> settime->tm_hour >> settime->tm_min >> settime->tm_sec;
    TrainDetails.push_back(Train(Trainnumber, Trainname, FromStation, ToStation, FixedBerth, Fare,settime));
    cout << "\t\t\t\t\t\t\t[ Added Successfully ]" << endl;
}
void EditTrain() {
    cout << "\t\t\t\t\t\t\t[ Edit Train ]" << endl<<endl;
    string Trainnumber;
    cout << "[ Enter Train No. ]: ";
    cin >> Trainnumber;
    for (train = TrainDetails.begin(); train != TrainDetails.end(); train++) {
        if (train->getTrainNo() == Trainnumber) {
            if (train->getEnableEdit() == 0) {
                cout << "\t\t\t\t\t\t\t[ Unable To Edit this Train ]" << endl;
                return;
            }
            string Trainname, FromStation, ToStation;
            int FixedBerth, Fare;
            tm* settime = new tm;
            cout << "[ Enter Train Name ]: ";
            cin >> Trainname;
            train->setTrainName(Trainname);
            cout << "[ Enter From Station ]: ";
            cin >> FromStation;
            train->setFromStation(Trainname);
            cout << "[ Enter To Station ]: ";
            cin >> ToStation;
            train->setToStation(ToStation);
            cout << "[ Enter Fixed Berth ]: ";
            cin >> FixedBerth;
            train->setFixedBerth(FixedBerth);
            cout << "[ Enter Fare ]: ";
            cin >> Fare;
            train->setFare(Fare);
            cout << "[ Enter Departure Date (dd/mm/yy) ] : ";
            cin >> settime->tm_mday >> settime->tm_mon >> settime->tm_year;
            cout << "[ Enter Departure Time (HH:MM:SS) ] : ";
            cin >> settime->tm_hour >> settime->tm_min >> settime->tm_sec;
            train->setTime(settime);
            train->setEnableEdit(0);
            cout << "\t\t\t\t\t\t\t[ Edited Successfully ]" << endl;
            return;
        }
    }
    cout << "\t\t\t\t\t\t\t[ Train Not Found ]" << endl;
}
void ExtendBerth() {
    cout << "\t\t\t\t\t\t\t[ Extend Train Berth ]" << endl << endl;
    string Trainnumber;
    int flag = 0,AvlBerth,ActBerth,ExBerth,TotalBerth;
    cout << "[ Enter Train Number ]: ";
    cin >> Trainnumber;
    for (train = TrainDetails.begin(); train != TrainDetails.end(); train++) {
        if (train->getTrainNo() == Trainnumber) {
            ActBerth = train->getFixedBerth();
            AvlBerth = train->getAvlBerth();
            cout << "\t\t[ Available Berth ]: " << AvlBerth << endl;
            cout << "[ Enter No.of Berth to be Extended ]: ";
            cin >> ExBerth;
            TotalBerth = ActBerth + ExBerth;
            train->setFixedBerth(TotalBerth);
            train->setAvlBerth(AvlBerth + ExBerth);
            cout << "\t\t\t\t\t\t\t[ Extended Successfully ]" << endl;
            flag = 1;
        }
    }
    if (flag == 0) {
        cout << "\t\t\t\t\t\t\t[ Train Number Not Found ]" << endl;
    }
}
void RemoveTrain() {
    cout << "\t\t\t\t\t\t\t[ Remove Train ]" << endl << endl;
    string Trainnumber;
    cout << "[ Enter Train Number ]: ";
    cin >> Trainnumber;
    cout << endl;
    for (train = TrainDetails.begin(); train != TrainDetails.end(); train++) {
        if (train->getTrainNo() == Trainnumber) {
            tm* Time = train->getTime();
            cout << "\t\t\t\t\t=============================================================================" << endl;
            cout << "\t\t\t\t\t\t\t[ Train Name ]: " << train->getTrainName() << endl;
            cout << "\t\t\t\t\t\t\t[ From Station ]: " << train->getFromStation() << endl;
            cout << "\t\t\t\t\t\t\t[ To Station ]: " << train->getToStation() << endl;
            cout << "\t\t\t\t\t\t\t[ Departure Date (dd/mm/yy) ]: ( " << Time->tm_mday << "/" << Time->tm_mon << "/" << Time->tm_year << " )" << endl;
            cout << "\t\t\t\t\t\t\t[ Depature Time (H:M) ]: (" << Time->tm_hour << ":" << Time->tm_min << " )" << endl;
            cout << "\t\t\t\t\t\t\t[ Berth Available ]: " << train->getAvlBerth() << endl;
            cout << "\t\t\t\t\t\t\t[ Fare ]: " << train->getFare() << endl;
            cout << "\t\t\t\t\t=============================================================================" << endl << endl;
            cout << "[ Press 1 -> Confirm ]" << endl;
            cin >> choice;
            if (choice == 1) {
                UpdateStatus(Trainnumber,"Train Cancelled");
                TrainDetails.erase(train);
                cout << "\t\t\t\t\t\t\t[ Train Removed SuccessFully ]" << endl;
            }
            return;
        }
    }
    cout << " \t\t\t\t\t\t\t[ Train Not Found ] " << endl;
}

void FindTrain() {
    cout << "\t\t\t\t\t\t\t[ Find Train ]" << endl << endl;
    string Trainnumber;
    int flag = 0;
    cout << "[ Enter Train Number ]: ";
    cin >> Trainnumber;
    for (train = TrainDetails.begin(); train != TrainDetails.end(); train++) {
        if (train->getTrainNo() == Trainnumber) {
            tm* Time = train->getTime();
            cout << "\t\t\t\t\t==========================================================================" << endl << endl;
            cout << "\t\t\t\t\t\t\t[ Train Number ]: " << train->getTrainNo() << endl;
            cout << "\t\t\t\t\t\t\t[ Train Name ]: " << train->getTrainName() << endl;
            cout << "\t\t\t\t\t\t\t[ From Station ]: " << train->getFromStation() << endl;
            cout << "\t\t\t\t\t\t\t[ To Station ]: " << train->getToStation() << endl;
            cout << "\t\t\t\t\t\t\t[ Departure Date (dd/mm/yy) ]: ( " << Time->tm_mday<<"/"<< Time->tm_mon<<"/" << Time->tm_year <<" )" << endl;
            cout << "\t\t\t\t\t\t\t[ Depature Time (H:M) ]: (" << Time->tm_hour << ":" << Time->tm_min <<" )"<< endl;
            cout << "\t\t\t\t\t\t\t[ Berth Available ]: " << train->getAvlBerth() << endl;
            cout << "\t\t\t\t\t\t\t[ Fare ]: " << train->getFare() << endl;
            cout << "\t\t\t\t\t==========================================================================" << endl << endl;
            flag = 1;
        }
    }
    if (flag == 0) {
        cout << "\t\t\t\t\t\t\t[ Train Not Found ]" << endl;
    }
}
void SearchTrain() {
    cout << "\t\t\t\t\t\t\t[ Search Train ]" << endl << endl;
    string FromStation, ToStation;
    int NoOfTickets, index = 1;
    cout << "[ Enter From Station ]: ";
    cin >> FromStation;
    cout << "[ Enter To Station ]: ";
    cin >> ToStation;
    cout << "[ Enter No. Of Tickets ]: ";
    cin >> NoOfTickets;
    cout << endl;
    for (train = TrainDetails.begin(); train != TrainDetails.end(); train++) {
        if (train->getFromStation() == FromStation && train->getToStation() == ToStation && train->getFixedBerth() >= NoOfTickets) {
            tm* Time = train->getTime();
            cout << "\t\t\t\t\t===================Train Detail : " << index++ << "  ======================" << endl;
            cout << "\t\t\t\t\t\t\t[ Train Number ]: " << train->getTrainNo() << endl;
            cout << "\t\t\t\t\t\t\t[ Train Name ]: " << train->getTrainName() << endl;
            cout << "\t\t\t\t\t\t\t[ From Station ]: " << train->getFromStation() << endl;
            cout << "\t\t\t\t\t\t\t[ To Station ]: " << train->getToStation() << endl;
            cout << "\t\t\t\t\t\t\t[ Departure Date (dd/mm/yy) ]: ( " << Time->tm_mday << "/" << Time->tm_mon << "/" << Time->tm_year << " )" << endl;
            cout << "\t\t\t\t\t\t\t[ Depature Time (H:M) ]: (" << Time->tm_hour << ":" << Time->tm_min << " )" << endl;
            cout << "\t\t\t\t\t\t\t[ Berth Available ]: " << train->getAvlBerth() << endl;
            cout << "\t\t\t\t\t\t\t[ Fare ]: " << train->getFare() << endl;
            cout << "\t\t\t\t\t=================================================================================== " << endl << endl;
        }
    }
    if (index == 1) {
        cout << "\t\t\t\t\t\t\t[ No Trains Available For This Search Criteria ]" << endl;
    }
}

int FindTrainFunc(string Trainnumber) {
    for (train = TrainDetails.begin(); train != TrainDetails.end(); train++) {
        if (train->getTrainNo() == Trainnumber) {
            return 1;
        }
    }
    return 0;
}
int SearchTrainFunc(string Trainnumber, string FromStation, string ToStation, int NoOfTickets) {
    for (train = TrainDetails.begin(); train != TrainDetails.end(); train++) {
        if (train->getFromStation() == FromStation && train->getToStation() == ToStation &&
            train->getAvlBerth() >= NoOfTickets && train->getTrainNo() == Trainnumber && CheckTime(train->getTime())==1) {
            return 1;
        }
    }
    return 0;
}

void ViewAllTrains() {
    cout << "\t\t\t\t\t\t\t[ View All Trains ]" << endl << endl;
    int index = 1;
    for (train = TrainDetails.begin(); train != TrainDetails.end(); train++) {
        tm* Time = train->getTime();
        cout << "\t\t\t\t\t===================Train Detail : " << index++ << "  ======================" << endl;
        cout << "\t\t\t\t\t\t\t[ Train Number ]: " << train->getTrainNo() << endl;
        cout << "\t\t\t\t\t\t\t[ Train Name ]: " << train->getTrainName() << endl;
        cout << "\t\t\t\t\t\t\t[ From Station ]: " << train->getFromStation() << endl;
        cout << "\t\t\t\t\t\t\t[ To Station ]: " << train->getToStation() << endl;
        cout << "\t\t\t\t\t\t\t[ Departure Date (dd/mm/yy) ]: ( " << Time->tm_mday << "/" << Time->tm_mon << "/" << Time->tm_year << " )" << endl;
        cout << "\t\t\t\t\t\t\t[ Depature Time (H:M) ]: (" << Time->tm_hour << ":" << Time->tm_min << " )" << endl;
        cout << "\t\t\t\t\t\t\t[ Berth Available ]: " << train->getAvlBerth() << endl;
        cout << "\t\t\t\t\t\t\t[ Fare ]: " << train->getFare() << endl;
        cout << "\t\t\t\t\t================================================================      " << endl<<endl;
    }
    if (index == 1) {
        cout << "\t\t\t\t\t\t\t[ No Trains Available ]" << endl;
    }
}
void UpdateStatus(string Trainnumber,string message) {
    for (book = BookedDetails.begin(); book != BookedDetails.end(); book++) {
        if (book->getTrainNumber() == Trainnumber) {
            for (int i = 0; i < book->getNoOfTickets(); i++) {
                if (book->getStatus(i) == "Booked") {
                    book->setStatus(message, i);
                }
            }
        }
    }
}                        

void IncrementAvlBerth(string Trainnumber) {
    for (train = TrainDetails.begin(); train != TrainDetails.end(); train++) {
        if (train->getTrainNo() == Trainnumber) {
            int AvlSeats = train->getAvlBerth() +1;
            train->setAvlBerth(AvlSeats);
        }
    }
}
void AddToCancelledSeats(string Trainnumber, int SeatNo) {
    for (train = TrainDetails.begin(); train != TrainDetails.end(); train++) {
        if (train->getTrainNo() == Trainnumber) {
            int Size = train->getCancelCount();
            train->setCancelledSeatswithIndex(SeatNo, Size);
            train->setCancelCount(Size + 1);
        }
    }
}

void ViewAllBooked() {
    cout << "\t\t\t\t\t\t\t[ View All Booked ]" << endl << endl;
    int index = 1;
    for (book = BookedDetails.begin(); book != BookedDetails.end(); book++) {
        int flag = 0;
        cout << "\t\t\t\t\t==================================Book.No: " << index++ << " ====================================" << endl;
        cout << "\t\t\t\t\t\t\t[ PNR ]: " << book->getPNR() << endl;
        cout << "\t\t\t\t\t\t\t[ Train No ]: " << book->getTrainNumber() << endl;
        cout << "\t\t\t\t\t\t\t[ User Name ]: " << book->getUserName() << endl;
        cout << "\t\t\t\t\t\t\t[ No Of Tickets ]: " << book->getNoOfTickets() << endl;
        for (int i = 0; i < book->getNoOfTickets(); i++) {
            if(book->getStatus(i) != "Cancelled") {
                cout << "\t\t\t\t\t======================================================================================" << endl;
                cout << "\t\t\t\t\t\t\t[ Name ]: " << book->getName(i) << endl;
                cout << "\t\t\t\t\t\t\t[ Age ]: " << book->getAge(i) << endl;
                cout << "\t\t\t\t\t\t\t[ Mobile ]: " << book->getMobile(i) << endl;
                cout << "\t\t\t\t\t\t\t[ Seat No ]: " << book->getSeatNo(i) << endl;
                cout << "\t\t\t\t\t\t\t[ Status ]: " << book->getStatus(i) << endl;
                cout << "\t\t\t\t\t=======================================================================================" << endl << endl;
                flag = 1;
            }
        }
        if (flag == 0) {
            cout << "[ All Passenger Cancelled From this PNR ]" << endl;
            cout << "\t\t\t\t\t==============================================================================================" << endl;
            return;
        }
        cout << "\t\t\t\t\t===============================================================================================" << endl;
    }
    if (index == 1) {
        cout << "\t\t\t\t\t\t\t[ No Booking Started ]" << endl;
    }
}
void ViewAllCancelled() {
    cout << "\t\t\t\t\t\t\t[ Cancel Ticket ]" << endl << endl;
    int index = 1;
    for (cancel = CancelledDetails.begin(); cancel != CancelledDetails.end(); cancel++) {
        cout << "\t\t\t\t\t==================[ Cancel Details: " << index++ << " ]====================================" << endl;
        cout << "\t\t\t\t\t\t\t[ User Name ]: " << cancel->getUserName() << endl;
        cout << "\t\t\t\t\t\t\t[ PNR ]: " << cancel->getPNR() << endl;
        cout << "\t\t\t\t\t\t\t[ Train Number ]: " << cancel->getTrainNumber() << endl;
        cout << "\t\t\t\t\t\t\t[ Passenger Name ]: " << cancel->getName() << endl;
        cout << "\t\t\t\t\t\t\t[ Passenger Age ]: " << cancel->getAge() << endl;
        cout << "\t\t\t\t\t\t\t[ Passenger Mobile ]: " << cancel->getMobile() << endl;
        cout << "\t\t\t\t\t======================================================================================" << endl;
    }
    if (index == 1) {
        cout << "\t\t\t\t\t\t\t[ No Cancellation Found ]" << endl;
    }
}