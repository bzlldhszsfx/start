#define _dottime 250

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void dot()
{
	digitalWrite(13,HIGH);
	delay(_dottime);
	digitalWrite(13,LOW);
	delay(_dottime);
}
void dash()
{
	digitalWrite(13,HIGH);
	delay(_dottime*4);
	digitalWrite(13,LOW);
	delay(_dottime);
}
 void c_space()
{
	digitalWrite(13,LOW);
	delay(_dottime*2);
} 
 
void translate(char m)
{
  switch(m){
  case 'a' : {dot(); dash();}
  case 'b' : {dash();dot();dot();dot();}
  case 'c' : {dash();dot();dash();dot(); }
  case 'd' : {dash();dot();dot();}
  case 'e' : {dot();}
  case 'f' : {dot(); dot();dash();dot();}
  case 'g' : {dash();dash();dot(); }
  case 'h' : {dot(); dot();dot();dot();}
  case 'i' : {dot(); dot();}
  case 'j' : {dot(); dash(); dash(); dash();}
  case 'k' : {dash(); dash();dash();}
  case 'l' : {dot(); dash();dot(); dot(); }
  case 'm' : {dash(); dash();}
  case 'n' : {dash();dot(); }
  case 'o' : {dash(); dash();dash();}
  case 'p' : {dot(); dash();dash();dot();}
  case 'q' : {dash(); dash();dot(); dash();}
  case 'r' : {dot(); dash();dot();}
  case 's' : {dot(); dot();dot();}
  case 't' : {dash();}
  case 'u' : {dot(); dot();dash();}
  case 'v' : {dot(); dot();dot();dash();}
  case 'w' : {dot(); dash(); dash(); }
  case 'x' : {dash();dot();dot();dash();}
  case 'y' : {dash();dot(); dash();dash();}
  case 'z' : {dash(); dash();dot();dot();}
  }
}
void loop()
{
  String str="";
  int i, t , flag = 0;
  int n = 0;  //传入字符个数
  while (Serial.available() > 0)
  {
    flag = 1; 
    str[n]=char(Serial.read());
    delay(2); 
    n++;
  }

  if (flag)
  {
    for (i = 0; i < n; i++)
    {
      if(str[i]==' ')
      {
        c_space();c_space();c_space();
      }
      else {translate(str[i]);c_space();}
      
    }
    delay(2);
  }
}
    
  
