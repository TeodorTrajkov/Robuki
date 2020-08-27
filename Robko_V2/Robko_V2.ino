#define A 13
#define B 12
#define C 11
#define En 10

#define D0 6
#define D1 7
#define D2 8
#define D3 9

#define Speed 3000 //Speed of the mottor in microseconds


int data; //Stores received data
int maskD = B11000000;
int maskB = B00000011;

unsigned long Curr = 0, Prev = 0;
int Step = 0;

void setup() {
  DDRD = B11100000;
  DDRB = B00111111;

  PORTD = B00000000;
  PORTB = B00000000;
  
  Serial.begin(9600);
}

void loop() 
{
  if(Serial.available() > 0)
  {
    data = Serial.read();

    if(data == '1')
    {
      Prev = micros();
      PORTB |= B00000100;
      while(1)
      {
        Curr = micros();
        if((Curr - Prev) > Speed)
        {
          half_forward();
          Step++;
          Prev = Curr;
        }
        
        data = Serial.read();
        if(data == 'S')
        {
          Step = 0;
          PORTD &= B00000011;
          PORTB &= B00000000;
          break;
        }
      }
    }
    
    if(data == '3')
    {
      Prev = micros();
      PORTB |= B00010100;
      while(1)
      {
        Curr = micros();
        if((Curr - Prev) > Speed)
        {
          ForearmContract();
          Step++;
          Prev = Curr;
        }
        
        data = Serial.read();
        if(data == 'S')
        {
          Step = 0;
          PORTD &= B00000011;
          PORTB &= B00000000;
          break;
        }
      }
    }
    
    if(data == '4')
    {
      Prev = micros();
      PORTB |= B00101100;
      while(1)
      {
        Curr = micros();
        if((Curr - Prev) > Speed)
        {
          half_forward();
          Step++;
          Prev = Curr;
        }
        
        data = Serial.read();
        if(data == 'S')
        {
          Step = 0;
          PORTD &= B00000011;
          PORTB &= B00000000;
          break;
        }
      }
    }
    
    if(data == '6')
    {
      Prev = micros();
      PORTB |= B00001100;
      while(1)
      {
        Curr = micros();
        if((Curr - Prev) > Speed)
        {
          half_forward();
          Step++;
          Prev = Curr;
        }
        
        data = Serial.read();
        if(data == 'S')
        {
          Step = 0;
          PORTD &= B00000011;
          PORTB &= B00000000;
          break;
        }
      }
    }
    
    if(data == '7')
    {
      Prev = micros();
      PORTB |= B00000100;
      while(1)
      {
        Curr = micros();
        if((Curr - Prev) > Speed)
        {
          half_backward();
          Step++;
          Prev = Curr;
        }
        
        data = Serial.read();
        if(data == 'S')
        {
          Step = 0;
          PORTD &= B00000011;
          PORTB &= B00000000;
          break;
        }
      }
    }
    
    if(data == '9')
    {
      PORTB |= B00010100;
      while(1)
      {
        Curr = micros();
        if((Curr - Prev) > Speed)
        {
          ForearmExpand();
          Step++;
          Prev = Curr;
        }
        
        data = Serial.read();
        if(data == 'S')
        {
          Step = 0;
          PORTD &= B00000011;
          PORTB &= B00000000;
          break;
        }
      }
    }
    
    if(data == 'a')
    {
      PORTB |= B00101100;
      while(1)
      {
        Curr = micros();
        if((Curr - Prev) > Speed)
        {
          half_backward();
          Step++;
          Prev = Curr;
        }
        
        data = Serial.read();
        if(data == 'S')
        {
          Step = 0;
          PORTD &= B00000011;
          PORTB &= B00000000;
          break;
        }
      }
    }
    
    if(data == 'c')
    {
      PORTB |= B00001100;
      while(1)
      {
        Curr = micros();
        if((Curr - Prev) > Speed)
        {
          half_backward();
          Step++;
          Prev = Curr;
        }
        
        data = Serial.read();
        if(data == 'S')
        {
          Step = 0;
          PORTD &= B00000011;
          PORTB &= B00000000;
          break;
        }
      }
    }
    
    if(data == '8')
    {
      PORTB = B00000100;
      while(1)
      {
        Curr = micros();
        if((Curr - Prev) > Speed)
        {
          WristClockwise();
          Step++;
          Prev = Curr;
        }
        
        data = Serial.read();
        if(data == 'S')
        {
          Step = 0;
          PORTD &= B00000011;
          PORTB &= B00000000;
          break;
        }
      }
    }
    if(data == '2')
    {
      PORTB = B00000100;
      while(1)
      {
        Curr = micros();
        if((Curr - Prev) > Speed)
        {
          WristCounterclockwise();
          Step++;
          Prev = Curr;
        }
        
        data = Serial.read();
        if(data == 'S')
        {
          Step = 0;
          PORTD &= B00000011;
          PORTB &= B00000000;
          break;
        }
      }
    }
    if(data == '5')
    {
      PORTB = B00000100;
      while(1)
      {
        Curr = micros();
        if((Curr - Prev) > Speed)
        {
          WristUp();
          Step++;
          Prev = Curr;
        }
        
        data = Serial.read();
        if(data == 'S')
        {
          Step = 0;
          PORTD &= B00000011;
          PORTB &= B00000000;
          break;
        }
      }
    }
    if(data == 'b')
    {
      PORTB = B00000100;
      while(1)
      {
        Curr = micros();
        if((Curr - Prev) > Speed)
        {
          WristDown();
          Step++;
          Prev = Curr;
        }
        
        data = Serial.read();
        if(data == 'S')
        {
          Step = 0;
          PORTD &= B00000011;
          PORTB &= B00000000;
          break;
        }
      }
    }
  }
}

