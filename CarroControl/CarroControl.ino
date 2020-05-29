int izqA = 6; 
int izqB = 11; 
int derA = 5; 
int derB = 3; 
int vel = 200;            // Velocidad .de los motores (0-255)
int estado = 'c';         // inicia detenido
 
void setup()  { 
  Serial.begin(9600);    // inicia el puerto serial para comunicacion con el Bluetooth
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT); 
} 
 
void loop()  { 
  if(Serial.available()>0){        // lee el bluetooth y almacena en estado
    estado = Serial.read();
  }
    if(estado=='a'){           // Boton desplazar al Frente
      DeFrente();      
    }
    
    if(estado=='b'){          // Boton IZQ 
      GirarIzqierda();     
    }
    
    if(estado=='c'){         // Boton Parar
      Stop();  
    }
    
    if(estado=='d'){          // Boton DER
      GirarDerecha();
    } 
   
    if(estado=='e'){          // Boton Reversa
      Reversa();    
    }
}// fin void loop
 
//funciones
 
//funcion Stop
 
void Stop(){
    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, 0);    
    analogWrite(izqA, 0);  
}
 
// hacia a delante
 
void DeFrente(){
    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, vel);  
    analogWrite(izqA, vel);   
}
//Hace Girar a la Izquierda
void GirarIzqierda(){
    analogWrite(derB, 0);     
    analogWrite(izqB, 0);
    analogWrite(izqA, 0);
    analogWrite(derA, vel);
}
 
//Hace Girar a la Derecha
void GirarDerecha(){
    analogWrite(derB, 0);     
    analogWrite(izqB, 0); 
    analogWrite(derA, 0);  
    analogWrite(izqA, vel);         
}
// De Reversa
 
void Reversa(){
    analogWrite(derA, 0);    
    analogWrite(izqA, 0);
    analogWrite(derB, vel);  
    analogWrite(izqB, vel);  
}
