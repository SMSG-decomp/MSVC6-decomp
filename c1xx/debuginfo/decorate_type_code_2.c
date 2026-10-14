char * __cdecl decorate_type_code_2(char *out,c1_type *type)

{
  byte bVar1;
  byte *pbVar2;
  
  bVar1 = (byte)type->code;
  if ((bVar1 >> 6 & 1) != 0) {
    *out = 'X';
    return out + 1;
  }
  if ((-1 < (char)bVar1) && (type->flags != 0)) {
    pbVar2 = decorate_pointer_target(out,type,3);
    return (char *)pbVar2;
  }
  pbVar2 = decorate_pointer_target(out,type,0);
  return (char *)pbVar2;
}

