c1_node * __cdecl expr_string_literal(c1_node *node)

{
  byte pooled;
  char in_inline_function;
  int iVar1;
  char *s;
  c1_lookup_result *result;
  c1_symbol *sym;
  c1_node *pcVar2;
  c1_lookup_entry *pcVar3;
  void *name;
  
  name = (void *)0x0;
  iVar1 = expr_string_pooling_enabled();
  pooled = (byte)iVar1;
  if ((g_il_block_level == '\0') || (g_current_function == (c1_symbol *)0x0)) {
LAB_10440d99:
    in_inline_function = '\0';
  }
  else {
    iVar1 = func_wants_inline(g_current_function);
    if ((char)iVar1 == '\0') goto LAB_10440d99;
    in_inline_function = '\x01';
  }
  g_function_string_literal_count = g_function_string_literal_count + 1;
  if (pooled == 0) {
    if ((g_c9il_mode != '\0') || (in_inline_function == '\0')) goto LAB_10440df6;
    s = decorate_function_string_literal();
  }
  else {
    s = decorate_string_literal_name((int *)&node->left,*(byte *)((int)&node->right + 2) & 1);
  }
  if (s == (char *)0x0) goto LAB_10440df6;
  name = name_intern(s);
  if (pooled == 0) goto LAB_10440df6;
  result = (*g_current_scope->global_scope->vtbl->lookup)(g_current_scope->global_scope,name,1);
  if (result == (c1_lookup_result *)0x0) {
LAB_10440df0:
    sym = (c1_symbol *)0x0;
  }
  else {
    pcVar3 = lookup_check_ambiguous_symbol(result,'\x01');
    if (pcVar3 == (c1_lookup_entry *)0x0) goto LAB_10440df0;
    sym = pcVar3->sym;
  }
  if (sym != (c1_symbol *)0x0) {
    pcVar2 = tree_new_symbol_ref(sym,'\0');
    return pcVar2;
  }
LAB_10440df6:
  pcVar2 = func_new_compiler_generated(node,name,pooled,in_inline_function);
  return pcVar2;
}

