c1_type * __cdecl conv_warn_nonlvalue_array_2(c1_type pointer_type,c1_node *object,c1_node *node)

{
  c1_type *pcVar1;
  int level;
  
  if (-1 < (char)object->type->code) {
    if (g_ms_extensions == '\0') {
      level = 1;
    }
    else {
      level = 4;
    }
    diag_warning(level,0xdf);
  }
  if ((node->kind & 7) != 5) {
    pointer_type.debug_index = 0;
    pointer_type.base = node->type->base;
    pointer_type.code = 0x82;
    pointer_type.flags = 0;
    pointer_type.extra.sym = (c1_symbol *)0x0;
    pcVar1 = type_intern(&pointer_type);
    return pcVar1;
  }
  return node->type;
}

