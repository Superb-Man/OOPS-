#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int* a ;
	int b;
}MyStruct ;

int main()
{
	MyStruct obj1,obj2,obj3;
	obj2.a = (int* )malloc(5*sizeof(int)) ;
	obj1.a = (int* )malloc(5*sizeof(int));
	
	*obj1.a =40;    obj1.b =20;
    
    /***********Same thing using different method*******/

	memcpy((MyStruct* )&obj2,(MyStruct* )&obj1,sizeof(MyStruct));
	memcpy((MyStruct* )&obj3,(MyStruct* )&obj2,sizeof(MyStruct)) ;
	*obj2.a = 190 ;
	/***************/
	
	printf ( "Obj1 Values\na:%d and b:%d\n",*obj1.a,obj1.b  );
	printf ( "Obj2 Values\na:%d and b:%d\n",*obj2.a,obj2.b  );
	printf ( "Obj3 Values\na:%d and b:%d\n",*obj3.a,obj3.b  );
	
	printf ("obj1 = %p\nobj2 = %p\nobj3 = %p\n", &obj1.a,&obj2.a,&obj3.a) ;
	//The adress of the pointer variable
	printf ("obj1.a = %p\nobj2.a = %p\nobj3.a = %p\n", obj1.a,obj2.a,obj3.a) ; //All a points to the same location .
	

    free(obj1.a) ;
    //free(obj2.a) ;//Will cause error because both obj1.a and ob2.a points to same location
    //free(obj2.a) ; //Will cause error.Because there's no memory allocation 
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
obj1.a = 00BC0CF8
obj2.a = 00BC0CF8
obj3.a = 00BC0CF8
*/