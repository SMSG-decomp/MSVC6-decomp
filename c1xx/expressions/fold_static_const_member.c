c1_node * __cdecl fold_static_const_member(c1_node *node)

{
  char *node_00;
  c1_symbol *sym;
  c1_symbol *pcVar1;
  c1_node *pcVar2;
  int size;
  uint local_8;
  c1_type *local_4;
  
  if (((g_token_class[node->op] == '=') && (node_00 = node->left, *node_00 == '\x06')) &&
     (sym = *(c1_symbol **)(node_00 + 0x10), (sym->flags5 & 0x40) != 0)) {
    if ((sym->kind & 0x1f) == 0x17) {
      pcVar2 = (c1_node *)tree_find_template_parameter_use(node_00);
      if (pcVar2 != (c1_node *)0x0) {
        return pcVar2;
      }
      pcVar1 = (sym->tail).seg_helper;
      if (pcVar1->kind == 'e') {
        local_8 = pcVar1->position;
        local_4 = pcVar1->type;
      }
    }
    else {
      local_8 = (sym->tail).data.value_lo;
      local_4 = (c1_type *)(sym->tail).data.value_hi;
    }
    if ((char)(*(c1_type **)(node_00 + 4))->code < '\0') {
      node = tree_new_int_constant(local_8);
    }
    else {
      size = type_size_scalar(*(c1_type **)(node_00 + 4));
      node = tree_new_three_fields_flagged(local_8,(int)local_4,size);
      if ((local_8 == 0 && local_4 == (c1_type *)0x0) ||
         ((local_8 == 1 && (local_4 == (c1_type *)0x0)))) {
        node->flags = node->flags | 1;
      }
    }
    node->type = sym->type;
    if ((sym->flags3 & 8) != 0) {
      sym_mark_referenced(sym);
    }
  }
  return node;
}

