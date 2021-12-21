#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

int main() {
   while (true){
    //  string com1 = "cd";
        // cout << com1 << endl;
    // system(com1.c_str()); // ham thuc hien lenh he thong
        // string comm = "cd /home/dung/Get_Event/personcount111/build";
        // cout << comm << endl;
    // system(comm.c_str()); // ham thuc hien lenh he thong
    string com = "./DistancingTest";
        // cout << comm << endl;
    system(com.c_str()); // ham thuc hien lenh he thong
    usleep(300000);
   }
  return 0;
}
