cmake_minimum_required(VERSION 3.17)
project(COS214_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(COS214_Project
        Aggressive.cpp
        Aggressive.h
        Base_Car_Measurements.cpp
        Base_Car_Measurements.h
        Component.cpp
        Component.h
        Concrete_Base_Car_Measurements.cpp
        Concrete_Base_Car_Measurements.h
        Conservative.cpp
        Conservative.h
        Driver.cpp
        Driver.h
        Driver_Management.cpp
        Driver_Management.h
        Engineering.cpp
        Engineering.h
        Engineering_Iterator.cpp
        Engineering_Iterator.h
        Moderate.cpp
        Moderate.h
        Overall.cpp
        Overall.h
        Performance_Indicator.cpp
        Performance_Indicator.h
        Prepared.cpp
        Prepared.h
        Preparedness.cpp
        Preparedness.h
        Pro.cpp
        Pro.h
        RaceDay_Strat.cpp
        RaceDay_Strat.h
        Risky.cpp
        Risky.h
        Rookie.cpp
        Rookie.h
        Skill_Level.cpp
        Skill_Level.h
        Stage.cpp
        Stage.h
        Statistics.cpp
        Statistics.h
        Testing_Stage.cpp
        Testing_Stage.h
        Unprepared.cpp
        Unprepared.h)
