CXXFLAGS = -std=c++17

all = libcurve.so demos demo

all : $(all)

$(all) : curve.h

libcurve.so : CXXFLAGS += -shared

demos : libcurve.so

demos : LDFLAGS = -L. -lcurve

demo : curve.cpp
