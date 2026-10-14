void __cdecl ns_end_definition(int ns_type)

{
  ushort *puVar1;
  
  scope_pop_child(g_current_scope);
  if (((*(byte *)(ns_type + 3) & 4) == 0) && ((*(byte *)(*(int *)(ns_type + 0x14) + 6) & 1) != 0)) {
    ns_using_directive((c1_symbol *)ns_type,(fe_name *)0x0,0,'\x01');
  }
  puVar1 = (ushort *)(*(int *)(ns_type + 0x14) + 6);
  *puVar1 = *puVar1 & 0xfffd;
  return;
}

