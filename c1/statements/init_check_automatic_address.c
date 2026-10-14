void __cdecl init_check_automatic_address(c1_symbol *sym,c1_node *init)

{
  int iVar1;
  void *local_8;
  int local_4;
  
  local_8 = (void *)0x0;
  local_4 = 0;
  iVar1 = init_split_address_constant(init,&local_8,&local_4);
  if (((iVar1 != 0) && (local_8 != (void *)0x0)) && ((*(byte *)((int)local_8 + 0x20) & 7) == 4)) {
    if (g_ms_extensions != '\0') {
      diag_warning(4,0xdd,sym);
      return;
    }
    diag_error(0x5d,sym,local_8);
  }
  return;
}

