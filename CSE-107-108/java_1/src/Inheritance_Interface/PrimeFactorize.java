package Inheritance_Interface;

class PrimeFactorize extends List implements Factorize {
    public PrimeFactorize() {
        super();
    }

    public List factors(int n) {
        List list = new List();
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                list.push(i);
                while (n % i == 0) {
                    n /= i;
                }
            }
        }
        if (n > 1) list.push(n);
        list.setList();
        return list;
    }
}
