int __cdecl sym_element_size(c1_symbol *sym)

{
  ushort uVar1;
  c1_type *pcVar2;
  c1_tag_symbol *pcVar3;
  char cVar4;
  ushort uVar5;
  
  pcVar2 = sym->type;
  uVar1 = pcVar2->code;
  cVar4 = (char)uVar1;
  while (((cVar4 < '\0' && ((uVar1 & 0x8f) != 0x86)) && ((uVar1 & 0x8f) != 0x82))) {
    pcVar2 = pcVar2->base;
    uVar1 = pcVar2->code;
    cVar4 = (char)uVar1;
  }
  if ((char)pcVar2->code < '\0') {
    return 4;
  }
  uVar1 = pcVar2->code;
  if ((uVar1 & 0x530) != 0) {
    return (int)(char)(&g_type_rank_table)[uVar1 & 0xf];
  }
  uVar5 = uVar1 & 0x8f;
  if (((uVar5 != 0x83) && (uVar5 != 0x82)) &&
     ((uVar5 != 0x86 && ((-1 < (char)uVar1 || (uVar5 != 0x80)))))) {
    if ((uVar1 & 0x200) == 0) {
      return 0;
    }
    pcVar3 = (pcVar2->extra).tag;
    if ((pcVar3->kind & 0x1f) != 4) {
      if ((pcVar3->type->code & 0x200) == 0) {
        return iRam00000028;
      }
      return ((pcVar3->type->extra).tag)->size;
    }
    return pcVar3->size;
  }
  return 4;
}

