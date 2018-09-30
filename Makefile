CXX=g++

CXXFLAGS = -Wall -fPIC
LDFLAGS = -lm

.PHONY: tests
tests: test_ellipse test_hyperbola

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

