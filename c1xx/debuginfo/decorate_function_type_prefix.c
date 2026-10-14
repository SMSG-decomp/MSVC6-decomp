char * __cdecl decorate_function_type_prefix(char *out,c1_type *type)

{
  ushort uVar1;
  byte *pbVar2;
  c1_type *pcVar3;
  char *pcVar4;
  byte bVar5;
  
  switch(type->code & 0x8f) {
  case 0x81:
  case 0x84:
  case 0x85:
  case 0x86:
  case 0x8e:
    break;
  default:
    pcVar4 = decorate_function_type_prefix_none(out);
    return pcVar4;
  }
  uVar1 = type->code & 0x8f;
  bVar5 = (byte)type->flags >> 1 & 4;
  if ((uVar1 == 0x8e) || (uVar1 == 0x85)) {
    bVar5 = bVar5 | 2;
  }
  if (bVar5 < 4) {
    *out = bVar5 + 0x36;
  }
  else {
    *out = '_';
    out = out + 1;
    *out = bVar5 + 0x41;
  }
  pbVar2 = (byte *)(out + 1);
  uVar1 = type->code & 0x8f;
  if (uVar1 == 0x8e) {
    pcVar4 = decorate_scope_chain((char *)pbVar2,&((type->extra).cls)->kind);
    *pcVar4 = '@';
    pcVar3 = type_get_base(type);
    pbVar2 = (byte *)decorate_type_into(pcVar4 + 1,
                                        (c1_type *)
                                        **(undefined4 **)
                                          (((uint)pcVar3 & -(uint)((pcVar3->code & 0x80) != 0)) + 8)
                                        ,1);
  }
  else if (uVar1 == 0x85) {
    pcVar4 = decorate_scope_chain
                       ((char *)pbVar2,&((((type->extra).params)->this_type->extra).cls)->kind);
    *pcVar4 = '@';
    pbVar2 = (byte *)decorate_type_into(pcVar4 + 1,
                                        (c1_type *)
                                        **(undefined4 **)
                                          ((-(uint)((type->code & 0x80) != 0) & (uint)type) + 8),1);
  }
  if ((bVar5 & 4) == 0) {
    return (char *)pbVar2;
  }
  pbVar2 = decorate_type_text(pbVar2,type);
  return (char *)pbVar2;
}

