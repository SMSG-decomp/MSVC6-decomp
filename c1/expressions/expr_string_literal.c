c1_node * __cdecl expr_string_literal(c1_node *literal)

{
  c1_u8 local;
  char named;
  int iVar1;
  char *s;
  c1_symbol **slot;
  c1_symbol *sym;
  c1_node *pcVar2;
  fe_name *name;
  
  name = (fe_name *)0x0;
  iVar1 = expr_string_pooling_enabled();
  local = (c1_u8)iVar1;
  if ((g_il_block_level == '\0') || (g_current_function == (c1_symbol *)0x0)) {
LAB_1061f79c:
    named = '\0';
  }
  else {
    iVar1 = func_wants_inline(g_current_function);
    if ((char)iVar1 == '\0') goto LAB_1061f79c;
    named = '\x01';
  }
  g_function_string_count = g_function_string_count + 1;
  if (local == '\0') {
    if ((g_c9il_mode != '\0') || (named == '\0')) goto LAB_1061f7f7;
    s = decorate_name_4();
  }
  else {
    s = expr_string_literal_lookup_name(&literal->left,*(byte *)((int)&literal->right + 2) & 1);
  }
  if (s != (char *)0x0) {
    name = name_intern(s);
    if (local != '\0') {
      slot = &(*g_current_scope->file_scope->vtbl->lookup)(g_current_scope->file_scope,(int)name)->
              sym;
      if (slot == (c1_symbol **)0x0) {
        sym = (c1_symbol *)0x0;
      }
      else {
        sym = *slot;
      }
      if (sym != (c1_symbol *)0x0) {
        pcVar2 = tree_new_symbol_ref(sym);
        return pcVar2;
      }
    }
  }
LAB_1061f7f7:
  pcVar2 = func_new_compiler_generated(literal,name,local,named);
  return pcVar2;
}

