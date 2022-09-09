#include<iostream>
#include<fstream>
#include<cstring>

using namespace std ;

int main(){
    ifstream fin("C:/Users/User/Documents/GitHub/CSE-107-108/OOP-C++/IO-1/fin.txt") ;
    if(!fin.is_open()){
        cout<<"Error!, Can't open file" << endl ;
    }


    ofstream fout( "C:/Users/User/Documents/GitHub/CSE-107-108/OOP-C++/IO-1/fout.txt", ios::out | ios::binary) ;
    if(!fout.is_open()){
        cout<<"Error!, Can't open file"<< endl;
    }

    char ch ;
    const char* chs = "Name : Kazi Istiak Uddin Toriqe\nRoll : 1905104" ; 
    fin.unsetf (ios :: skipws );
    while(!fin.eof()){
        fin >> ch ;
        if(ch == ' ' && ch!='\n')
            ch =',' ;
        if(!fin.eof()){
            fout.put(ch);
            //fout<<ch ;
        }
    }
    fout << "\n"<<chs ;
    fout << "\nGoodbye Folks\0" ;
    fin.close() ; 
    fout.close() ;
}