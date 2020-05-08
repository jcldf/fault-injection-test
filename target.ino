int loopnumber = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  int ctr = 0;
  loopnumber++;
  for(int i=0; i<500; i++){
    for(int j=0; j<500; j++) {
      if (j % 100 == 0){
        ctr++;
      }
    }
  }

  Serial.print (loopnumber);
  Serial.print (" - ");
  Serial.print ("controle: ");
  Serial.println(ctr);
  
}
