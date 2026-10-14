c2_scope_table * __fastcall scope_table_new(void)

{
  c2_scope_table *pcVar1;
  
  pcVar1 = arena_alloc(1,0x1004);
  pcVar1->parent = &g_global_scope;
  return pcVar1;
}

