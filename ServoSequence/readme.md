# Servo Sequence

Esta libreria te permite crear uan secuencia de movimientos con los servos, de manera asincronica y con la libreria de ServoEasyn se logra un suavisado perfecto para coordinar los movimientos de cualquier tipo de robot

Para incluir la libreria hay que colocar la siguiente linea:
```
#include <ServoSequence.h>
```
Una vez incluida la libreria se puede crear objetos *ServoSequence*

```
ServoSequence servo;    //Para crear el servoSequence
ServoSequence servo(false);     //Para crear el servoSequence sin el autoreplay
```

## Comandos

```
servo.add( Angle , Interval );      //Agrega una secuencia de determinado angulo y tiempo

servo.clear();       //Borra la secuencia establecida

servo.Init( pin );  //Inicia la secuencia en el pin indicado

servo.setContinuous( state );  //Para modificar el autoreplay

servo.Check();      //Debe estar incluida en el loop y ejecutarse a cada instante

```

## Ejemplo Sweep


```
#include <ServoSequence.h>
ServoSequence servo;

void setup() {
  servo.add(0,2000);
  servo.add(180,2000);
  servo.Init(2);
}

void loop(){
  servo.Check();
}
```