task main()
{
  int i;
  int j;
  int ArrayX[50][100];
  int f = sizeof(ArrayX);
  memset(ArrayX, 0, sizeof(ArrayX));
/*
  for (i = 0; i < 50; ++i)
  {
    for (j = 0; j < 100; ++j)
    {
      if (ArrayX[i][j] != 0)
        writeDebugStreamLine("Value 'ArrayX[%d][%d] is %d. NOT ZERO AS EXPECTED!!", i, j, ArrayX[i][j]);
    }
  }
  writeDebugStreamLine("A big string literal");
  writeDebugStreamLine("%d", f);*/
}
