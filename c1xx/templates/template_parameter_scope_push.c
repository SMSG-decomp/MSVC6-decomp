void __thiscall template_parameter_scope_push(c1_scope_stack *stack,c1_sym_list *params)

{
  c1xx_scope *pcVar1;
  int iVar2;
  c1_arena *a;
  c1xx_scope *scope;
  
  iVar2 = 4 - (uint)((g_compile_flags_cc & 0x100000) != 0);
  a = g_arenas + iVar2;
  scope = (c1xx_scope *)a->cur;
  pcVar1 = (c1xx_scope *)g_arenas[iVar2].end;
  a->cur = (c1_u8 *)(scope + 1);
  if (pcVar1 < scope + 1) {
    arena_grow(a);
  }
  if (scope == (c1xx_scope *)0x0) {
    scope = (c1xx_scope *)0x0;
  }
  else {
    scope->outer = (c1xx_scope *)0x0;
    scope->kind = 0xfa;
    scope->parent = (c1xx_scope *)0x0;
    scope->usings = (c1_using_directive *)0x0;
    (scope->body).symbols = params;
    scope->vtbl = (c1xx_scope_vtbl *)&PTR_block_scope_has_entries_104ca1a4;
  }
  if (params != (c1_sym_list *)0x0) {
    g_function_parameter_scope = params;
  }
  scope_push_child(stack,scope);
  return;
}

