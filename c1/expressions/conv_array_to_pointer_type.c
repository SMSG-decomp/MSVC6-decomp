c1_type * __cdecl conv_array_to_pointer_type(c1_node *node)

{
  c1_type pointer_type;
  c1_type *pcVar1;
  c1_u16 in_stack_fffffff0;
  c1_u16 in_stack_fffffff2;
  c1_type *in_stack_fffffff4;
  c1_type_x08 in_stack_fffffff8;
  c1_u32 in_stack_fffffffc;
  
  if ((node->op == 'P') && (node->left->op == 'p')) {
    pointer_type.flags = in_stack_fffffff2;
    pointer_type.code = in_stack_fffffff0;
    pointer_type.base = in_stack_fffffff4;
    pointer_type.extra.sym = in_stack_fffffff8.sym;
    pointer_type.debug_index = in_stack_fffffffc;
    pcVar1 = conv_warn_nonlvalue_array_2(pointer_type,node->left,node);
    return pcVar1;
  }
  if ((node->kind & 7) != 5) {
    pcVar1 = type_intern((c1_type *)&stack0xfffffff0);
    return pcVar1;
  }
  return node->type;
}

