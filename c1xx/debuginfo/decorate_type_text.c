byte * __cdecl decorate_type_text(byte *out,c1_type *type)

{
  byte *pbVar1;
  byte flags;
  
  if ((type->code & 0x83) == 0x81) {
    type = type->base;
  }
  if ((type->code & 0x8f) != 0x83) {
    flags = (byte)type->flags;
    if ((flags & 0x18) != 0x18) {
      pbVar1 = decorate_based_code(out,flags,(c1_symbol *)0x0);
      return pbVar1;
    }
    pbVar1 = decorate_based_code(out,flags,(type->extra).cls);
    return pbVar1;
  }
  *out = 0x39;
  return out + 1;
}