void WristUp()
{
  if(Step > 15) Step = 0;
  if(Step == 0)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB);
  }
  if(Step == 1)
  {
    PORTB = (PORTB &~ B00111000) | B00100000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000010;
  }
  if(Step == 2)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000001;
  }
  if(Step == 3)
  {
    PORTB = (PORTB &~ B00111000) | B00100000;
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000010;
  }
  if(Step == 4)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000001;
  }
  if(Step == 5)
  {
    PORTB = (PORTB &~ B00111000) | B00100000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000010;
  }
  if(Step == 6)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000001;
  }
  if(Step == 7)
  {
    PORTB = (PORTB &~ B00111000) | B00100000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB);
  }
  if(Step == 8)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB);
  }
  if(Step == 9)
  {
    PORTB = (PORTB &~ B00111000) | B00100000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000001;
  }
  if(Step == 10)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000010;
  }
  if(Step == 11)
  {
    PORTB = (PORTB &~ B00111000) | B00100000;
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000001;
  }
  if(Step == 12)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000010;
  }
  if(Step == 13)
  {
    PORTB = (PORTB &~ B00111000) | B00100000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000001;
  }
  if(Step == 14)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000010;
  }
  if(Step == 15)
  {
    PORTB = (PORTB &~ B00111000) | B00100000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB);
  }
}

void WristDown()
{
  if(Step > 15) Step = 0;
  if(Step == 0)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000010;
  }
  if(Step == 1)
  {
    PORTB = (PORTB &~ B00111000) | B00100000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB);
  }
  if(Step == 2)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000010;
  }
  if(Step == 3)
  {
    PORTB = (PORTB &~ B00111000) | B00100000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000001;
  }
  if(Step == 4)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000010;
  }
  if(Step == 5)
  {
    PORTB = (PORTB &~ B00111000) | B00100000;
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000001;
  }
  if(Step == 6)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB);
  }
  if(Step == 7)
  {
    PORTB = (PORTB &~ B00111000) | B00100000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000001;
  }
  if(Step == 8)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000001;
  }
  if(Step == 9)
  {
    PORTB = (PORTB &~ B00111000) | B00100000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB);
  }
  if(Step == 10)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000001;
  }
  if(Step == 11)
  {
    PORTB = (PORTB &~ B00111000) | B00100000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000010;
  }
  if(Step == 12)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000001;
  }
  if(Step == 13)
  {
    PORTB = (PORTB &~ B00111000) | B00100000;
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000010;
  }
  if(Step == 14)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB);
  }
  if(Step == 15)
  {
    PORTB = (PORTB &~ B00111000) | B00100000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000010;
  }
}

void WristClockwise()
{
  if(Step > 7) Step = 0;
  if(Step == 0)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000010;
    PORTB = (PORTB &~ B00111000) | B00100000;
  }
  if(Step == 1)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000010;
    PORTB = (PORTB &~ B00111000) | B00100000;
  }
  if(Step == 2)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000010;
    PORTB = (PORTB &~ B00111000) | B00100000;
  }
  if(Step == 3)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB);
    PORTB = (PORTB &~ B00111000) | B00100000;
  }
  if(Step == 4)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000001;
    PORTB = (PORTB &~ B00111000) | B00100000;
  }
  if(Step == 5)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000001;
    PORTB = (PORTB &~ B00111000) | B00100000;
  }
  if(Step == 6)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000001;
    PORTB = (PORTB &~ B00111000) | B00100000;
  }
  if(Step == 7)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB);
    PORTB = (PORTB &~ B00111000) | B00100000;
  }
}

