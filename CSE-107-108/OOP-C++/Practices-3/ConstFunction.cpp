#include <iostream>
using namespace std ;

class Date
{
    int year ;
    int month ;
    int day ;

public:
    Date(int year, int month, int day){
        setDate(year, month, day);
    }

    void setDate(int year, int month, int day){
        this->year = year;
        this->month = month;
        this->day = day;
    }

    int getYear() const{ return year; }
    int getMonth() const{ return month; }
    int getDay() const{ return day; }
    
    const Date& getDate(){
        //Returning const reference 
        return *this ;
    }
    
    void printDate () const 
    {
        //If the method has to be const then all methods it is calling have to be const ;
        cout << getYear() << '/' << getMonth() << '/' << getDay() << '\n';
    }
};
void printDate1(const Date& date)
{
    //If getYear(),getMonth() and getDay() aren't const function then the constant arguement object can't access non-constant functions
    //But the reverse isn't true ;
    cout << date.getYear() << '/' << date.getMonth() << '/' << date.getDay() << '\n';
}

int main()
{
    Date date(2000, 12, 17);
    date.printDate() ;//2000/12/17
    printDate1(date) ;//2000/12/17
    /*
    Date &date2 = date.getDate() ;
    Compilation error 
    binding reference of type 'Date&' to 'const Date' discards qualifiers,because we are returning const reference
    */
    Date date2 = date.getDate() ;//Just a copy returning const reference,address not same for both objects
    const Date &date_X = date.getDate() ;//assigning to same address .
    printDate1(date2) ;//2000/12/17
    Date date3(2021,5,6) ;
    date = date3 ; //Works fine
    /*
    date_X = date.getDate() ;
    Error!!
    date_X = date //Error
    date_X = date3.getDate() ;//Error
    */
    printDate1(date2) ;//2000/12/17
    printDate1(date) ;//2021/5/6
    printDate1(date_X) ;//2021/5/6
    printDate1(date3) ;//2021/5/6
    cout<<&date<<" "<<&date2<<" "<<&date3<<" "<<&date_X<<endl;
    //Notice that,date and date_x have same address .
    

    return 0;
}