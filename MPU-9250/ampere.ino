//File for work with amperemetre
int ampere;
#define KEY 7
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(KEY, OUTPUT);
  Serial.println("START\n");
}

void loop() {
  ampere = analogRead(1);
  Serial.println(ampere);
  if (ampere > 550)
    digitalWrite(KEY, HIGH);
  else
    digitalWrite(KEY, LOW);
}
