bool __cdecl type_is_function(byte *type_code)

{
  return (*type_code & 0x8f) == 0x86;
}

