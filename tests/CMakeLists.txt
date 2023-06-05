project(tests)

add_executable(tests main.cpp)

target_include_directories(tests PUBLIC ../include)
target_link_libraries(tests PUBLIC -lgtest -lpthread neural)
