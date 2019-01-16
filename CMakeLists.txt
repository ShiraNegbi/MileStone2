cmake_minimum_required(VERSION 3.12)
project(MileStone2)

set(CMAKE_CXX_STANDARD 14)

add_executable(MileStone2 main.cpp server_side.h  ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CacheManager.h FileCacheManager.cpp FileCacheManager.h StringReverser.cpp StringReverser.h DFS.h DFS.cpp BFS.cpp BFS.h AStar.cpp AStar.h BestFirstSearch.cpp BestFirstSearch.h MyClientHandler.cpp MyClientHandler.cpp MyClientHandler.h GeneralFirstSearch.h GeneralFirstSearch.cpp State.h State.cpp MatrixProblem.cpp MatrixProblem.h SearcherSolver.cpp SearcherSolver.h MatrixSolution.cpp MatrixSolution.h)