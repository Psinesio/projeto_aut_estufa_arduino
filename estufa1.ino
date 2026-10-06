// C++ code
//


const int sensorTemp = A0;
const int led = 8;
const int buzzer = 9;
const int motor = 10;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(motor, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  // Leitura do sensor TMP36
  int leitura = analogRead(sensorTemp);

  // Conversão da leitura para tensão
  float tensao = leitura * (5.0 / 1023.0);

  // Conversão da tensão para temperatura em °C
  float temperatura = (tensao - 0.5) * 100.0;

  // Exibe a temperatura no monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  // Aciona o ventilador a partir de 30 °C
  if (temperatura >= 30.0)
  {
    digitalWrite(motor, HIGH);
  }
  else
  {
    digitalWrite(motor, LOW);
  }

  // Situação de emergência acima de 50 °C
  if (temperatura > 50.0)
  {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }

  delay(1000);
}