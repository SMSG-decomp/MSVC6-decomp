int * __thiscall scope_lookup_segment(void *this,int name)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  char *pcVar4;
  
  uVar3 = 0xffffffff;
  pcVar4 = *(char **)(name + 4);
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (0x7f < ~uVar3 - 1) {
    (*(char **)(name + 4))[0x7f] = '\0';
  }
  if (((*(int **)((int)this + 0x210) != (int *)0x0) && (name != 0)) &&
     ((fe_name *)name != g_name_unnamed)) {
    piVar2 = sym_list_find_non_tag(*(int **)((int)this + 0x210),name);
    return piVar2;
  }
  return (int *)0x0;
}

