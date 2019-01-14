#ifndef FSMLIST_HPP_INCLUDED
#define FSMLIST_HPP_INCLUDED

#include "tinyfsm.hpp"

#include "pattern_recognizer.hpp"

using fsm_list = tinyfsm::FsmList<PatternRec>;

/** dispatch event to "PatternRec" */
template<typename E>
void send_event(E const & event)
{
  fsm_list::template dispatch<E>(event);
}


#endif
