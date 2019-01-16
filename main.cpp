#include <iostream>
#include "Searchable.h"
#include "Searcher.h"
#include "Searchers/BestFirstSearch.h"
#include "Searchers/DFS.h"
#include "Searchers/DummySearchable.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    //auto* searcher = new BestFirstSearch<int>();
    //searcher->search(new DummySearchable<int>());
    Searchable<int*>* searchable = new DummySearchable<int*>();
    auto* searcher = new BestFirstSearch<int*>();
    searcher->search(searchable);







    return 0;
}