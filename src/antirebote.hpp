#include <stdint.h>
#include <tecla.hpp>
#include <timer.hpp>

 class antirebote{
     public:
     explicit antirebote(uint8_t tecla, uint32_t count): _tecla(tecla), _timer(count){}
     ~antirebote() {}

     void init(){
         tecla::init(_tecla);
     }

     void fsm(){

         switch(_State){
             case _state::SUELTO:
                if(_tecla==1){
                    ventana_desc();
                    _State=_state::VENTANA_D;
                    count=0;
                }
                break;
             case _state::VENTANA_D:
                if(count=50){ 
                presionado();
                _State=_state::PRESIONADO;
                }
                break;
                case _state::PRESIONADO:
                if(_tecla==0){
                    ventana_asce();
                    _State=_state::VENTANA_A;
                    count=0;
                }
                break;

             case _state::VENTANA_A:
                if(count=50){
                    suelto();
                    _State=_state::SUELTO;
                }
                break;

             default:
                 init();

         }


     }

     private:

     uint8_t _tecla;
     int32_t count;
      enum class _state{
         SUELTO,
         VENTANA_D,
         PRESIONADO,
         VENTANA_A
        }_State;

      void suelto (){tecla::suelto(_tecla);}
      void ventana_desc (){tecla::ventana_desc(_tecla);}
      void presionado (){tecla::presiono(_tecla);}
      void ventana_asce(){tecla::ventana_asce(_tecla);}

 }; 