CXXFLAGS = -std=c++17

all = libcurve.so demo omp

all : $(all)

$(all) : curve.h

demo omp : libcurve.so

libcurve.so : curve.cpp

	$(CXX) $(CXXFLAGS) -fPIC -shared $< -o $@

% : %.cpp

	$(CXX) $(CXXFLAGS) $< libcurve.so -o $@

omp : CXXFLAGS += -fopenmp
