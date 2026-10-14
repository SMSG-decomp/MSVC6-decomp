void __cdecl init_check_dllimport_address(c1_symbol *sym,c1_node *node)

{
  byte bVar1;
  int iVar2;
  byte *local_8;
  int local_4;
  
  local_8 = (byte *)0x0;
  local_4 = 0;
  bVar1 = node->kind & 7;
  if (((((bVar1 != 5) && (bVar1 != 3)) &&
       (iVar2 = init_split_address_constant(node,&local_8,&local_4), iVar2 != 0)) &&
      ((local_8 != (byte *)0x0 && (((*local_8 & 0x1f) == 7 || ((*local_8 & 0x1f) == 8)))))) &&
     ((local_8[0x22] & 8) != 0)) {
    if (g_ms_extensions != '\0') {
      diag_warning(4,0xe8,sym);
      return;
    }
    diag_error(0x142,sym,local_8);
  }
  return;
}

