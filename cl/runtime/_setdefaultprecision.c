void __cdecl _setdefaultprecision(void)

{
  _controlfp(0x10000,0x30000);
  return;
}

