#ifndef PREC_HPP_INCLUDED
#define PREC_HPP_INCLUDED

#include "tinyfsm.hpp"

// ----------------------------------------------------------------------------
// Event declarations
//
struct BitIn : tinyfsm::Event {
  // single event for incoming bit
  char bit;
 };


// ----------------------------------------------------------------------------
// pattern_recognizer (FSM base class) declaration
//

class PatternRec : public tinyfsm::Fsm<PatternRec>{

public:

  /* default reaction for unhandled events */
  void react(tinyfsm::Event const &) { };
  virtual void react(BitIn const &);

  virtual void entry(void) { };  /* entry actions in some states */
  void         exit(void)  { };  /* no exit actions at all */

};



#endif
