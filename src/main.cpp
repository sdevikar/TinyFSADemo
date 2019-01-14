#include <iostream>
#include <sstream>

#include "../inc/tinyfsm.hpp"
#include "../inc/fsmlist.hpp"

using namespace std;

// ----------------------------------------------------------------------------
// Main
//
int main()
{

  fsm_list::start();
  stringstream ss;
  bool continue_flag = true;

  BitIn bIn;

  while(continue_flag)
  {
    char c;
    std::cout << std::endl << "Enter 0 or 1 or 1 to quit ";
    std::cin >> c;

    switch(c) {
    case '0':
      ss << c;
      std::cout << "Input so far\t" << ss.str() << std::endl;
      bIn.bit = c;
      send_event(bIn);
      break;
    case '1':
      ss << c;
      std::cout << "Input so far\t" << ss.str() << std::endl;
      bIn.bit = c;
      send_event(bIn);
      break;

    case 'q':
      std::cout << "Quitting" << std::endl;
      //fsm_handle::dispatch(toggle);
      continue_flag = false;
      break;
    default:
      std::cout << "> Invalid input" << std::endl;
      break;
    };
  }

  return 0;
}
