#include <iostream>
#include "Searchable.h"
#include "Searcher.h"
#include "BestFirstSearch.h"
#include "DFS.h"
#include "Solver.h"
#include "SearcherSolver.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "ClientHandler.h"
#include "MyClientHandler.h"
#include "Check.h"

using std::pair;

int main(int argc, char* argv[]) {
    int port;
    if (argc < 2) {
        std::cerr << "Port number needs to be entered." << std::endl;
        return -1;
    }
    //get port number
    port = std::stoi(argv[1]);

    //define the variables of the searcher and the solver
    Searcher<pair<int, int>, State<pair<int, int>>*>* searcher;
    Solver<Searchable<pair<int, int>>*, State<pair<int, int>>*>* solver;
    //define the cacheManager and the clientHandler
    CacheManager* cacheManager;
    ClientHandler* clientHandler;

    //the searcher chosen to be injected is BestFirstSearch
    searcher = new BestFirstSearch<pair<int, int>>();
    //The solver is using SearcherSolver - an object adapter to solve a search problem
    solver = new SearcherSolver<pair<int, int>, State<pair<int, int>>*>(searcher);

    cacheManager = new FileCacheManager("problems_and_solutions.txt");
    clientHandler  = new MyClientHandler<Searchable<pair<int, int>>*, State<pair<int, int>>*>(solver, cacheManager);

//-------------------------------------------------------------------Delete after this please------------------------
//    PriorityQueue<State<int>*> priorityQueue = PriorityQueue<State<int>*>();
//    priorityQueue.push(new State<int>(5, 1.2, nullptr, false));
//
//    PriorityQueue<State<pair<int, int>>*> priorityQueue2 = PriorityQueue<State<pair<int, int>>*>();
//    priorityQueue2.push(new State<pair<int, int>>(pair<int,int>(1, 2), 5.6, nullptr, false));
    //   Check<pair<int,int>> check;
    //   check.foo(pair<int,int>(4,5));

    return 0;

}