cmake_minimum_required(VERSION 3.12)
project(MileStone2)

set(CMAKE_CXX_STANDARD 14)

add_executable(MileStone2 main.cpp server_side.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h Problem.h Solution.h CacheManager.h FileCacheManager.cpp FileCacheManager.h Searchable.h State.cpp State.h Searcher.h DFS.cpp DFS.h)