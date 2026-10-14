c1_type * __cdecl conv_array_to_pointer_type(c1_node *node)

{
  c1_type *pcVar1;
  int level;
  c1_type local_10;
  
  if (((node->op == 'P') && (*(char *)node->left == 'p')) && (-1 < **(char **)((int)node->left + 4))
     ) {
    if (g_ms_extensions == '\0') {
      level = 1;
    }
    else {
      level = 4;
    }
    diag_warning(level,0xdf);
  }
  if ((node->kind & 7) != 5) {
    local_10.debug_index = 0;
    local_10.base = node->type->base;
    local_10.code = 0x82;
    local_10.flags = 0;
    local_10.extra.cls = (c1_symbol *)0x0;
    pcVar1 = type_intern(&local_10);
    return pcVar1;
  }
  return node->type;
}

