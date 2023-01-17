#include <iostream>
using namespace std;
enum status{nil, red, green};
class trafficlight{
    private:
    status stat;
    int light;
    public:
    trafficlight(){
            stat=red;
            light=stat;
        }
    trafficlight(int chan){
        if (chan!=1&&chan!=2){
            cout<<"invalid value, reenter: ";
            cin>>chan;
        }
        else {
            light=chan;
            if (light==1){
                stat=red;
                light=stat;
            }
            else {
                stat=green;
                light=stat;
            }
        }
    }
    void switchlight(){
        stat=red;
         if (stat==1){
             light=stat+1;
         }
         else if(stat==2){
             light=stat-1;
         }
    }
    void showstat(){
         if (light==1){
             cout<<"the signal is red"<<endl;
         }
         else if(light==2){
              cout<<"the signal is green"<<endl;
         }
    }

};
int main(){
trafficlight obj;
trafficlight obj2(2);
obj.switchlight();
obj.showstat();
}