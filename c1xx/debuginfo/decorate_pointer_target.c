byte * __cdecl decorate_pointer_target(char *out,c1_type *type,int mode)

{
  byte bVar1;
  byte *pbVar2;
  char *out_00;
  
  bVar1 = (byte)type->code;
  if ((((char)bVar1 < '\0') && ((bVar1 & 0x8f) == 0x80)) ||
     (((char)bVar1 < '\0' && ((bVar1 & 0x8f) == 0x84)))) {
    if ((type->flags & 0x40) != 0) {
      *out = 'B';
      pbVar2 = (byte *)decorate_type_full(out + 1,type);
      return pbVar2;
    }
    *out = 'A';
    pbVar2 = (byte *)decorate_type_full(out + 1,type);
    return pbVar2;
  }
  if ((bVar1 & 0x83) == 0x81) {
    *out = '$';
    out[1] = '$';
    out[2] = 'A';
    out_00 = decorate_function_type_prefix(out + 3,type);
    pbVar2 = (byte *)debug_type_name_text(out_00,type);
    return pbVar2;
  }
  if ((mode != 1) && (((bVar1 & 0x8f) == 0x83 || ((bVar1 >> 6 & 1) != 0)))) {
    *out = '$';
    out[1] = '$';
    out[2] = 'B';
    pbVar2 = (byte *)decorate_type_code(out + 3,type);
    return pbVar2;
  }
  if ((mode != 2) && (mode != 3)) {
    pbVar2 = decorate_pointer_code((byte *)out,type);
    return pbVar2;
  }
  *out = '$';
  out[1] = '$';
  out[2] = 'C';
  pbVar2 = (byte *)decorate_type_into(out + 3,type,0);
  pbVar2 = decorate_pointer_code(pbVar2,type);
  return pbVar2;
}

