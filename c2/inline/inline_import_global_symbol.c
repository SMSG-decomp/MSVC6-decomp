void __fastcall inline_import_global_symbol(c2_fe_symbol *s)

{
  char *pcVar1;
  c2_fe_symbol *s_00;
  uint32_t uVar2;
  c2_fe_symbol_redirect *pcVar3;
  
  s_00 = fe_symbol_copy(s,0);
  uVar2 = fe_symbol_next_id();
  s_00->id = uVar2;
  scope_hash_insert(&g_global_scope,s_00);
  pcVar1 = s->name;
  s_00->storage = s_00->storage & 0xffffefff;
  s_00->name = pcVar1 + 6;
  pcVar3 = arena_alloc(0,0xc);
  pcVar3->original = s;
  pcVar3->copy = s_00;
  pcVar3->next = g_fe_symbol_redirect_map;
  g_fe_symbol_redirect_map = pcVar3;
  return;
}

