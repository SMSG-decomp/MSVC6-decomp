void coff_mark_referenced_globals(void)

{
  uint32_t id;
  c2_fe_symbol *pcVar1;
  
  id = prevobj_read_dword();
  while (id != 0) {
    pcVar1 = fe_scope_lookup_id(&g_global_scope,id);
    if (pcVar1 != (c2_fe_symbol *)0x0) {
      pcVar1->attrs = pcVar1->attrs | 0x10000;
    }
    id = prevobj_read_dword();
  }
  return;
}

