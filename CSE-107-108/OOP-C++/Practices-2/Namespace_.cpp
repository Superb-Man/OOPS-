#include<iostream>
#include<string.h>
using namespace std;
namespace infrastructure{
    class pool{
        int height,width,depth;
        char painted_color[10];
    public:
        void set_properties(int h,int w ,int d,char *pc)
        {
            height=h;
            width=w;
            depth=d;
            strcpy(painted_color,pc);
        }
        void show()
        {
            cout<<height<<" "<<width<<" "<<depth<<" "<<painted_color<<endl;
        }
    };
}
namespace sports{
    class pool{
        char table_ingradient[10];
        char table_color[10];
    public:
        void set_properties(char *ti,char *tc)
        {
            strcpy(table_ingradient,ti);
            strcpy(table_color,tc);
        }
        void show()
        {
            cout<<table_ingradient<<" "<<table_color<<endl;
        }

    };
}
int main()
{
    infrastructure::pool P1;
    //pool P1;
    P1.set_properties(1, 2, 3, "Blue");
    P1.show();
    using namespace sports;
    pool P2;
    P2.set_properties("IN", "Red");
    P2.show();
    return 0;
}