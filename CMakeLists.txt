cmake_minimum_required(VERSION 3.17)
project(Tema)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tema main.cpp location.cpp location.h clock_time.cpp clock_time.h date.cpp date.h person.cpp person.h gym.cpp gym.h exercise.cpp exercise.h trainer.cpp trainer.h client.h client.cpp boutique_gym.cpp boutique_gym.h crossfit_gym.cpp crossfit_gym.h powerlifting_gym.cpp powerlifting_gym.h too_many_clients.cpp too_many_clients.h exercise_factory.cpp exercise_factory.h wrong_type.cpp wrong_type.h)