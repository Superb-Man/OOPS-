#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int* a ;
	int b;
}MyStruct ;

int main()
{
	MyStruct obj1,obj2;
	obj2.a = (int* )malloc(5*sizeof(int)) ;
	obj1.a = (int* )malloc(5*sizeof(int));
	
	*obj1.a =40;    obj1.b =20;
    
    /*****Assigning .Dynamically alloacted  variable(within structures) has an effect if any of 
     structure variable changes the value. Unlike C++ , Here the adress is copied******/
	obj2 = obj1 ;
	MyStruct obj3=obj1;
	
	*obj2.a = 190 ; //All changes
	/***************/
	
	printf ( "Obj1 Values\na:%d and b:%d\n",*obj1.a,obj1.b  );
	printf ( "Obj2 Values\na:%d and b:%d\n",*obj2.a,obj2.b  );
	printf ( "Obj3 Values\na:%d and b:%d\n",*obj3.a,obj3.b  );
	
	printf ("obj1 = %p\nobj2 = %p\nobj3 = %p\n", &obj1.a,&obj2.a,&obj3.a) ;
	//The adress of the pointer variable
	printf ("obj1.a = %p\nobj2.a = %p\nobj3.a = %p\n", obj1.a,obj2.a,obj3.a) ; //All a points to the same location .
	

    free(obj1.a) ;
    //free(obj2.a) ;//Will cause error because both obj1.a and ob2.a points to same location
    //free(obj2.a) ; //Will cause error.Because there's no memory allocation and if allocated though, the memory has already been freed. 
}

/*
Obj1 Values   
a:190 and b:20
Obj2 Values    
a:190 and b:20 
Obj3 Values    
a:190 and b:20 
obj1 = 0060FEF8
obj2 = 0060FEF0
obj3 = 0060FEE8
obj1.a = 00B00CF8
obj2.a = 00B00CF8
obj3.a = 00B00CF8
*/