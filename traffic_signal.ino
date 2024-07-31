int time_slot;
void setup() {
  pinMode(2,OUTPUT);//signal 1 red led
  pinMode(3,OUTPUT); //signal 1 yellow led
  pinMode(4,OUTPUT); //signal 1 green led
   pinMode(5,OUTPUT); //signal 2 red led
  pinMode(6,OUTPUT); //signal 2 yellow led
  pinMode(7,OUTPUT); //signal 2 green led
   pinMode(8,OUTPUT); //signal 3 red led
  pinMode(9,OUTPUT); //signal 3 yellow led
  pinMode(10,OUTPUT); //signal 3 green led
   pinMode(11,OUTPUT); //signal 4 red led
  pinMode(12,OUTPUT); //signal 4 yellow led
  pinMode(13,OUTPUT); //signal 4 green  led
 Serial.begin(9600);
  Serial.println("Enter 1,2,3 or 4 to see\n traffic during 3am to 6am,6am to 9am,,\n9am to 9pm and 9pm to 3am respectively");
 
while(Serial.available()==0)
{
 
}
  time_slot=Serial.parseInt();
  Serial.println(time_slot);
}

void loop() {
  
   if(time_slot==1)
  {
   for(int i=3; i<=12; i=i+3)
   {
    digitalWrite(i,HIGH);
   }
   delay(1000);
   for(int i=3;i<=12;i=i+3)
   {
     digitalWrite(i,LOW);
   }
   delay(1000);
  }
  else if(time_slot==2 || time_slot==4)
  {
    for(int i=3;i<=12;i=i+3)
    {
       digitalWrite(i+1,HIGH);
       for(int j=2;j<=11;j=j+3)
       {
        if(j!=i-1)
        digitalWrite(j,HIGH);
       }
       delay(3000);
       digitalWrite(i+1,LOW);
       digitalWrite(i,HIGH);
       delay(1000);
        for(int j=2;j<=11;j=j+3)
       {
        if(j!=i-1)
        digitalWrite(j,LOW);
       }
       digitalWrite(i,LOW);
    }
  }
  else if(time_slot==3)
  {
   for(int i=3;i<=6;i=i+3)
   {
    digitalWrite(i+1,HIGH);
    digitalWrite(i+7,HIGH);
    digitalWrite(i+2,HIGH);
    digitalWrite((i+8)%12,HIGH);
    delay(3000);
    digitalWrite(i+1,LOW);
    digitalWrite(i+7,LOW);
    digitalWrite(i,HIGH);
    digitalWrite(i+6,HIGH);
    delay(1000);
    digitalWrite(i,LOW);
    digitalWrite(i+6,LOW);
    digitalWrite(i+2,LOW);
    digitalWrite((i+8)%12,LOW);
   }
  }
}
