int __fastcall type_size_scalar(c1_type *type)

{
  ushort uVar1;
  c1_tag_symbol *pcVar2;
  ushort uVar3;
  
  uVar1 = type->code;
  if ((uVar1 & 0x530) != 0) {
    return (int)(char)(&g_type_rank_table)[uVar1 & 0xf];
  }
  uVar3 = uVar1 & 0x8f;
  if ((((uVar3 == 0x83) || (uVar3 == 0x82)) || (uVar3 == 0x86)) ||
     (((char)uVar1 < '\0' && (uVar3 == 0x80)))) {
    return 4;
  }
  if ((uVar1 & 0x200) == 0) {
    return 0;
  }
  pcVar2 = (type->extra).tag;
  if ((pcVar2->kind & 0x1f) == 4) {
    return pcVar2->size;
  }
  if ((pcVar2->type->code & 0x200) != 0) {
    return ((pcVar2->type->extra).tag)->size;
  }
  return iRam00000028;
}

