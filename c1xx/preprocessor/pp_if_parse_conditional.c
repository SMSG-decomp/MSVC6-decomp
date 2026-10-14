void * __cdecl pp_if_parse_conditional(void)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  
  pvVar1 = pp_if_parse_logical_or();
  iVar2 = pp_if_accept_token(0x56);
  if (iVar2 == 0) {
    return pvVar1;
  }
  pvVar3 = pp_if_parse_logical_or();
  iVar2 = pp_if_accept_token(0x36);
  if (iVar2 == 0) {
    diag_fatal_simple(0x11);
  }
  pvVar4 = pp_if_parse_logical_or();
  if (*(int *)((int)pvVar1 + 8) != 0 || *(int *)((int)pvVar1 + 0xc) != 0) {
    pvVar4 = pvVar3;
  }
  return pvVar4;
}

