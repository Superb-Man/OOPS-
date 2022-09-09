package Inheritance_Interface;

class List implements add_pop_list {
    protected int[] ara;
    protected int total;

    public List() {
        ara = new int[1];
        total = -1;
    }

    @Override
    public void push(int n) {
        if (ara.length - 1 == total) {
            int[] temp = new int[3 * ara.length];
            for (int i = 0; i < ara.length; i++) {
                temp[i] = ara[i];
            }

            ara = temp;
            ara[++total] = n;
        } else {
            ara[++total] = n;
        }
    }

    @Override
    public int pop() {
        if (total < 0) {
            return 0;
        }
        return ara[total--];
    }

    @Override
    public boolean isEmpty() {
        if (total == -1) {
            return true;
        }
        return false;
    }

    public int getNumber(int idx) {
        return ara[idx];
    }

    public void setList() {
        if (total > -1) {
            int[] temp = new int[total + 1];
            for (int i = 0; i < total + 1; i++) {
                temp[i] = ara[i];
            }
            ara = temp;
        }
    }

    public int getSize() {
        return total + 1;
    }
}
