//cada pin pode ser output ou input; HIgh significa 5v e low 0v
//O codigo corre sempre em loop
//Long leg (mais) Smaller leg (menos)
/* Ligar o ground como 0 (preto)
Resistência tem de ser ligada do vermelho à pata curta da luz
a pata grande tem de ser ligada ao output
uma reststencia tem cores a simbolizar numeros vermelhor-vemelho-castanho é 2*2*10, vermelho-vermelho-vermelho é 2*2*100
 // definir a entrada do pin em q a luz liga
usar wokwi.com para simulação do arduino */

int sensorValue = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  int value = analogRead(A0);
  Serial.println("Analog  Value: ");
  Serial.println(value);
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A0);
  if (value < 600){
    analogWrite(9, map(sensorValue, 0, 1023, 0, 255));  
    
  }else{
    analogWrite(9, 0);
  }
  delay(100);
  Serial.println(sensorValue);
   // Wait for 100 millisecond(s)
}
