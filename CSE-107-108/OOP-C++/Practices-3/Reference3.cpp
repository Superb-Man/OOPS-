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
    
    Date& getDate(){
        return *this ;
    }
    Date* getDateAnother(){
        return &(*this) ;
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
    Compilation error when getDate() method returns const reference
    binding reference of type 'Date&' to 'const Date' discards qualifiers,because we are returning const reference.
    
    But this time no error!
    */
    Date date2 = date.getDate() ;//Just a copy returning const reference,address not same for both objects
    const Date& date_X = date.getDate();//assigning to same address .
    printDate1(date2) ;//2000/12/17
    Date date3(2021,5,6) ;
    //date = date3 ; //Works fine
    //date_X = date2 ;//Error!
    //date_X = date.getDate() ; //Error
    date = date3.getDate() ;//Works Fine
    //Date& date_Y = date_X.getDate(); Error! date_X is an const reference!
    Date& date_Y = date.getDate() ;// Works fine
    printDate1(date2) ;//2000/12/17
    printDate1(date) ;//2021/5/6
    printDate1(date_X) ;//2021/5/6
    printDate1(date_Y) ;//2021/5/6
    printDate1(date3) ;//2021/5/6
    cout<<&date<<" "<<&date2<<" "<<&date3<<" "<<&date_X<<" "<<&date_Y<<endl<<endl<<endl;
    //Notice that,date, date_x and date_Y have same address .
    
    date_Y = date2 ;//just assigning the values , address not same
    printDate1(date2) ;//2000/12/17
    printDate1(date) ;//2000/12/17
    printDate1(date_X) ;//2000/12/17
    printDate1(date_Y) ;//2000/12/17
    printDate1(date3) ;//2021/5/6
    cout<<&date<<" "<<&date2<<" "<<&date3<<" "<<&date_X<<" "<<&date_Y<<endl<<endl<<endl;
    //Notice that,date, date_x and date_Y have same address .
    
    Date* date_Z = date3.getDateAnother() ;//Will not get the same address of date3 because date3 is not a pointer variable ,rather date_Z points to the location of date3 .if anything is changed in date_Z or date3 it will effect others having same memory address or pointing to same memory address;
    //printDate1(date_Z) ; Will not work because date_Z is a pointer.
    printDate1(*date_Z) ;//2021/5/6
    date_Z->printDate() ; //2021/5/6
    cout<<&date_Z<<endl;//Pointer memory adress,not the location it points
    
    Date* date_Theta = date_Z->getDateAnother();//Both of date_Z and date_Theta point to same location and same object .
    cout<<&date_Theta<<endl;//Pointer memory adress,not the location it points
    //date_Theta = date3.getDate() ;//Error ,cannot convert 'Date' to 'Date*' in assignment
    *date_Theta = date_Y.getDate() ;//It's ok and It will effect date_Z also.But still points to date3 location.So date3 is now changed,it's more like int *p = &x ; *p =10/
    printDate1(date3) ;//2000/12/17
    
    printDate1(*date_Theta) ;//2000/12/17
    printDate1(*date_Z) ;//2000/12/17
    
    cout<<endl;
    date_Y.printDate() ;//2000/12/17
    
    date_Theta = date_Y.getDateAnother() ;//Now points to the location of date_Y,But date_Z still points to date3. So, date_Z will not be affected by changing date_Theta or date_Z ;
    date.setDate(1,1,1) ;
    date_Z->printDate() ;
    date_Theta->printDate() ;//1/1/1-> as date_Y and date referes to same address.
    cout<<endl<<endl<<endl;
    
    
    date.printDate() ;
    date2.printDate() ;
    date3.printDate() ;
    date_X.printDate() ;
    date_Y.printDate() ;
    date_Z->printDate() ;
    date_Theta->printDate() ;
    //Bye
    cout<<&date<<" "<<&date_X<<" "<<&date_Y<<endl;
    return 0;
}
