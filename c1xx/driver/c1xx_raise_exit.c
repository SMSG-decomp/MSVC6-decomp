void __cdecl c1xx_raise_exit(uint code)

{
  RaiseException(0xe0005031,0xc0000025,1,&code);
  return;
}

