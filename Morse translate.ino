#include <Morse.h>

Morse morse(13);

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
  Serial.begin(9600);
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
    delay(2);  //读取一个字符1ms左右，from百度
    n++;
  }

  if (flag)
  {
    for (i = 0; i < n; i++)
    {
      for (t = 0; t < 4; t++)
      {
        if (str[i] >= 97 && str[i] <= 122)//小写转换
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
    Serial.println(morse_s);  //串口传入
    for (i = 0; morse_s[i]!='\0' ; i++)//从头到尾读取莫尔斯电码
    {
      if (morse_s[i] == '.')morse.dot();
      else if (morse_s[i] == '-')morse.dash();
      else if (morse_s[i] == ' ')morse.w_space();
      if (morse_s[i] != ' ' && str[i] != '*')morse.c_space();
    }
    Serial.println("播放完毕");
    delay(2);
  }
}
