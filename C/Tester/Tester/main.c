#include <stdio.h>
typedef enum { red, amber, green} traffic_light;

int main( ) {
    
    traffic_light x = red;
    
    while (1)
        
        switch (x) {
                
            case amber: x = red; printf("R"); break;
                
            case red: x = green; printf("G"); break;
                
            case green: x = amber; printf("A"); break;
                
        }
    
}
