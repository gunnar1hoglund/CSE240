#include <iostream>
using namespace std;

class Rectangle {
private:
    int width, height;
public:
    void set_values (int,int);
    int area ();
};

int main()
{
    Rectangle *a = new Rectangle[2];
    
    a[0]->set_values(1,1);
    
    a[1]->set_values(2,2);

}
