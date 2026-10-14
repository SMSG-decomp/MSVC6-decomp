c2_fe_symbol * __fastcall alloc_null_fe_symbol(void)

{
  uint32_t size;
  c2_fe_symbol *pcVar1;
  
  size = fe_symbol_size(1);
  g_fe_symbol_bytes[0] = g_fe_symbol_bytes[0] + size;
  pcVar1 = arena_alloc(0,size);
  pcVar1->cls = '\x01';
  return pcVar1;
}

