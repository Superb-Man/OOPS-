package Inheritance_Interface;

public class MyFactorization {
    public static void main(String []args){
        PrimeFactorize P = new PrimeFactorize() ;
        AllFactors all   = new AllFactors() ;
        for(int i=1 ;i<= 100 ;i++){
            P.push(i) ;
            all.push(i);
        }
        System.out.println(P.getSize());
        P.setList() ;
        all.setList() ;
        System.out.println(P.getSize());
        for(int i = -12 ; i <= 120 ;i++){
            try{
                List list1 = P.factors(P.getNumber(i)) ;
                List list2 = all.factors(all.getNumber(i)) ;
                if(list1.isEmpty() == true ){
                    System.out.println("There's no prime factors of "+P.getNumber(i));
                    if(all.getNumber(i) == 1){
                        System.out.println("factors of 1 : 1");
                    }
                    System.out.println();
                }
                else{
                    System.out.print("Prime factors of "+ P.getNumber(i) + " are : ");
                    for(int j = 0 ; j < list1.getSize() ; j++){
                        System.out.print(list1.getNumber(j)+" ");
                    }
                    System.out.println();
                    System.out.print("factors of "+ all.getNumber(i) + " are : ");
                    for(int j = 0 ; j < list2.getSize() ; j++){
                        System.out.print(list2.getNumber(j)+" ");
                    }
                    System.out.println() ;
                    System.out.println() ;
                }
            }catch (NullPointerException | ArrayIndexOutOfBoundsException e){
                System.out.println(e);
            }
        }
    }
}
