#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    int *a;
    int b;
} MyStruct;

void MyStruct_initialize(MyStruct* );
void Struct_copy(MyStruct* , const MyStruct*);
void Struct_print(const MyStruct*);

int main(void)
{
    MyStruct obj1 ,obj2 ;
    obj1.b = 10 ;
    
    obj1.a =(int* ) malloc(obj1.b * sizeof(int));
    MyStruct_initialize(&obj1);

    Struct_print(&obj1);
    Struct_copy(&obj2, &obj1);
    Struct_print(&obj2);
    
    printf ("obj1.a = %p\nobj2.a = %p\n", obj1.a,obj2.a) ;//Now working like copy . aAdress not copied ;
    
    for(int i = 0 ; i < obj2.b ;i++){
        obj1.a[i] = i*(obj1.a[i]) ;
        //Will not effect obj2 //
    }
    Struct_print(&obj2) ;
    Struct_print(&obj1) ;

    free(obj1.a);
    free(obj2.a);

    return 0;
}

void MyStruct_initialize(MyStruct *obj){
    for (int i = 0; i < obj->b; ++i){
        obj->a[i] = i;
    }
}


//Works like copy Constructor in c++ ;
void Struct_copy(MyStruct* _new, const MyStruct* _source){
    int *temp =(int *) malloc(_source->b * sizeof(_source->a[0]));
    if (temp){
        _new->b = _source->b;
        _new->a = temp;
        memcpy(_new->a, _source->a, _source->b *sizeof(_source->a[0])) ;
    }
}

void Struct_print(const MyStruct *obj)
{
    printf("%d: ",obj->b);
    if (obj->a){
        for (int i = 0; i < obj->b; ++i){
            printf("%d ", obj->a[i]);
        }
    }
    printf("\n");
}
/*
10: 0 1 2 3 4 5 6 7 8 9 
10: 0 1 2 3 4 5 6 7 8 9 
obj1.a = 007A0CC8
obj2.a = 007A0CF8
10: 0 1 2 3 4 5 6 7 8 9 
10: 0 1 4 9 16 25 36 49 64 81   
*/