void WristCounterclockwise()
{
  if(Step > 7) Step = 0;
  if(Step == 0)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB);
    PORTB = (PORTB &~ B00111000) | B00100000;
  }
  if(Step == 1)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000001;
    PORTB = (PORTB &~ B00111000) | B00100000;
  }
  if(Step == 2)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000001;
    PORTB = (PORTB &~ B00111000) | B00100000;
  }
  if(Step == 3)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000001;
    PORTB = (PORTB &~ B00111000) | B00100000;
  }
  if(Step == 4)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB);
    PORTB = (PORTB &~ B00111000) | B00100000;
  }
  if(Step == 5)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000010;
    PORTB = (PORTB &~ B00111000) | B00100000;
  }
  if(Step == 6)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000010;
    PORTB = (PORTB &~ B00111000) | B00100000;
  }
  if(Step == 7)
  {
    PORTB = (PORTB &~ B00111000) | B00011000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000010;
    PORTB = (PORTB &~ B00111000) | B00100000;
  }
}

void ForearmContract()
{
  if(Step > 7) Step = 0;
  if(Step == 0)
  {
    PORTB = (PORTB &~ B00111000) | B00101000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB);
    PORTB = (PORTB &~ B00111000) | B00010000;
  }
  if(Step == 1)
  {
    PORTB = (PORTB &~ B00111000) | B00101000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000001;
    PORTB = (PORTB &~ B00111000) | B00010000;
  }
  if(Step == 2)
  {
    PORTB = (PORTB &~ B00111000) | B00101000;
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000001;
    PORTB = (PORTB &~ B00111000) | B00010000;
  }
  if(Step == 3)
  {
    PORTB = (PORTB &~ B00111000) | B00101000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000001;
    PORTB = (PORTB &~ B00111000) | B00010000;
  }
  if(Step == 4)
  {
    PORTB = (PORTB &~ B00111000) | B00101000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB);
    PORTB = (PORTB &~ B00111000) | B00010000;
  }
  if(Step == 5)
  {
    PORTB = (PORTB &~ B00111000) | B00101000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000010;
    PORTB = (PORTB &~ B00111000) | B00010000;
  }
  if(Step == 6)
  {
    PORTB = (PORTB &~ B00111000) | B00101000;
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000010;
    PORTB = (PORTB &~ B00111000) | B00010000;
  }
  if(Step == 7)
  {
    PORTB = (PORTB &~ B00111000) | B00101000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000010;
    PORTB = (PORTB &~ B00111000) | B00010000;  
  }
}

void ForearmExpand()
{
  if(Step > 7) Step = 0;
  if(Step == 0)
  {
    PORTB = (PORTB &~ B00111000) | B00101000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000010;
    PORTB = (PORTB &~ B00111000) | B00010000;
  }
  if(Step == 1)
  {
    PORTB = (PORTB &~ B00111000) | B00101000;
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000010;
    PORTB = (PORTB &~ B00111000) | B00010000;
  }
  if(Step == 2)
  {
    PORTB = (PORTB &~ B00111000) | B00101000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000010;
    PORTB = (PORTB &~ B00111000) | B00010000;
  }
  if(Step == 3)
  {
    PORTB = (PORTB &~ B00111000) | B00101000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB);
    PORTB = (PORTB &~ B00111000) | B00010000;
  }
  if(Step == 4)
  {
    PORTB = (PORTB &~ B00111000) | B00101000;
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000001;
    PORTB = (PORTB &~ B00111000) | B00010000;
  }
  if(Step == 5)
  {
    PORTB = (PORTB &~ B00111000) | B00101000;
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000001;
    PORTB = (PORTB &~ B00111000) | B00010000;
  }
  if(Step == 6)
  {
    PORTB = (PORTB &~ B00111000) | B00101000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000001;
    PORTB = (PORTB &~ B00111000) | B00010000;
  }
  if(Step == 7)
  {
    PORTB = (PORTB &~ B00111000) | B00101000;
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB);
    PORTB = (PORTB &~ B00111000) | B00010000;
  }
}

void forward()
{
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
}

void backward()
{
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
}

void half_forward()
{
  if(Step > 7) Step = 0;
  if(Step == 0)
  {
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB);
  }
  if(Step == 1)
  {
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000001;
  }
  if(Step == 2)
  {
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000001;
  }
  if(Step == 3)
  {
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000001;
  }
  if(Step == 4)
  {
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB);
  }
  if(Step == 5)
  {
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000010;
  }
  if(Step == 6)
  {
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000010;
  }
  if(Step == 7)
  {
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000010;
  }
}

void half_backward()
{
  if(Step > 7) Step = 0;
  if(Step == 0)
  {
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000010;
  }
  if(Step == 1)
  {
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000010;
  }
  if(Step == 2)
  {
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000010;
  }
  if(Step == 3)
  {
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB);
  }
  if(Step == 4)
  {
    PORTD = (PORTD &~ maskD) | B10000000;
    PORTB = (PORTB &~ maskB) | B00000001;
  }
  if(Step == 5)
  {
    PORTD = (PORTD &~ maskD);
    PORTB = (PORTB &~ maskB) | B00000001;
  }
  if(Step == 6)
  {
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB) | B00000001;
  }
  if(Step == 7)
  {
    PORTD = (PORTD &~ maskD) | B01000000;
    PORTB = (PORTB &~ maskB);
  }
}
