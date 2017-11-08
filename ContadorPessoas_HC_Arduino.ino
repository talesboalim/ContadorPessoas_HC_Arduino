/* Sensor Ultrasônico SC
 * https://www.filipeflop.com/wp-content/uploads/2017/07/58594_16826.jpg */

int hcPinoEcho1 = 9;// digital verde
int hcPinoEcho2 = 10;// digital verde
int hcPinoTr = 2;//digital amarelo
int hcMedia1 = 0;//Média do sensor
int hcMedia2 = 0;//Média do sensor

int dist = 0;

void hcIniciarSensor(){
  int x,dist;
  Serial.println("Calculando Média: ");
  hcMedia1=0;
  hcMedia2=0;
  for (x=1;x<=10;x++){
    Serial.print(x);
    Serial.print("/10=");
    dist=hcDistancia(hcPinoEcho1);
    Serial.println(dist);
    hcMedia1 = hcMedia1 + dist;
    
    Serial.print(x);
    Serial.print("/10=");
    dist=hcDistancia(hcPinoEcho2);
    Serial.println(dist);
    hcMedia1 = hcMedia1 + dist;

  }
  hcMedia1 = hcMedia1 / 10;
  hcMedia2 = hcMedia2 / 10;
  Serial.print("Média encontrada: ");
  Serial.println(hcMedia1);
  Serial.println(hcMedia2);
}

int hcDistancia(int PinoEcho){
  long duration, distance;
  digitalWrite(hcPinoTr, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(hcPinoTr, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(hcPinoTr, LOW);
  duration = pulseIn(PinoEcho, HIGH);
  distance = (duration/2) / 29.1;
  return  distance;
}

void setup() {
  Serial.begin(9600);  // sets the serial port to 9600
  pinMode(hcPinoTr, OUTPUT);
  pinMode(hcPinoEcho1, INPUT);
  pinMode(hcPinoEcho2, INPUT);
  
  hcIniciarSensor();
}

void loop() {
  dist = hcDistancia(hcPinoEcho1);
  Serial.print("HC1=");
  Serial.print(dist);
  dist = hcDistancia(hcPinoEcho2);
  Serial.print("                    HC2=");
  Serial.println(dist); 
  
}
