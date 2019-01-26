#include "islands.h"

int main(){
  vector< vector<int> > region = {{1,0,0,1,0}, // 4 islands
                                  {1,0,0,0,0},
                                  {1,0,0,1,1},
                                  {0,0,1,1,1},
                                  {1,0,0,0,1}};
  
  //print_elements(region);
  cout<< count_islands(region)<<endl;
                            
  return 0;
}