c2_fe_symbol * __fastcall
fe_symbol_new_local_cur(uint16_t cls,int a,int16_t kind,int arena,uint8_t f,uint32_t attrs)

{
  c2_fe_symbol *pcVar1;
  c2_scope_table *scope;
  
  scope = g_cur_scope;
  if (arena == 0) {
    scope = &g_global_scope;
  }
  pcVar1 = fe_symbol_new_local(scope,cls,a,kind,arena,f,attrs);
  return pcVar1;
}

