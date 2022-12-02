const int   m1_1 = 7;
const int   m1_2 = 8;

const int   m2_1 = 9;
const int   m2_2 = 10;

void setup()
{

pinMode(m1_1,OUTPUT);
pinMode(m1_2,OUTPUT);
pinMode(m2_1,OUTPUT);
pinMode(m2_2,OUTPUT);

digitalWrite(m1_1,HIGH);
digitalWrite(m1_2,HIGH);
digitalWrite(m2_1,HIGH);
digitalWrite(m2_2,HIGH);

}

void loop()
{
  
while(1)
{
unsigned int xaxis,yaxis;

xaxis=analogRead(A0);
yaxis=analogRead(A1);

if(xaxis<351&&xaxis>300&&yaxis<351&&yaxis>300)
{
digitalWrite(m1_1,HIGH);
digitalWrite(m1_2,HIGH);
digitalWrite(m2_1,HIGH);
digitalWrite(m2_2,HIGH);

}
else if(xaxis>366&&yaxis<351&&yaxis>300)
{
digitalWrite(m1_1,HIGH);
digitalWrite(m1_2,LOW);
digitalWrite(m2_1,HIGH);
digitalWrite(m2_2,LOW);

}

else if(xaxis<290&&yaxis<351&&yaxis>300)
{
digitalWrite(m1_1,LOW);
digitalWrite(m1_2,HIGH);
digitalWrite(m2_1,LOW);
digitalWrite(m2_2,HIGH);

}

else if(yaxis>366&&xaxis<351&&xaxis>300)
{
digitalWrite(m1_1,HIGH);
digitalWrite(m1_2,LOW);
digitalWrite(m2_1,LOW);
digitalWrite(m2_2,HIGH);

}

else if(yaxis<290&&xaxis<351&&xaxis>300)
{
digitalWrite(m1_1,LOW);
digitalWrite(m1_2,HIGH);
digitalWrite(m2_1,HIGH);
digitalWrite(m2_2,LOW);

}

}