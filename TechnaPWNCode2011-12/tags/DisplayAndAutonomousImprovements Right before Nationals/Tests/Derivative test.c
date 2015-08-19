
float DPS;
int derivitive()
{
  float time;
  int encoder;
  ClearTimer(T1)
  do
  {
   // do nothing
  }while(encoder<=1);
  time = time1[T1];
  DPS = 1/time;
  return DPS;
}


task main()
{
  do
  {
    derivitive;
    displayNextLCDNumber(DPS);
  }while(1<2)
}
