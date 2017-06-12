// Using for unit testing
#include "search/bfs.h"

int main(void) {
  STATE *start = create_new_state(),
  *target = create_new_state() , *end;
  int start_data[9] = {2,3,7,1,8,6,5,0,4} ,
  target_data[9] = {1,2,3,4,5,6,7,8,0};
  set_state_data(start,start_data);
  set_state_data(target,target_data);
  end = bfs(start,target);
  printf("%p",end);
}