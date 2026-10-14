c1_node * __cdecl
expr_build_builtin_binary_pointer_add
          (c1_type *ptr_type,int swapped,c1_type *other_type,c1_node *node,c1_u8 op,c1_node *right)

{
  c1_node *pcVar1;
  ushort uVar2;
  
  uVar2 = ptr_type->code & 0x8f;
  if ((uVar2 == 0x86) || (((char)ptr_type->code < '\0' && (uVar2 == 0x84)))) {
    if (swapped != 0) {
      diag_error_C2296_or_C2297(op,2,ptr_type);
      return (c1_node *)0x0;
    }
    diag_error_C2296_or_C2297(op,1,ptr_type);
    return (c1_node *)0x0;
  }
  if ((other_type->code & 0x110) != 0) {
    g_constant_value = type_size_checked(ptr_type);
    g_constant_value_high = 0;
    pcVar1 = tree_new_constant(g_type_long,&g_constant_value,g_expr_arena_index);
    pcVar1 = expr_build_builtin_binary('J',right,pcVar1);
    node->right = pcVar1;
    return node;
  }
  if ((char)other_type->code < '\0') {
    diag_error(0x6e);
    return (c1_node *)0x0;
  }
  diag_error(0x6f);
  return (c1_node *)0x0;
}

