#include <iostream>
#include <string>
#include "mat.hpp"

int main(){
    cout<<
"___  ___  ___ _____  ______ _____ _____ _____ _____  _   _  ___________  \n"
"|  \\/  | / _ \\_   _| |  _  \\  ___/  ___|_   _|  __ \\| \\ | ||  ___| ___ | \n"
"| .  . |/ /_\\ \\| |   | | | | |__ \\ `--.  | | | |  \\/|  \\| || |__ | |_/ / \n"
"| |\\/| ||  _  || |   | | | |  __| `--. \\ | | | | __ | . ` ||  __||    /  \n"
"| |  | || | | || |   | |/ /| |___/\\__/ /_| |_| |_\\ \\| |\\  || |___| |\\ \\  \n"
"\\_|  |_/\\_| |_/\\_/   |___/ \\____/\\____/ \\___/ \\____/\\_| \\_/\\____/\\_| \\_| \n";
                                                                        
                                                                    
    cout<<"Welcome to the mat designer..."<<endl;
    while(true){
        
        int w;
        int l;
        char c;
        char spacing;
        cout<<"Enter mat witdh (MUST BE ODD): ";
        cin>>w;
        cout<<endl;
         cout<<"Enter mat length (MUST BE ODD): ";
        cin>>l;
        cout<<endl;
         cout<<"Enter first design (any printable char): ";
        cin>>c;
        cout<<endl;
         cout<<"Enter second design (any printable char): ";
        cin>>spacing;
        cout<<endl;
        if(w%2==0){
            cout<< "Error! width must be odd."<<endl;
            continue;
        }
        if(l%2==0){
            cout<< "Error! length must be odd."<<endl;
            continue;
        }
        if(std::isprint(c)==0){
             cout<< "Error! first char must be printable."<<endl;
            continue;
        }
          if(std::isprint(spacing)==0){
             cout<< "Error! second char must be printable."<<endl;
            continue;
        }
        cout<<ariel::mat(w,l,c,spacing)<<endl;
        cout<<"Good Design!!"<<endl;
        cout<<endl;
        cout<<"Time to design our next mat!"<<endl;
        cout<<"----------------------------"<<endl;
    }
    return 0;
}