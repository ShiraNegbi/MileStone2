cmake_minimum_required(VERSION 3.12)
project(MileStone2)

set(CMAKE_CXX_STANDARD 14)

add_executable(MileStone2 main.cpp server_side.h  ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CacheManager.h FileCacheManager.cpp FileCacheManager.h StringReverser.cpp StringReverser.h Searchers/DFS.h Searchers/DFS.cpp Searchers/BFS.cpp Searchers/BFS.h Searchers/AStar.cpp Searchers/AStar.h Searchers/BestFirstSearch.cpp Searchers/BestFirstSearch.h MyClientHandler.cpp MyClientHandler.cpp MyClientHandler.h MatrixHandler.cpp MatrixHandler.h Searchers/GeneralFirstSearch.h Searchers/GeneralFirstSearch.cpp Searchers/DummySearchable.cpp Searchers/DummySearchable.h State.h State.cpp)