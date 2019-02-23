cmake_minimum_required(VERSION 3.12)
project(MileStone2)

set(CMAKE_CXX_STANDARD 14)

add_executable(MileStone2 main.cpp server_side.h  ClientHandler.h Solver.h CacheManager.h FileCacheManager.cpp FileCacheManager.h StringReverser.cpp StringReverser.h DFS.h DFS.cpp BFS.cpp BFS.h AStar.cpp AStar.h BestFirstSearch.cpp BestFirstSearch.h MyClientHandler.cpp MyClientHandler.cpp MyClientHandler.h GeneralFirstSearch.h GeneralFirstSearch.cpp State.h SearcherSolver.h MatrixSolution.cpp MatrixSolution.h PriorityQueue.h PriorityQueue.cpp MySerialServer.h MySerialServer.cpp MyClientHandler.h MyClientHandler.cpp MatrixProblem.h MatrixProblem.cpp Check.cpp Check.h MyParallelServer.h MyParallelServer.cpp)