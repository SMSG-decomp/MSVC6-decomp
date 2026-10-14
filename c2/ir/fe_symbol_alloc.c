c2_fe_symbol * __fastcall fe_symbol_alloc(char cls,int arena)

{
  uint32_t size;
  c2_fe_symbol *pcVar1;
  
  size = fe_symbol_size((int)cls);
  g_fe_symbol_bytes[arena] = g_fe_symbol_bytes[arena] + size;
  pcVar1 = arena_alloc(arena,size);
  pcVar1->cls = cls;
  return pcVar1;
}

