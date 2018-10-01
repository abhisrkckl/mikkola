CXX=g++
SWIG = swig3.0

CXXFLAGS = -Wall -fPIC
LDFLAGS = -lm
PYTHONI = -I/usr/include/python3.6/


.PHONY: tests
tests: test_ellipse test_hyperbola

.PHONY: python_interface lib

python_interface: lib

lib: _mikkola.so

_mikkola.so: mikkola.o mikkolah.o mikkola_wrap.o
	$(CXX) -shared -o $@ $^ $(CXXFLAGS) $(LDFLAGS)
	chmod -x $@

mikkola_wrap.o: mikkola_wrap.cxx mikkola.h
	$(CXX)  -o $@ -c $< $(CXXFLAGS) $(PYTHONI)

mikkola_wrap.cxx: mikkola.i mikkola.h
	$(SWIG) -o $@ -c++ -python  $<

test_ellipse: test_ellipse.o mikkola.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

test_hyperbola: test_hyperbola.o mikkolah.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

test_ellipse.o: test_ellipse.cpp mikkola.h
	$(CXX) -o $@ -c $< $(CXXFLAGS)
	
test_hyperbola.o: test_hyperbola.cpp mikkola.h
	$(CXX) -o $@ -c $< $(CXXFLAGS)

mikkola.o: mikkola.cpp mikkola.h
	$(CXX) -o $@ -c $< $(CXXFLAGS)

mikkolah.o: mikkolah.cpp mikkola.h
	$(CXX) -o $@ -c $< $(CXXFLAGS)


.PHONY: clean
clean:
	rm *.o test_ellipse test_hyperbola

