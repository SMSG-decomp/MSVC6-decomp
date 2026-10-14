void __thiscall type_check_array_bound_constant_2(void *d,c1_node *node)

{
  c1_node *node_00;
  c1_node *pcVar1;
  char *pcVar2;
  c1_type *layer;
  ushort a;
  void *local_4;
  
  a = 0x83;
  local_4 = (void *)0x0;
  node_00 = (c1_node *)0x0;
  if (node != (c1_node *)0x0) {
    node_00 = expr_resolve_address_of_overload(node);
    if ((node_00->kind & 8) == 0) {
      node_00 = fold_static_const_member(node_00);
      if (((node_00->kind & 7) == 3) && ((node_00->type->code & 0x110) != 0)) {
        local_4 = node_00->left;
      }
      else {
        pcVar1 = conv_convert_expression('t',g_type_int,node_00,'\x02','\0');
        if (pcVar1 == (c1_node *)0x0) {
          local_4 = (void *)0x1;
        }
        else {
          a = 0x4083;
          node_00 = pcVar1;
        }
      }
    }
  }
  if ((a & 0x4000) != 0) {
    if (*(int *)((int)d + 4) == 0) {
      *(c1_node **)((int)d + 0x40) = node_00;
      local_4 = (void *)0x0;
      pcVar2 = tree_find_template_parameter_use((char *)node_00);
      if (pcVar2 == (char *)0x0) {
        *(byte *)((int)d + 0x14) = *(byte *)((int)d + 0x14) | 2;
      }
      else {
        a = a & 0xbfff;
      }
    }
    else {
      pcVar2 = tree_find_template_parameter_use((char *)node_00);
      if (pcVar2 == (char *)0x0) {
        diag_error(0x21c);
        a = a & 0xbfff;
        *(byte *)((int)d + 0x3c) = *(byte *)((int)d + 0x3c) | 1;
        local_4 = (void *)0x1;
      }
    }
  }
  layer = (c1_type *)record_pos_new(a,0,(int *)&local_4);
  type_check_array_declarator(d,layer);
  if (*(int *)((int)d + 8) == 0) {
    *(c1_type **)((int)d + 8) = layer;
    *(c1_type **)((int)d + 4) = layer;
    return;
  }
  *(c1_type **)(*(int *)((int)d + 8) + 4) = layer;
  *(c1_type **)((int)d + 8) = layer;
  return;
}

