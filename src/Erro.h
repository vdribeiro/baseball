#ifndef ERRO_H_
#define ERRO_H_

#include <stdexcept>

class ErroFx {
    public:
		string ficheiro;
        ErroFx(string fx) {ficheiro = fx;}
};

class ErroVector {
    public:
		string vector;
        ErroVector(string vec) {vector = vec;}
};

class ErroSim {
    public:
		string simul;
        ErroSim(string sim) {simul = sim;}
};

class BadIterator { };

class NoMoreSpace { };

class BadPosition { };

class ErroInterno { };

class Underflow { };

class Overflow { };

class BadArgs { };

#endif
