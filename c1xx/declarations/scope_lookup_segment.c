byte * __thiscall scope_lookup_segment(void *stack,void *name)

{
  char cVar1;
  c1_symbol *pcVar2;
  uint uVar3;
  char *pcVar4;
  
  uVar3 = 0xffffffff;
  pcVar4 = *(char **)((int)name + 4);
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (0x7f < ~uVar3 - 1) {
    (*(char **)((int)name + 4))[0x7f] = '\0';
  }
  if (((*(c1_sym_link **)((int)stack + 0x228) != (c1_sym_link *)0x0) && (name != (void *)0x0)) &&
     (name != g_name_unnamed)) {
    pcVar2 = scope_lookup_skip_type_aliases(*(c1_sym_link **)((int)stack + 0x228),name);
    return &pcVar2->kind;
  }
  return (byte *)0x0;
}

