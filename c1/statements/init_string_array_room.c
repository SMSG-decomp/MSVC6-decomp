int __cdecl init_string_array_room(c1_symbol *sym,uint str)

{
  c1_u16 *pcVar1;
  c1_type *pcVar2;
  int iVar3;
  uint uVar4;
  
  if (-1 < g_init_brace_depth) {
    return 0;
  }
  pcVar2 = sym->type;
  pcVar1 = (c1_u16 *)(-(uint)((pcVar2->code & 0x80) != 0) & (uint)pcVar2);
  if (*(int *)(pcVar1 + 4) == 0) {
    uVar4 = 2;
    if ((*(byte *)(str + 0x16) & 1) == 0) {
      uVar4 = 1;
    }
    str = *(ushort *)(str + 0x14) / uVar4;
    pcVar2 = type_intern_from_parts(pcVar2,*pcVar1,pcVar1[1],&str);
    sym->type = pcVar2;
    return 0;
  }
  iVar3 = 2;
  if ((*(byte *)(str + 0x16) & 1) == 0) {
    iVar3 = 1;
  }
  return *(int *)(pcVar1 + 4) * iVar3 - (uint)*(ushort *)(str + 0x14);
}

