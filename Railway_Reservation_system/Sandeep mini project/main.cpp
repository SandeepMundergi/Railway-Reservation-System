#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <process.h>
#include <string.h>
#include <iomanip>

using namespace std;
class pn
{
public:
    int pnr;
} x;

void star();       // FUNCTION TO PRINT STARS ON SCREEN
void dash_board(); // FUNCTION USED FOR USER MODULE
class train
{
public:
    int tno, ac, sleeper, sc, dist, fac, fsleeper, fsc;
    float time;
    char from[100], to[100], name[100];

public:
    void modify();   // FUNCTION TO MODIFY TRAIN RECORDS
    void del();      // FUNCTION TO DELETE TRAIN RECORDS
    void display();  // FUNCTION TO DISPLAY TRAIN RECORDS
    void display1(); // FUNCTION TO DISPLAY TRAIN RECORDS IN ORDER
    void acp();      //	FUNCTION TO ACCEPT TRAIN RECORDS
    void check();    //	FUNCTION TO CHECK AVAILABILITY
    int update(int); //	FUNCTION TO UPDATE NO. OF SEATS AFTER CANCELLATION
    int ret()        // ACCESSOR FUNCTION TO RETURN TRAIN NUMBER
    {
        return tno;
    }
    char *f1() // ACCESSOR FUNCTION TO RETURN STARTING POINT
    {
        return from;
    }
    char *t1() // ACCESSOR FUNCTION TO RETURN DESTINATION
    {
        return to;
    }
} t;         // END OF CLASS
void add();  // FUNCTION TO ADD TRAIN RECORDS
void disp(); // FUNCTION TO DISPLAY TRAIN RECORDS
class book
{
public:
    int no, tickets, pnr;
    char pto[100], pfrom[100], clas[20];
    long int amt;
    int retpnr() // ACCESSOR FUNCTION TO RETURN PNR NUMBER
    {
        return pnr;
    }
    int rettic() // ACCESSOR FUNCTION TO RETURN TICKETS
    {
        return tickets;
    }
    int retamt() // ACCESSOR FUNCTION TO RETURN AMOUNT
    {
        return amt;
    }
    void get();          // FUNCTION TO GET BOOKING DETAILS
    int assign();        // FUNCTION TO CALCULATE AND ASSIGN BOOKING DETAILS
    void show();         // FUNCTION TO DISPLAY BOOKING DETAILS
    void cancel();       // FUNCTION TO CANCEL BOOKING
    void check_status(); // CHECK THE STATUS OF PASSENGER BOOKING
    void list_pass();    // SEND INDIVIDUAL PNR NUMBER TO DISPLAY FUNCTION
    void list_disp(int); // GENERATE PASSNGER LIST FOR ADMIN SECTION
} b;                     // END OF CLASS
class passenger
{
public:
    int pnr, page;
    char pGENDER, pname[100];
    string date;
    void getp();     // FUNCTION TO GET PASSENGER DETAILS
    void showp(int); //	FUNCTION TO SHOW PASSENGER DETAILS
} p;                 // END OF CLASS
void admin();        // ADMIN SECTION TO MANIPULATE TRAIN RECORDS
void menu();         // STARTING OF RAILWAY RESERVATION PROGRAM

int main() // STARTING MAIN FUNCTION
{
    menu(); // STARTING OF PROGRAM
    return 0;
} // END OF MAIN

void menu()
{
    int n;
    do
    {
        system("cls");
        cout << "\n\n\n\n";
        star();
        cout << "\t\t\t\t\t  WELCOME TO INDIAN RAILWAYS" << endl;
        star();
        cout << "\n\t\t\t\t\t1.ADMIN ACCESS" << endl;
        cout << "\t\t\t\t\t2.USER ACCESS" << endl;
        cout << "\t\t\t\t\t3.EXIT\n"
             << endl;
        star();
        cout << "\t\t\t\t\t  YOUR CHOICE : ";
        cin >> n;
        switch (n)
        {
        case 1:
            admin();
            break;
        case 2:
            dash_board();
            break;
        case 3:
            exit(0);
        }

    } while (n != 3);
}
void dash_board()
{
    int n;
    while (1)
    {
        system("cls");
        cout << "\n\n\n";
        star();
        cout << "\t\t\t\t\t  WELCOME TO INDIAN RAILWAYS" << endl;
        star();
        cout << "\n\t\t\t\t\t1.TO CHECK AVAILABILITY" << endl;
        cout << "\t\t\t\t\t2.TO BOOK TICKETS" << endl;
        cout << "\t\t\t\t\t3.FOR CANCELLATION" << endl;
        cout << "\t\t\t\t\t4.CHECK STATUS" << endl;
        cout << "\t\t\t\t\t5.RETURN\n\n";
        star();
        cout << "\t\t\t\t\t  YOUR CHOICE : ";
        cin >> n;
        system("cls");
        switch (n)
        {
        case 1:
            t.check();
            getch();
            break;
        case 2:
            b.get();
            getch();
            break;
        case 3:
            b.cancel();
            getch();
            break;
        case 4:
            b.check_status();
            break;
        case 5:
            menu();
            break;
        default:
            system("cls");
            star();
            cout << "\t\t\t\tWRONG CHOICE" << endl;
            star();
            getch();
        } // END OF SWITCH
    }     // END OF WHILE
}

