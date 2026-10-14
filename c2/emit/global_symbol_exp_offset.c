uint32_t __fastcall global_symbol_exp_offset(uint32_t id)

{
  c2_fe_symbol *pcVar1;
  
  pcVar1 = fe_scope_lookup_id(&g_global_scope,id);
  return (pcVar1->u4a).function.exp_offset;
}

