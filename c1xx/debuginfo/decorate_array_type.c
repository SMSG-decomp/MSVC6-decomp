char * __cdecl decorate_array_type(char *out,c1_type *type)

{
  byte *pbVar1;
  char *pcVar2;
  
  if ((type->code & 0x8f) != 0x83) {
    pbVar1 = decorate_pointer_code((byte *)out,type);
    return (char *)pbVar1;
  }
  *out = 'Y';
  pcVar2 = decorate_array_dims(out + 1,type);
  return pcVar2;
}

