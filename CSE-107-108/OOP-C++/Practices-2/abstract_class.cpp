#include<iostream>
#include<cstring>
using namespace std ;

class Media{
protected:
    char media_name[100] ;
    int   popularity ;
public:
    Media(){
        
    }
    Media(char* media_name,int popularity){
        this->popularity = popularity ;
        strcpy(this->media_name, media_name) ;
    }
    int get_popularity(){ return popularity ; } 
    char* get_media() { return media_name ; }
    ~Media(){
        
    }
};
class Hero{
    int   power , rating ;
    char  hero_name[20] ;
    char comic_name[20] ;
public:
    Hero(){
        
    }
    Hero(char* hero_name,char* comic_name,int power,int rating){
        this->rating = rating ;
        this-> power = power ;
        strcpy(this->hero_name , hero_name) ;
        strcpy(this->comic_name , comic_name) ;
    }
    int get_rating(){ return rating ; }
    int get_power(){ return power ; }
    char* get_comicName(){ return comic_name ; }
    char* get_heroName() { return hero_name ; }
    ~Hero(){
        
    }
};

class comics{

protected:
    char* name ;
    Hero* male ;
    Hero* female ;
public:
    virtual void action() = 0 ;
    virtual void set_media(Media*,int) = 0;
    void set_name(char* name){
        this->name = new char[100] ;
        strcpy(this->name , name) ;
        
    }
    virtual ~comics(){
        delete [] name ;
    }
};

class DC_Comics : public comics{
    int IMDB_rating ;
    Media* medias ;
    int all_media ;
public:
    DC_Comics(char* name ,Hero* male, Hero* female,int IMDB_rating) {
        this->male   = new Hero[4] ;
        this->female = new Hero[4] ;
        for(int i = 0;i<4;i++){
            this->male[i] = male[i] ;
            this->female[i] = female[i] ;
        }
        set_name(name) ;
        this->IMDB_rating = IMDB_rating ;
        all_media = 0 ;
    }
    void set_media(Media* medias,int length){
        int i = 0 ;
        this->medias = new Media[10] ;
        while(i<length){
            this->medias[i++] = medias[i] ;
        }
        all_media = i ;
    }
    void all_medias(){
        for(int i=0 ;i<all_media ;i++){
            cout<<medias[i].get_media()<<endl;
        }
    }
    
    void action(){
        for(int i =0 ;i<4 ;i++){
            if(female[i].get_power() > male[i].get_power()){
                cout<<female[i].get_comicName()<<"("<<female[i].get_heroName()<<")"<<" kills "<<male[i].get_comicName()<<"("<<male[i].get_heroName()<<")"<<endl;
                
            }
            else if(female[i].get_power() < male[i].get_power()){
                cout<<male[i].get_comicName()<<"("<<male[i].get_heroName()<<")"<<" kills "<<female[i].get_comicName()<<"("<<female[i].get_heroName()<<")"<<endl;
                
            }
            else {
                cout<<male[i].get_comicName()<<"("<<male[i].get_heroName()<<")"<<" marries "<<female[i].get_comicName()<<"("<<female[i].get_heroName()<<")"<<endl;
            }
        }
    }
    int get_IMDB_rating(){ return IMDB_rating ; } 
    ~DC_Comics(){
        delete [] medias ;
        delete [] male ;
        delete [] female ;
    }
       
};

class Marvel_Comics : public comics{
    int fans_rating ;
    Media* medias ;
    int all_media ;
public:
    Marvel_Comics(char* name ,Hero* male, Hero* female,int fans_rating){
        this->male   = new Hero[4] ;
        this->female = new Hero[4] ;
        for(int i = 0;i<4;i++){
            this->male[i] = male[i] ;
            this->female[i] = female[i] ;
        }
        set_name(name) ;
        this->fans_rating = fans_rating ;
        all_media = 0 ;
    }
    void set_media(Media* medias,int length){
        int i = 0 ,j=0;
        this->medias = new Media[10] ;
        while(j++<length){
            if(medias[j-1].get_popularity() > 6){
                this->medias[i++] = medias[j-1] ;   
            }
        }
        all_media = i ;
    }
    
    void all_medias(){
        for(int i=0 ;i<all_media ;i++){
            cout<<medias[i].get_media()<<endl;
        }
    }
    
    void action(){
        for(int i =0 ;i<4 ;i++){
            if(female[i].get_power()*female[i].get_rating() > male[i].get_power()*male[i].get_rating()){
                cout<<female[i].get_comicName()<<"("<<female[i].get_heroName()<<")"<<" kills "<<male[i].get_comicName()<<"("<<male[i].get_heroName()<<")"<<endl;
                
            }
            else if(female[i].get_power()*female[i].get_rating() < male[i].get_power()*male[i].get_rating()){
                cout<<male[i].get_comicName()<<"("<<male[i].get_heroName()<<")"<<" kills "<<female[i].get_comicName()<<"("<<female[i].get_heroName()<<")"<<endl;
                
            }
            else {
                cout<<male[i].get_comicName()<<"("<<male[i].get_heroName()<<")"<<" marries "<<female[i].get_comicName()<<"("<<female[i].get_heroName()<<")"<<endl;
            }
        }
    }
    int get_fans_rating() { return fans_rating ; }
    ~Marvel_Comics(){
        delete [] medias ;
        delete [] male ;
        delete [] female ;
    }
} ;

int main(){
    Hero Dc_hero1[4] ={Hero("Batman","Bruce Wayne",100,9), Hero("Superman","Clarck",200,9),Hero("Aquaman","Arthur",150,8), Hero("Flash","Barry",100,7) };
    Hero Dc_hero2[4] = { Hero("Catwoman","Selina Kyle",100,8) , Hero("No HeroName","Lois Lane",0,8),Hero("No HeroName","Mera",150,4),Hero("WonderWoman","Diana",200,6) } ;
    DC_Comics Dc("DC_Vol_1",Dc_hero1,Dc_hero2,10) ;
    Dc.action() ;
    cout<<endl ; 
    Media DC_medias[3] = { Media("Warner Brothers",9),Media("Legendary",9),Media("Universal",8) } ;
    Dc.set_media(DC_medias,3) ;
    Dc.all_medias() ;
    cout<<endl;  
    
    Hero Marvel_hero1[4] ={Hero("Iron Man","Tony",100,9), Hero("Captain America","Steve Rogers",100,8),Hero("Son of Odin","Thor",100,8), Hero("Hulk","Banner",150,6) } ;
    Hero Marvel_hero2[4] ={ Hero("No Hero name","Pepper Pots",10,8) , Hero("No HeroName","Peggy",200,4),Hero("No nickname","Jane Foster",150,6),Hero("Black Widow","Natasha",100,9) } ;
    Marvel_Comics Mr("Marvel_Vol_1", Marvel_hero1,Marvel_hero2,9) ;
    Mr.action() ;
    cout<<endl;
    Media Marvel_medias[3] = {Media("Disney",9),Media("Marvel Studios",5),Media("20th Fox",7)};
    Mr.set_media(Marvel_medias,3) ;
    Mr.all_medias() ;
    
}
