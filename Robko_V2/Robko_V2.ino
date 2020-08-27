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
      PORTB |= B00000100;
      while(1)
      {
        half_forward();
        
        data = Serial.read();
        if(data == 'S')
        {
          PORTD &= B00000011;
          PORTB &= B00000000;
          break;
        }
      }
    }
    
    if(data == '3')
    {
      PORTB |= B00010100;
      while(1)
      {
        ForearmContract();
        
        data = Serial.read();
        if(data == 'S')
        {
          PORTD &= B00000011;
          PORTB &= B00000000;
          break;
        }
      }
    }
    
    if(data == '4')
    {
      PORTB |= B00101100;
      while(1)
      {
        half_forward();
        
        data = Serial.read();
        if(data == 'S')
        {
          PORTD &= B00000011;
          PORTB &= B00000000;
          break;
        }
      }
    }
    
    if(data == '6')
    {
      PORTB |= B00001100;
      while(1)
      {
        half_forward();
        
        data = Serial.read();
        if(data == 'S')
        {
          PORTD &= B00000011;
          PORTB &= B00000000;
          break;
        }
      }
    }
    
    if(data == '7')
    {
      PORTB |= B00000100;
      while(1)
      {
        half_backward();
        
        data = Serial.read();
        if(data == 'S')
        {
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
        ForearmExpand();
        
        data = Serial.read();
        if(data == 'S')
        {
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
        half_backward();
        
        data = Serial.read();
        if(data == 'S')
        {
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
        half_backward();
        
        data = Serial.read();
        if(data == 'S')
        {
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
        WristClockwise();
        
        data = Serial.read();
        if(data == 'S')
        {
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
        WristCounterclockwise();
        
        data = Serial.read();
        if(data == 'S')
        {
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
        WristUp();
        
        data = Serial.read();
        if(data == 'S')
        {
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
        WristDown();
        
        data = Serial.read();
        if(data == 'S')
        {
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
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
}

void WristDown()
{
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
}

void WristClockwise()
{
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
}

void WristCounterclockwise()
{
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
  PORTB = (PORTB &~ B00111000) | B00011000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00100000;
}

void ForearmContract()
{
  PORTB = (PORTB &~ B00111000) | B00101000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00010000;
  PORTB = (PORTB &~ B00111000) | B00101000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00010000;
  PORTB = (PORTB &~ B00111000) | B00101000;
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00010000;
  PORTB = (PORTB &~ B00111000) | B00101000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00010000;
  PORTB = (PORTB &~ B00111000) | B00101000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00010000;
  PORTB = (PORTB &~ B00111000) | B00101000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00010000;
  PORTB = (PORTB &~ B00111000) | B00101000;
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00010000;
  PORTB = (PORTB &~ B00111000) | B00101000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00010000;  
}

void ForearmExpand()
{
  PORTB = (PORTB &~ B00111000) | B00101000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00010000;
  PORTB = (PORTB &~ B00111000) | B00101000;
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00010000;
  PORTB = (PORTB &~ B00111000) | B00101000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00010000;
  PORTB = (PORTB &~ B00111000) | B00101000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00010000;
  PORTB = (PORTB &~ B00111000) | B00101000;
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00010000;
  PORTB = (PORTB &~ B00111000) | B00101000;
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00010000;
  PORTB = (PORTB &~ B00111000) | B00101000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00010000;
  PORTB = (PORTB &~ B00111000) | B00101000;
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
  PORTB = (PORTB &~ B00111000) | B00010000;
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
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
}

void half_backward()
{
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000010;
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD) | B10000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD);
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB) | B00000001;
  delayMicroseconds(Speed);
  PORTD = (PORTD &~ maskD) | B01000000;
  PORTB = (PORTB &~ maskB);
  delayMicroseconds(Speed);
}