void add() // FUNCTION TO WRITE TRAIN RECORDS
{
    system("cls");
    star();
    fstream rr;
    rr.open("train.dat", ios::app | ios::in | ios::binary);
    char ch;
    do
    {
        system("cls");
        star();
        t.acp();
        rr.write((char *)&t, sizeof t);
        cout << "\t\t\t\t\t  MORE RECORDS ? (Y/N) : ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    star();
    rr.close();
} // END OF FUNCTION
void disp() // FUNCTION TO DISPLAY TRAIN RECORDS
{
    fstream rr;
    rr.open("train.dat", ios::in | ios::binary);
    system("cls");
    cout << "\n\n\n";
    star();
    cout << "\t\t\t\t\t   TRAIN DETAILS" << endl;
    star();
    cout << "\t\t  TRAIN NO\t\tTRAIN NAME\t     FROM\t    TO\t      TIME" << endl;
    star();
    while (rr.read((char *)&t, sizeof t))
    {
        // system("cls");
        t.display1();
    }
    cout << "\n";
    star();
    rr.close();
} // END OF FUNCTION
void train::display() // FUNCTION TO DISPLAY TRAIN RECORD
{
    cout << "\t\t\t\t\t\tTRAIN DETAILS" << endl;
    star();
    cout << "\n\t\t\t\t\tTRAIN NUMBER : " << tno << endl;
    cout << "\t\t\t\t\tTRAIN NAME : " << name << endl;
    cout << "\t\t\t\t\tSTARTING POINT : " << from << endl;
    cout << "\t\t\t\t\tDESTINATION : " << to << endl;
    cout << "\t\t\t\t\tAC TICKETS AVAILABLE : " << ac << endl;
    cout << "\t\t\t\t\tPRICE OF EACH AC TICKET Rs. : " << fac << endl;
    cout << "\t\t\t\t\tSLEEPER CLASS TICKETS AVAILABLE : " << sleeper << endl;
    cout << "\t\t\t\t\tPRICE OF EACH SLEEPER CLASS TICKET Rs. : " << fsleeper << endl;
    cout << "\t\t\t\t\tSECOND CLASS TICKETS AVAILABLE : " << sc << endl;
    cout << "\t\t\t\t\tPRICE OF EACH SECOND CLASS TICKET Rs. : " << fsc << endl;
    cout << "\t\t\t\t\tDURATION OF JOURNEY (hrs) : " << time << endl;
    cout << "\t\t\t\t\tTOTAL DISTANCE(km) : " << dist << endl;
    cout << endl;
    star();
    getch();
}
void train::display1() // FUNCTION TO DISPLAY TRAIN RECORD
{
    cout << "\t\t    " << tno << setw(29) << name << setw(15) << from << setw(12) << to << setw(10) << time << " hr" << endl;
}
void train::acp() // FUNCTION TO ACCEPT TRAIN RECORDS
{
    system("cls");
    cout << "\n\n\n";
    star();
    cout << "\t\t\t\t\t  ENTER TRAIN DETAILS" << endl;
    star();
    cout << "\n\t\t\t\tTRAIN NUMBER : ";
    cin >> tno;
    cout << "\t\t\t\tTRAIN NAME : ";
    cin >> name;
    cout << "\t\t\t\tSTARTING POINT : ";
    cin >> from;
    cout << "\t\t\t\tDESTINATION : ";
    cin >> to;
invalid_5:
    cout << "\t\t\t\tNUMBER OF AC TICKETS TO BE MADE AVAILABLE  : ";
    cin >> ac;
    if (ac <= 0)
    {
        star();
        cout << "\t\t\t\tNUMBER OF TICKET SHOULD BE GREATER THAN 0\n";
        star();
        getch();
        system("cls");
        cout << "\n\n\n";
        star();
        goto invalid_5;
    }
invalid_6:
    cout << "\t\t\t\tPRICE OF EACH AC TICKET Rs. : ";
    cin >> fac;
    if (fac <= 0)
    {
        star();
        cout << "\t\t\t\tPRICE SHOULD BE GREATER THAN 0\n";
        star();
        getch();
        system("cls");
        cout << "\n\n\n";
        star();
        goto invalid_6;
    }
invalid_7:
    cout << "\t\t\t\tNUMBER OF SLEEPER TICKETS TO BE MADE AVAILABLE : ";
    cin >> sleeper;
    if (sleeper <= 0)
    {
        star();
        cout << "\t\t\t\tNUMBER OF TICKET SHOULD BE GREATER THAN 0\n";
        star();
        getch();
        system("cls");
        cout << "\n\n\n";
        star();
        goto invalid_7;
    }
invalid_8:
    cout << "\t\t\t\tPRICE OF EACH SLEEPER TICKET Rs. : ";
    cin >> fsleeper;
    if (fsleeper <= 0)
    {
        star();
        cout << "\t\t\t\tPRICE SHOULD BE GREATER THAN 0\n";
        star();
        getch();
        system("cls");
        cout << "\n\n\n";
        star();
        goto invalid_8;
    }
invalid_9:
    cout << "\t\t\t\tNUMBER OF SECOND CLASS TICKETS TO BE MADE AVAILABLE : ";
    cin >> sc;
    if (sc <= 0)
    {
        star();
        cout << "\t\t\t\tNUMBER OF TICKET SHOULD BE GREATER THAN 0\n";
        star();
        getch();
        system("cls");
        cout << "\n\n\n";
        star();
        goto invalid_9;
    }
invalid_10:
    cout << "\t\t\t\tPRICE OF EACH SECOND CLASS TICKET Rs. : ";
    cin >> fsc;
    if (fsc <= 0)
    {
        star();
        cout << "\t\t\t\tPRICE SHOULD BE GREATER THAN 0\n";
        star();
        getch();
        system("cls");
        cout << "\n\n\n";
        star();
        goto invalid_10;
    }
invalid_11:
    cout << "\t\t\t\tDURATION OF JOURNEY(hrs)  : ";
    cin >> time;
    if (time <= 0)
    {
        star();
        cout << "\t\t\t\tNUMBER OF HOUR'S SHOULD BE GREATER THAN 0\n";
        star();
        getch();
        system("cls");
        cout << "\n\n\n";
        star();
        goto invalid_11;
    }
invalid_12:
    cout << "\t\t\t\tTOTAL DISTANCE (km) : ";
    cin >> dist;
    if (dist <= 0)
    {
        star();
        cout << "\t\t\t\tDISTANCE SHOULD BE GREATER THAN 0\n";
        star();
        getch();
        system("cls");
        cout << "\n\n\n";
        star();
        goto invalid_12;
    }
    cout << "\n";
    star();
} // END OF FUNCTION
void train::modify() // FUNCTION TO MODIFY TRAIN RECORD
{
    system("cls");
    cout << "\n\n\n";
    star();
    cout << "\t\t\t\t\t   TRAIN MODIFICATION" << endl;
    star();
    fstream rr;
    rr.open("train.dat", ios::in | ios::out | ios::binary);
    int id, f = 0, n = 0, p;
    cout << "\t\t\t\tTRAIN NUMBER OF TRAIN TO BE MODIFIED : ";
    cin >> id;
    while (rr.read((char *)&t, sizeof t))
    {
        n++;
        if (id == t.ret())
        {
            acp();
            p = (n - 1) * (sizeof t);
            rr.seekp(p, ios::beg);
            rr.write((char *)&t, sizeof t);
            f = 1;
        }
    }
    if (f == 0)
    {
        star();
        cout << "\t\t\t\t\t   SORRY RECORD NOT FOUND !!" << endl;
        star();
    }
    rr.close();
} //END OF FUNCTION
void train::del() // FUNCTION TO DELETE TRAIN RECORDS
{
    system("cls");
    cout << "\n\nn\n";
    star();
    cout << "\t\t\t\t\t\t DELETE TRAIN" << endl;
    star();
    int id, f = 0;
    fstream rr;
    rr.open("train.dat", ios::in | ios::binary);
    fstream t1;
    t1.open("temp.dat.dat", ios::out | ios::binary);
    cout << "\t\t\t\t\tTRAIN NUMBER TO BE DELETED : ";
    cin >> id;
    star();
    while (rr.read((char *)&t, sizeof t))
    { // 1
        if (id == t.ret())
        { // 2
            char ch;
            f = 1;
            cout << "\n\n\n";
            t.display();
            cout << "\t\t\t\tARE YOU SURE ? (Y/N) : ";
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
            {
                star();
                cout << "\t\t\t\tRECORD DELETED";
            }
            else
            {
                t1.write((char *)&t, sizeof t);
            }
        } // 2
        else
            t1.write((char *)&t, sizeof t);
    } // 1
    if (f == 0)
    {
        cout << "\t\t\t\t\t   SORRY RECORD NOT FOUND !!" << endl;
        star();
    }
    rr.close();
    t1.close();
    remove("train.dat");
    rename("temp.dat.dat", "train.dat");
} // END OF FUNCTION
void train::check() // FUNCTION TO CHECK TICKET AVAILABILITY
{
    int count = 0;
    cout << "\n\n\n";
    disp();
    cout << "\t\t\t\t\t  CHECK AVAILABILITY" << endl;
    star();
    char T[100], f[100];
    int flag = 0;
    cout << "\t\t\t\tTHE STARTING POINT : ";
    cin >> f;
    cout << "\t\t\t\tTHE DESTINATION : ";
    cin >> T;
    fstream rr;
    rr.open("train.dat", ios::in | ios::binary);
    while (rr.read((char *)&t, sizeof t))
    {
        if (strcmpi(f, t.f1()) == 0 && strcmpi(T, t.t1()) == 0)
        {
            system("cls");
            cout << "\n\n\n";
            star();
            flag = 1;
            t.display();
            count++;
        }
    } // END OF WHILE
    if (flag == 0)
    {
        star();
        cout << "\t\t\t\t\t  SORRY NO AVAILABLE TRAINS FOUND" << endl;
        star();
    }
    else
    {
        cout << "\t\t\t\t\t  NUMBER OF TRAINS ARE : " << count << endl;
        star();
    }
} //END OF FUNCTION
int train::update(int q) // FUNCTION TO UPDATE TICKETS AFTER CANCELLATION
{
    fstream rr;
    int n, tic, charge;
    rr.open("booking.dat", ios::in | ios::out | ios::binary);
    while (rr.read((char *)&b, sizeof b))
    {
        if (b.pnr == q)
        {
            n = b.no;
            tic = b.tickets;
            rr.close();
            rr.open("train.dat", ios::in | ios::out | ios::binary);
            rr.seekg(0, ios::beg);
            int f = 0, p;
            while (rr.read((char *)&t, sizeof t))
            {
                f++;
                if (t.tno == n) //1
                {
                    p = (f - 1) * (sizeof(t));
                    rr.seekp(p, ios::beg);
                    if (strcmpi(b.clas, "ac") == 0)
                    {
                        t.ac += tic;
                        rr.write((char *)&t, sizeof t);
                        charge = 1;
                    }
                    else if (strcmpi(b.clas, "sl") == 0)
                    {
                        t.sleeper += tic;
                        rr.write((char *)&t, sizeof t);
                        charge = 2;
                    }
                    else
                    {
                        t.sc += tic;
                        rr.write((char *)&t, sizeof t);
                        charge = 3;
                    }
                } //1
            }     // END OF WHILE 2
            rr.close();
            break;
        } // END OF IF
    }     // END OF WHILE 1
    return charge;
} // END OF FUNCTION
void book::get() // FUNCTION TO BOOK TICKETS
{
    cout << "\n\n\n";
    int n = 1;
    while (n == 1)
    { // WHILE 1
        system("cls");
        cout << "\n\n\n";
        star();
        cout << "\t\t\t\t\t  WELCOME TO BOOKING MENU" << endl;
        star();
        cout << "\t\t\t\t\t 1.TO BOOK TICKETS" << endl;
        cout << "\t\t\t\t\t 2.TO GO BACK" << endl;
        star();
        cout << "\t\t\t\t\t  YOUR CHOICE : ";
        cin >> n;
        if (n == 1)
        { //	IF 1
            system("cls");
            cout << "\n\n\n";
            star();
            cout << "\t\t\t\t\t    BOOKING SECTION" << endl;
            star();
            int flag = 0;
            cout << "\t\t\t\t\tTHE BOARDING POINT : ";
            cin >> pfrom;
            cout << "\t\t\t\t\tTHE DESTINATION : ";
            cin >> pto;
            cout << endl;
            fstream rr;
            rr.open("train.dat", ios::in | ios::binary);
            fstream pas;
            pas.open("passenger.dat", ios::app | ios::binary);
            rr.seekg(0, ios::beg);
            while (rr.read((char *)&t, sizeof t))
            { // WHILE 2
                if (strcmpi(pfrom, t.f1()) == 0 && strcmpi(pto, t.t1()) == 0)
                {
                    system("cls");
                    cout << "\n\n\n";
                    star();
                    flag = 1;
                    t.display();
                }
            } // END OF WHILE 2
            rr.close();
            if (flag == 0)
            {
                star();
                cout << "\t\t\t\t\tSORRY NO AVAILABLE TRAINS FOUND " << endl;
                star();
                getch();
            }
            // STARTING THE BOOKING PROCESS
            if (flag == 1)
            { //  IF 2
                int f1 = 0;
                system("cls");
                cout << "\n\n\n";
                star();
                cout << "\t\t\t\t\t    BOOKING SECTION" << endl;
                star();
                cout << "\t\t\t\tTHE TRAIN NUMBER TO BOOK TICKETS : ";
                cin >> no;
                rr.open("train.dat", ios::in | ios::binary);
                rr.seekg(0, ios::beg);
                while (rr.read((char *)&t, sizeof t))
                { // WHILE 3
                    if (no == t.ret())
                    {
                        f1 = 1;
                    invalid_1:
                        cout << "\t\t\t\tTHE NUMBER OF TICKETS TO BOOK(MAX .6) : ";
                        cin >> tickets;
                        if (tickets <= 0 || tickets > 6)
                        {
                            star();
                            cout << "\t\t\t\t\tSORRY CANNOT INVALID INPUT\n";
                            star();
                            getch();
                            system("cls");
                            cout << "\n\n\n";
                            star();
                            goto invalid_1;
                        }
                    invalid_2:
                        cout << "\t\t\t\tTHE CLASS (AC : ac / SLEEPER : sl / SECOND CLASS : sc) : ";
                        cin >> clas;
                        if (strcmpi(clas, "ac") != 0 && strcmpi(clas, "sl") != 0 && strcmpi(clas, "sc") != 0)
                        {
                            star();
                            cout << "\t\t\t\tSORRY YOU HAVE ENTERD INCORRECT CLASS" << endl;
                            star();
                            getch();
                            system("cls");
                            cout << "\n\n\n";
                            star();
                            goto invalid_2;
                        }
                        int z;
                        z = b.assign(); // CALLING THE FUNCTION TO ASSIGN
                        // BOOKING DETAILS
                        if (z == 0)
                        {
                            star();
                            cout << "\t\t\t\tSORRY CANNOT BOOK " << tickets << " TICKETS ";
                            star();
                            getch();
                            break;
                        }
                        else
                        {
                            for (int i = 0; i < tickets; i++)
                            {
                                system("cls");
                                star();
                                cout << "\t\t\t\t\t  DETAILS OF PASSENGER " << (i + 1) << endl;
                                p.getp();
                                p.pnr = b.pnr;
                                pas.write((char *)&p, sizeof p);
                                star();
                            }
                            pas.close();
                            rr.close();
                            b.show();
                            p.showp(b.pnr);
                            getch();
                            break;
                        }
                    } // END OF IF 3
                }     // END OF WHILE 3
                if (f1 == 0)
                {
                    star();
                    cout << "\t\t\t\tSORRY YOU HAVE ENTERD INCORRECT TRAIN NUMBER" << endl;
                    star();
                    getch();
                }
            } // END OF IF 2
            pas.close();
            rr.close();
        } // END OF IF 1
    }     // END OF WHILE 1
} // END OF FUNCTION
int book::assign() // FUNCTION TO CALCULATE AND ASSIGN BOOKING DETAILS
{
    int n = 0, p;
    fstream rr;
    rr.open("train.dat", ios::in | ios::out | ios::binary);
    rr.seekg(0, ios::beg);
    while (rr.read((char *)&t, sizeof t))
    {
        n++;
        if (no == t.ret())
        {
            if (strcmpi(clas, "ac") == 0)
            {
                amt = tickets * t.fac;

                p = (n - 1) * sizeof(t);
                rr.seekp(p, ios::beg);

                t.ac = t.ac - tickets;

                if (t.ac < 0)
                {
                    return 0;
                }

                else
                    rr.write((char *)&t, sizeof t);
            }

            else if (strcmpi(clas, "sl") == 0)
            {
                amt = tickets * t.fsleeper;

                p = (n - 1) * sizeof(t);
                rr.seekp(p, ios::beg);
                t.sleeper = t.sleeper - tickets;
                if (t.sleeper < 0)
                    return 0;
                else
                    rr.write((char *)&t, sizeof t);
            }
            else
            {
                amt = tickets * t.fsc;
                p = (n - 1) * sizeof(t);
                rr.seekp(p, ios::beg);
                t.sc = t.sc - tickets;
                if (t.sc < 0)
                    return 0;
                else
                    rr.write((char *)&t, sizeof t);
            }
            break;
        }
    }
    fstream b1;
    b1.open("booking.dat", ios::app | ios::binary);
    fstream rr2;
    rr2.open("pnr.dat", ios::in | ios::binary);
    if (!rr2)
    {
        rr2.close();
        rr2.open("pnr.dat", ios::in | ios::app | ios::binary);
        rr2.seekp(0, ios::beg);
        x.pnr = 1000;
        rr2.write((char *)&x, sizeof x);
        rr2.close();
    }
    else
    {
        int d;
        rr2.seekg(0, ios::beg);
        while (rr2.read((char *)&x, sizeof x))
        {
            d = x.pnr;
        }
        rr2.close();
        fstream r2;
        r2.open("pnr.dat", ios::app | ios::binary);
        x.pnr = ++d;
        r2.write((char *)&x, sizeof x);
        r2.close();
    }
    b.pnr = x.pnr;
    b1.write((char *)&b, sizeof b);
    b1.close();
    return 1;
} //END OF FUNCTION
void book::show() // FUNCTION TO DISPLAY BOOKING DETAILS
{
    system("cls");
    cout << "\n\n\n";
    star();
    cout << "\t\t\t\t\t\tTICKET" << endl;
    star();
    cout << "\t\t\t\t  PNR NUMBER		: " << pnr << endl;
    cout << "\t\t\t\t  TRAIN NUMBER		: " << no << endl;
    cout << "\t\t\t\t  TOTAL PASSENGERS	: " << tickets << endl;
    cout << "\t\t\t\t  TOTAL AMOUNT		: " << amt << endl;
    cout << "\t\t\t\t  BOARDING POINT        : " << pfrom << endl;
    cout << "\t\t\t\t  DESTINATION		: " << pto << endl;
    star();
    cout << "\t\t\t\t   YOUR TICKET HAS BEEN RESERVED" << endl;
} // END OF FUNCTION
void book::cancel() // FUNCTION TO CANCEL BOOKING
{
    int C_charge, C_temp;
    cout << "\n\n\n";
    star();
    cout << "\t\t\t\t\t  CANCELLATION" << endl;
    star();
    train tr;
    fstream b1;
    b1.open("booking.dat", ios::in | ios::binary);
    fstream rr;
    rr.open("passenger.dat", ios::in | ios::binary);
    fstream t;
    t.open("temp.dat", ios::out | ios::binary);
    fstream tmp;
    tmp.open("t2.dat", ios::out | ios::binary);
    int id;
    int flag = 0, f = 0;
    char ch;
    cout << "\t\t\t\t YOUR PNR NUMBER : ";
    cin >> id;
    while (b1.read((char *)&b, sizeof b))
    {
        if (id == b.retpnr())
        {
            system("cls");
            cout << "\n\n\n";
            star();
            cout << "\t\t\t\t\t  CANCELLATION" << endl;
            star();
            flag = 1;
            f = 1;
            cout << "\t\t\t\t  PNR NUMBER	        : " << b.retpnr() << endl;
            cout << "\t\t\t\t  TOTAL TICKETS		: " << b.rettic() << endl;
            cout << "\t\t\t\t  TOTAL AMOUNT		: " << b.retamt() << endl;
            cout << "\t\t\t\t  BOARDING POINT        : " << pfrom << endl;
            cout << "\t\t\t\t  DESTINATION		: " << pto << endl;

            p.showp(id);
            cout << "\t\t\t\t\tARE YOU SURE ? (Y/N) : ";
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
            {
                C_temp = tr.update(id);
                if (C_temp == 1)
                {
                    C_charge = amt * 0.2;
                }
                else if (C_temp == 2)
                {
                    C_charge = amt * 0.15;
                }
                else
                {
                    C_charge = amt * 0.1;
                }
                cout << "\n\t\t\t\tAFTER CANCELLATION AMOUNT : " << (amt - C_charge) << endl;
                star();
                cout << "\t\t\t\t  YOUR BOOKING HAS BEEN CANCELLED" << endl;
                star();
            }
            else
            {
                flag = 0;
                t.write((char *)&b, sizeof b);
            }
        }
        else
        {
            t.write((char *)&b, sizeof b);
        }
    }
    t.close();
    tmp.close();

    b1.close();
    remove("booking.dat");
    rename("temp.dat", "booking.dat");
    if (flag == 1)
    {

        fstream tmp;
        tmp.open("t2.dat", ios::out | ios::binary);
        rr.seekg(0, ios::beg);
        while (rr.read((char *)&p, sizeof p))
        {
            if (id != b.retpnr())
                tmp.write((char *)&p, sizeof p);
        }
        rr.close();
        tmp.close();
        remove("passenger.dat");
        rename("t2.dat", "passenger.dat");
        flag = 0;
    }
    if (f == 0)
    {
        star();
        cout << "\t\t\t\t\t SORRY INVALID PNR" << endl;
        star();
        remove("temp.dat");
        remove("t2.dat");
    }
    rr.close();
    tmp.close();
    b1.close();
    t.close();

} // END OF FUNCTION
void book::check_status()
{
    cout << "\n\n\n";
    star();
    cout << "\t\t\t\t\t  BOOKING STATUS" << endl;
    star();
    train tr;
    fstream b1;
    b1.open("booking.dat", ios::in | ios::binary);
    fstream rr;
    rr.open("passenger.dat", ios::in | ios::binary);
    fstream tt;
    tt.open("train.dat", ios::in | ios::binary);
    int id;
    int flag = 0, f = 0;
    char ch;
    cout << "\t\t\t\t YOUR PNR NUMBER : ";
    cin >> id;
    while (b1.read((char *)&b, sizeof b))
    {
        if (id == b.retpnr())
        {
            flag = 1;
            while (tt.read((char *)&t, sizeof t))
            { // WHILE 2
                if (strcmpi(pfrom, t.f1()) == 0 && strcmpi(pto, t.t1()) == 0)
                {
                    system("cls");
                    cout << "\n\n\n";
                    star();
                    cout << "\t\t\t\t\t  BOOKING STATUS" << endl;
                    star();
                    flag = 1;
                    f = 1;
                    cout << "\t\t\t\t  PNR NUMBER	        : " << b.retpnr() << endl;
                    cout << "\t\t\t\t  TRAIN NUMBER	        : " << t.tno << endl;
                    cout << "\t\t\t\t  TRAIN NAME	        : " << t.name << endl;
                    cout << "\t\t\t\t  TOTAL TICKETS		: " << b.rettic() << endl;
                    cout << "\t\t\t\t  TOTAL AMOUNT		: " << b.retamt() << endl;
                    cout << "\t\t\t\t  BOARDING POINT        : " << pfrom << endl;
                    cout << "\t\t\t\t  DESTINATION		: " << pto << endl;
                    p.showp(id);
                }
            } // END OF WHILE 2
        }
    }
    if (flag == 0)
    {
        star();
        cout << "\t\t\t\t\t  SORRY INVALID PNR" << endl;
        star();
    }
    b1.close();
    rr.close();
    tt.close();
    getch();
}
void passenger::getp()
{
    star();
    cout << "\t\t\t\t\tNAME : ";
    cin >> pname;
invalid_3:
    cout << "\t\t\t\t\tAGE : ";
    cin >> page;
    if (page < 10)
    {
        star();
        cout << "\t\t\t\tINVALID AGE SHOULD BE GREATER THAN 10\n";
        star();
        getch();
        system("cls");
        cout << "\n\n\n";
        star();
        goto invalid_3;
    }
invalid_4:
    cout << "\t\t\t\t\tGENDER (M/F) : ";
    cin >> pGENDER;
    if (pGENDER != 'm' && pGENDER != 'M' && pGENDER != 'f' && pGENDER != 'F')
    {
        star();
        cout << "\t\t\t\tINVALID GENDER SHOULD BE (M or F)\n";
        star();
        getch();
        system("cls");
        cout << "\n\n\n";
        star();
        goto invalid_4;
    }

} // END OF FUNCTION
void passenger::showp(int q) // FUNCTION TO SHOW PASSENGER DETAILS
{
    int i = 14;
    fstream rr;
    rr.open("passenger.dat", ios::in | ios::binary);
    star();
    cout << "\t\t\t\t\t   PASSENGER LIST" << endl;
    star();
    cout << "\t\t\t   PASSENGER NAME\tPASSENGER AGE\tPASSENGER GENDER " << endl;
    while (rr.read((char *)&p, sizeof p))
    {
        if (p.pnr == q)
        {
            cout << "\t\t" << setw(20) << pname << setw(18) << page << setw(18) << pGENDER << endl;
        }
    }
    star();
    rr.close();
} // END OF FUNCTION
void admin() // FUNCTION TO MANIPULATE TRAIN RECORDS
{
    system("cls");
    cout << "\n\n\n";
    star();
    int m;
    char p[20];
    cout << "\t\t\t\t\t\tADMIN LOGIN" << endl;
    star();
    cout << "\n\t\t\t\tTHE PASSWORD : ";
    for (int i = 0; i < 20; i++)
    {
        p[i] = getch();
        if (p[i] == 13)
        {
            p[i] = '\0';
            break;
        }
        else
            cout << "*";
    }
    if (strcmp(p, "railway123") == 0)
    {
        do
        {
            system("cls");
            cout << "\n\n\n";
            star();
            cout << "\t\t\t\t\t\tADMIN SECTION" << endl;
            star();
            cout << "\n\t\t\t\t\t1.CREATE NEW TRAIN FILE" << endl;
            cout << "\t\t\t\t\t2.NEW RECORD " << endl;
            cout << "\t\t\t\t\t3.MODIFY A TRAIN RECORD " << endl;
            cout << "\t\t\t\t\t4.GO BACK " << endl;
            cout << "\t\t\t\t\t5.DELETE A TRAIN RECORD " << endl;
            cout << "\t\t\t\t\t6.DISPLAY ALL THE CURRENT RECORDS " << endl;
            cout << "\t\t\t\t\t7.DISPLAY PASSENGER LIST\n\n";
            star();
            cout << "\t\t\t\t\tYOUR CHOICE : ";
            cin >> m;
            switch (m)
            {
            case 1:
                remove("train.dat");
                remove("booking.dat");
                remove("passenger.dat");
                remove("temp.dat");
                remove("t2.dat");
                add();
                getch();
                break;
            case 2:
                add();
                getch();
                break;
            case 3:
                t.modify();
                getch();
                break;
            case 4:
                break;
            case 5:
                t.del();
                getch();
                break;
            case 6:
                disp();
                getch();
                break;
            case 7:
                b.list_pass();
                getch();
                break;
            }
        } while (m != 4);
    } // END OF IF
    else
    {
        system("cls");
        star();
        cout << "\t\t\t\t\t\tWRONG PASSWORD" << endl;
        cout << "\t\t\t\t\t\tACCESS DENIED" << endl;
        star();
        getch();
    }
} // END OF FUNCTION
void star() // FUNCTION TO PRINT STARS ON SCREEN
{
    cout << "\t\t";
    for (int i = 1; i < 81; i++)
    {
        cout << "*";
    }
    cout << endl;
}
void book::list_pass() // FUNCTION TO GET ALL PASSENGER LIST
{
    system("cls");
    fstream b1;
    b1.open("booking.dat", ios::in | ios::binary);
    cout << "\n\n\n";
    star();
    cout << "\t\t\t\t\t    PASSENGER LIST" << endl;
    star();
    cout << "\t\t     PNR_NO  TRAIN NO   PASSENGER NAME   AGE   GENDER   FROM\tDESTINATION\n\n";

    while (b1.read((char *)&b, sizeof b))
    {
        b.list_disp(b.retpnr());
    }
    star();
    b1.close();
}
void book::list_disp(int q) // FUNCTION TO DISPLAY ALL PASSENGER LIST
{
    int i = 14, train_no;
    fstream rr;
    rr.open("passenger.dat", ios::in | ios::binary);
    fstream tt;
    tt.open("train.dat", ios::in | ios::binary);
    while (rr.read((char *)&p, sizeof p))
    {
        if (q == b.retpnr() && q == p.pnr)
        {
            while (tt.read((char *)&t, sizeof t))
            { // WHILE 2
                if (strcmpi(pfrom, t.f1()) == 0 && strcmpi(pto, t.t1()) == 0)
                {
                    train_no = t.tno; // GETTING TRAIN NUMBER BASED ON PNR NUMBER
                }
            } // END OF WHILE 2
            cout << "\t\t      " << p.pnr << "    " << train_no << setw(18) << p.pname << setw(8) << p.page << setw(6) << p.pGENDER << setw(10) << pfrom << setw(13) << pto << "\n";
        }
    }
    cout << endl;

    rr.close();
    tt.close();
}
