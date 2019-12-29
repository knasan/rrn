TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        rrn.cpp \

HEADERS += \
        rrn.hpp

macx {
    QMAKE_CXXFLAGS += -std=c++11

    _BOOST_PATH = /usr/local/Cellar/boost/1.72.0
    INCLUDEPATH += "$${_BOOST_PATH}/include/"
    LIBS += -L$${_BOOST_PATH}/lib
    ## Use only one of these:
    LIBS += -lboost_filesystem -lboost_program_options -lboost_system # using dynamic lib (not sure if you need that "-mt" at the end or not)
    #LIBS += $${_BOOST_PATH}/lib/libboost_chrono-mt.a # using static lib
    #   -lboost_date_time \
    #   -lboost_regex \
    #   -lboost_signals \
}



