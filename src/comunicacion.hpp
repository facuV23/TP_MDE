#include <stdint.h>
#include <string>
#include <respuesta.hpp>

class comunicacion {
public:
comunicacion(string r): _respuesta(r){}
~comunicacion(){}

void init(){
    respuesta::init(r);
}
void fsm(){
    switch(State){
        case state::SALUDO:
            if(r=='hola')
            {
                hola();
                State=state::IDENTIFICACION;
            }
            break;
        case state::IDENTIFICACION:
            if(reconocer(r)==1){
                ok();
                State=state::PASS;
            }else{
                error();
            }
            break;
        case state::PASS:
            if(pass(r)==1){
                pass();
            }else{
                error();
            }
            break;
    }


}


private:

    string r;

    enum class state{
    SALUDO,
    IDENTIFICACION,
    PASS
    }State;

    void hola(){respuesta::hola(r);}
    void error(){respuesta::error(r);}
    void ok(){respuesta::ok(r);}
    bool reconocer(){respuesta::reconocer(r);}
    bool pass(){respuesta::pass(r);}

};