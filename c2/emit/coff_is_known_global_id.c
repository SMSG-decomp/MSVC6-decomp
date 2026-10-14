int __fastcall coff_is_known_global_id(uint32_t id)

{
  c2_fe_symbol *pcVar1;
  
  if ((0x3effff < id) && (id < 0x400000)) {
    return 0;
  }
  if (id < g_frontend_id_limit) {
    return 1;
  }
  pcVar1 = fe_scope_lookup_id(&g_global_scope,id);
  return (uint)(pcVar1 != (c2_fe_symbol *)0x0);
}

