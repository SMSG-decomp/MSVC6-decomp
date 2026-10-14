int __fastcall coff_symbol_is_not_dllimport_var(uint32_t id)

{
  c2_fe_symbol *pcVar1;
  
  pcVar1 = fe_scope_lookup_id(&g_global_scope,id);
  if (((pcVar1 != (c2_fe_symbol *)0x0) && (pcVar1->cls == '\x04')) &&
     ((pcVar1->storage & 0x8000) != 0)) {
    return 0;
  }
  return 1;
}

