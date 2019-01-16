//
// Created by shay on 1/12/19.
//

#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H


    template <class T>
    class State {
    public:
        State(T state, double cost, State<T>* cameFrom, bool visited);

        T getValue() const;

        double getCost() const;

        State<T>* getCameFrom() const;

        bool isVisited() const;

        void setValue(T state);

        void setCost(double cost);

        void setCameFrom(State<T>* cameFrom);

        void setIsVisited(bool visited);

    private:
        T value;
        double cost;
        State<T>* cameFrom;
        bool visited;
};


#endif //MILESTONE2_STATE_H
