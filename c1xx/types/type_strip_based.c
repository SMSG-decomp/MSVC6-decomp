c1_type * __fastcall type_strip_based(c1_type *type)

{
  c1_type *pcVar1;
  char cVar2;
  ushort uVar3;
  c1_type local_10;
  
  uVar3 = type->flags & 0x18;
  if ((uVar3 == 0x18) || (uVar3 == 8)) {
    local_10.code = type->code;
    cVar2 = (char)local_10.code;
    pcVar1 = type;
    while (cVar2 < '\0') {
      pcVar1 = pcVar1->base;
      cVar2 = (char)pcVar1->code;
    }
    local_10.base = type->base;
    local_10.flags = pcVar1->flags & 0xffe7;
    local_10.debug_index = 0;
    local_10.extra.cls = (c1_symbol *)0x0;
    type = type_intern(&local_10);
  }
  return type;
}

