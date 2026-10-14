c1_node * __cdecl expr_this_pointer(c1_symbol *sym)

{
  c1_node *left;
  void *value;
  c1_node *right;
  
  left = expr_build_this(sym);
  if (left != (c1_node *)0x0) {
    if ((*(byte *)((int)&g_current_function->tail + 10) & 0x10) != 0) {
      value = sym_this_adjustment(g_current_function);
      if (value != (void *)0x0) {
        right = tree_new_int_constant((int)value);
        left = tree_new_binary('F',left,right);
        left->kind = left->kind | 0x20;
      }
    }
    return left;
  }
  return (c1_node *)0x0;
}

