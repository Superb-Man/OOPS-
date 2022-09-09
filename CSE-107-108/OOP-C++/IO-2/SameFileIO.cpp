#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>

using namespace std ;
int main(){
    fstream file("C:/Users/User/Documents/GitHub/CSE-107-108/OOP-C++/IO-2/List.txt",ios::out | ios::in | ios::binary | ios :: app) ;
    ofstream fout("C:/Users/User/Documents/GitHub/CSE-107-108/OOP-C++/IO-2/List2.txt",ios::out | ios::binary) ;
    if(!file){
        cout<<"Not Opened"<<endl;
        return 0 ;
    }

    string s ;   int i =0 ;
    file.unsetf (ios :: skipws );

    while(i++<3){
        getline(cin,s) ;
        //file << s ;
        //or ->
        for(int j = 0 ; s[j] ; j++)  file.put(s[j]) ;
        file.put('\n') ;
    }
    

    file.seekg(0,ios::beg) ;
    
    string tokens[3] ;
    file.unsetf (ios :: skipws );
    while(getline(file,s)){
        stringstream check(s) ;
        string copy ;
        i = 0 ;
        while(getline(check,copy,',')){
            tokens[i++] = copy ;
        }
        cout<<tokens[0]<<"  "<<tokens[1]<<" "<<tokens[2]<<endl;
        fout << s <<'\n' ;

    }

    fout.close() ;
    file.close() ;



}