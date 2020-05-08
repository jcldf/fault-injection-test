char incomingByte;
int acumulador = 0;
//int topo = 14200;
int topo = 15;
void setup() {
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
  IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_08 = 0xFF;
 //noInterrupts();
  Serial.begin(9600);
}

void loop() {
    
    if(Serial.available()){
    incomingByte = Serial.read();
    if(incomingByte == 's'){
    if(acumulador <= topo){
       digitalWriteFast(5, HIGH);
       acumulador++;
    }
      digitalWriteFast(5, LOW);
    
    Serial.println("enviando glitch de 14200 ciclo");
   
     } 

    if(incomingByte == 'd'){


    digitalWriteFast(5, LOW);
    digitalWriteFast(5, LOW);
    digitalWriteFast(5, LOW);
    digitalWriteFast(5, LOW);
    digitalWriteFast(5, LOW);
    digitalWriteFast(5, LOW);
    digitalWriteFast(5, HIGH);
    Serial.println("enviando glitch de 7 ciclos");
   
      } 
      
    if(incomingByte == 'a'){

    digitalWriteFast(5, LOW);
    delayMicroseconds(1);
    digitalWriteFast(5, HIGH);
    Serial.println("enviando glitch de 1 microsegundo");
   
      }

    if(incomingByte == 'f'){

    for (int i = 0; i <=1000000000; i++){
    digitalWriteFast(5, LOW);
    digitalWriteFast(5, LOW);
    digitalWriteFast(5, LOW);
    digitalWriteFast(5, LOW);
    digitalWriteFast(5, LOW);
    digitalWriteFast(5, LOW);
    digitalWriteFast(5, LOW);
    digitalWriteFast(5, LOW);
    digitalWriteFast(5, LOW);
    digitalWriteFast(5, LOW);
    digitalWriteFast(5, HIGH);
    digitalWriteFast(5, HIGH);
    digitalWriteFast(5, HIGH);
    digitalWriteFast(5, HIGH);
    digitalWriteFast(5, HIGH);
    digitalWriteFast(5, HIGH);
    digitalWriteFast(5, HIGH);
    digitalWriteFast(5, HIGH);
    digitalWriteFast(5, HIGH);
    digitalWriteFast(5, HIGH);
    }

    Serial.println("testando osciloscopio - fim do teste");
      
      }
    
   
    if(incomingByte == 't'){
      acumulador = acumulador + 1;
      Serial.print("valor do acumulador: ");
      Serial.println(acumulador);
      int cont = acumulador;
      for(cont; cont <= topo; cont++){
        digitalWriteFast(5, LOW);
        
      }
      digitalWriteFast(5, HIGH);
     }
    
   }
    
}
