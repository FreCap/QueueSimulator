cmake_minimum_required(VERSION 3.3)
project(Simulatore_di_coda)


set(SOURCE_FILES buffer.h calendar.h main.cpp buffer.cpp calendar.cpp easyio.cpp event.cpp packet.cpp queue.cpp rand.cpp simulator.cpp stat.cpp)
add_executable(Simulatore_di_coda ${SOURCE_FILES})