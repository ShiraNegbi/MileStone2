//
// Created by shay on 1/13/19.
//

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H


#include "../Searcher.h"
#include <queue>
template <class P>
class BestFirstSearch : public Searcher<P,State<P>*> {
public:
    State<P>* search(Searchable<P>* searchable) override{
        std::queue<State<P>*> open;
        std::queue<State<P>*> close;

        State<P>* initial = searchable->getInitialState();

        open.push(initial);

        while (!open.empty()) {
            State<P>* n = open.front();
            open.pop();

            if()
        }
    }
    int getNumberOfNodesEvaluated() override{
        return 0;
    }



};


#endif //MILESTONE2_BESTFIRSTSEARCH_H
