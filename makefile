CXXFLAGS = -std=c++17

all = libcurve.so demos demo omps omp

all : $(all)

$(all) : curve.h

libcurve.so : CXXFLAGS += -shared -fPIC

demos omps : libcurve.so

demos omps : LDFLAGS = -L. -lcurve

demo omp : curve.cpp

omps omp : CXXFLAGS += -fopenmp
