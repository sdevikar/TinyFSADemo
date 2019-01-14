#include "../inc/tinyfsm.hpp"
#include <iostream>


#include "../inc/pattern_recognizer.hpp"
#include "../inc/fsmlist.hpp"


using namespace std;


class State01; //forward declaration
class State10; //forward declaration
// ----------------------------------------------------------------------------
// State: State00
//

class State00
: public PatternRec
{
  void entry() override {
    std::cout << "Entered State00" << std::endl;
  }

  void react(BitIn const & e) override {
    if(e.bit == '0')
    {
      cout << "Transitioning to State01 after receiving: " << e.bit << endl;
      transit<State01>();
    }
    else
    {
      cout << "Transitioning to State00 after receiving: " << e.bit << endl;
      transit<State00>();
    }
  };
};


// ----------------------------------------------------------------------------
// State: State01
//

class State01
: public PatternRec
{
  void entry() override {
    std::cout << "Entered State01" << std::endl;
  }

  void react(BitIn const & e) override {
    if(e.bit == '1')
    {
      cout << "Transitioning to State10 after receiving: " << e.bit << endl;
      transit<State10>();
    }
    else
    {
      cout << "Transitioning to State01 after receiving: " << e.bit << endl;
      transit<State01>();
    }
  };
};


// ----------------------------------------------------------------------------
// State: State10
//

class State10
: public PatternRec
{
  void entry() override {
    std::cout << "Entered State10" << std::endl;
  }
  void react(BitIn const & e) override {
    if(e.bit == '0')
    {
      cout << "Transitioning to State01 after receiving: " << e.bit << endl;
      transit<State01>();
    }
    else
    {
      cout << "***SUCCESS!!!*** Transitioning to State00 after receiving: " << e.bit << endl;
      transit<State00>();
    }
  };
};



// ----------------------------------------------------------------------------
// Base state: default implementations
//

void PatternRec::react(BitIn const &) {
  cout << "Event ignored" << endl;
}


// ----------------------------------------------------------------------------
// Initial state definition
//
FSM_INITIAL_STATE(PatternRec, State00)
