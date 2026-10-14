void __cdecl c1_raise_exit(ULONG_PTR code)

{
  RaiseException(0xe0005031,0xc0000025,1,&code);
  return;
}

