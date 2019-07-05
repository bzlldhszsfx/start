#define _dottime 250

//定义莫尔斯电码表
char MORSE[][4] = {
  {'.', '-', '*', '*'}, //A
  {'-', '.', '.', '.'}, //B
  {'-', '.', '-', '.'}, //C
  {'-', '.', '.', '*'}, //D
  {'.', '*', '*', '*'}, //E
  {'.', '.', '-', '.'}, //F
  {'-', '-', '.', '*'}, //G
  {'.', '.', '.', '.'}, //H
  {'.', '.', '*', '*'}, //I
  {'.', '-', '-', '-'}, //J
  {'-', '.', '-', '*'}, //K
  {'.', '-', '.', '.'}, //L
  {'-', '-', '*', '*'}, //M
  {'-', '.', '*', '*'}, //N
  {'-', '-', '-', '*'}, //O
  {'.', '-', '-', '.'}, //P
  {'-', '-', '.', '-'}, //Q
  {'.', '-', '.', '*'}, //R
  {'.', '.', '.', '*'}, //S
  {'-', '*', '*', '*'}, //T
  {'.', '.', '-', '*'}, //U
  {'.', '.', '.', '-'}, //V
  {'.', '-', '-', '*'}, //W
  {'-', '.', '.', '-'}, //X
  {'-', '.', '-', '-'}, //Y
  {'-', '-', '.', '.'}  //Z
};

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
void loop()
{
  String str = "";  //转换前
  String morse_s = "";  //转换后
  int i, t , flag = 0;
  int n = 0;  //传入字符个数
  while (Serial.available() > 0)
  {
    flag = 1;  //判断是否有数据传入
    str += char(Serial.read());  //储存字符
    delay(2);  //读取一个字符1ms左右
    n++;
  }

  if (flag)
  {
    for (i = 0; i < n; i++)
    {
      for (t = 0; t < 4; t++)
      {
        if (str[i] >= 97 && str[i] <= 122)//判断读取小写
        {
          morse_s =  morse_s + char(MORSE[int(str[i] - 97)][t]);
        }
        else if (str[i]==' ')//空格保留
        {
           morse_s =  morse_s +  ' ';
        }
        else;
      }
      //每个输入的字母（或空格）之后补空格
      morse_s += ' ';
    }
    
    Serial.println(morse_s);
    for (i = 0; morse_s[i]!='\0' ; i++)
    {
      if (morse_s[i] == '.')  dot();
      else if (morse_s[i] == '-')  dash();
      else if (morse_s[i] == ' '&&morse_s[i+1] != ' ') c_space();
      else if (morse_s[i] == ' '&&morse_s[i+1] == ' ') 
      {
         c_space(); c_space(); 
      }
      else;
    }
    delay(2);
  }
}
