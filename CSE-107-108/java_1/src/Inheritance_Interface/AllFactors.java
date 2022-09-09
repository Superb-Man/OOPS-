package Inheritance_Interface;

class AllFactors extends List implements Factorize {
    public AllFactors() {
        super();
    }

    public List factors(int n) {
        List list = new List();
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                list.push(i);
                if (n / i != i)
                    list.push(n / i);
            }
        }

        list.setList();
        return list;
    }
}
