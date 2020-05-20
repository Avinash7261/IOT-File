void setup() {
  for(int i=2;i<=10;i++)
  {pinMode(i,OUTPUT);
  }
  digitalWrite(10,LOW);
}
void display_no(int num)
{
  switch(num)
  {
    case 0:
    digitalWrite(2,1);
    digitalWrite(3,1);
    digitalWrite(4,1);
    digitalWrite(5,1);
    digitalWrite(6,1);
    digitalWrite(7,1);
    digitalWrite(8,0);
    digitalWrite(9,0);
    break;
    case 1:
    digitalWrite(2,0);
    digitalWrite(3,1);
    digitalWrite(4,1);
    digitalWrite(5,0);
    digitalWrite(6,0);
    digitalWrite(7,0);
    digitalWrite(8,0);
    digitalWrite(9,0);
    break;
    case 2:
    digitalWrite(2,1);
    digitalWrite(3,1);
    digitalWrite(4,0);
    digitalWrite(5,1);
    digitalWrite(6,1);
    digitalWrite(7,0);
    digitalWrite(8,1);
    digitalWrite(9,0);
    break;
    case 3:
    digitalWrite(2,1);
    digitalWrite(3,1);
    digitalWrite(4,1);
    digitalWrite(5,1);
    digitalWrite(6,0);
    digitalWrite(7,0);
    digitalWrite(8,1);
    digitalWrite(9,0);
    break;
    case 4:
    digitalWrite(2,0);
    digitalWrite(3,1);
    digitalWrite(4,1);
    digitalWrite(5,0);
    digitalWrite(6,0);
    digitalWrite(7,1);
    digitalWrite(8,1);
    digitalWrite(9,0);
    break;
    case 5:
    digitalWrite(2,1);
    digitalWrite(3,0);
    digitalWrite(4,1);
    digitalWrite(5,1);
    digitalWrite(6,0);
    digitalWrite(7,1);
    digitalWrite(8,1);
    digitalWrite(9,0);
    break;
    case 6:
    digitalWrite(2,1);
    digitalWrite(3,0);
    digitalWrite(4,1);
    digitalWrite(5,1);
    digitalWrite(6,1);
    digitalWrite(7,1);
    digitalWrite(8,1);
    digitalWrite(9,0);
    break;
    case 7:
    digitalWrite(2,1);
    digitalWrite(3,1);
    digitalWrite(4,1);
    digitalWrite(5,0);
    digitalWrite(6,0);
    digitalWrite(7,0);
    digitalWrite(8,0);
    digitalWrite(9,0);
    break;
    case 8:
    digitalWrite(2,1);
    digitalWrite(3,1);
    digitalWrite(4,1);
    digitalWrite(5,1);
    digitalWrite(6,1);
    digitalWrite(7,1);
    digitalWrite(8,1);
    digitalWrite(9,0);
    break;
    case 9:
    digitalWrite(2,1);
    digitalWrite(3,1);
    digitalWrite(4,1);
    digitalWrite(5,1);
    digitalWrite(6,0);
    digitalWrite(7,1);
    digitalWrite(8,1);
    digitalWrite(9,0);
    break;
    
    
  }
}

void loop() {
  int i;
  for(i=0;i<=9;i++)
  {
    display_no(i);
    delay(1000);
  }
  }
 


