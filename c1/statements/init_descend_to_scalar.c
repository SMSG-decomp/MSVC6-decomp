int __cdecl init_descend_to_scalar(c1_node *node)

{
  int iVar1;
  
  iVar1 = init_check_undefined_type(node);
  if (iVar1 == 0) {
    return 0;
  }
  while( true ) {
    iVar1 = sym_has_scalar_type(g_init_level->cursor);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = init_is_char_array_string_init(g_init_level->cursor,node);
    if (iVar1 != 0) break;
    iVar1 = init_check_undefined_type(node);
    if (iVar1 == 0) {
      iVar1 = init_descend_to_scalar_fragment();
      return iVar1;
    }
  }
  return 1;
}

