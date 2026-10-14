void __cdecl init_emit_element_store(c1_symbol *sym,c1_node *node,c1_u8 *node2)

{
  c1_type *pcVar1;
  ushort uVar2;
  c1_type *pcVar3;
  c1_node *pcVar4;
  int iVar5;
  c1_node *item;
  c1_conversion *conv;
  c1_node *item_00;
  int flag;
  c1_type local_10;
  
  conv = (c1_conversion *)g_arenas[5].cur;
  if (node2 == (c1_u8 *)0x0) {
    g_arenas[5].cur = g_arenas[5].cur + 0x50;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (conv == (c1_conversion *)0x0) {
      conv = (c1_conversion *)0x0;
    }
    else {
      pcVar1 = sym->type;
      conv->op = 't';
      *(c1_u8 *)((int)conv + 1) = '\x01';
      *(c1_u8 *)((int)conv + 2) = '\0';
      *(c1_node **)((int)conv + 4) = node;
      if (node == (c1_node *)0x0) {
        local_10.base = (c1_type *)0x0;
        local_10.debug_index = 0;
        local_10.flags = 0;
        local_10.extra.cls = (c1_symbol *)0x0;
        local_10.code = 0x80f;
        pcVar3 = type_intern(&local_10);
        *(c1_type **)((int)conv + 8) = pcVar3;
        *(c1_type **)((int)conv + 0xc) = pcVar1;
        conv_compute_conversion(conv);
      }
      else {
        *(c1_type **)((int)conv + 8) = node->type;
        *(c1_type **)((int)conv + 0xc) = pcVar1;
        conv_compute_conversion(conv);
      }
    }
    node2 = &conv->op;
    if ((conv->flags4e & 1) == 0) {
      conv_report_cannot_convert(conv,'\x01');
      return;
    }
  }
  pcVar4 = init_element_lvalue(sym->type);
  iVar5 = init_is_char_array_string_init(sym,node);
  if (iVar5 != 0) {
    uVar2 = init_check_array_bounds(sym,node);
    *(ushort *)&node->right = uVar2;
    flag = 1;
    item = tree_new_int_constant((uint)uVar2);
    iVar5 = 1;
    item_00 = node;
    pcVar4 = tree_append_list_item((c1_node *)0x0,pcVar4,1);
    pcVar4 = tree_append_list_item(pcVar4,item_00,iVar5);
    pcVar4 = tree_append_list_item(pcVar4,item,flag);
    stmt_emit_intrinsic_call(0xac,pcVar4);
    g_init_offset = g_init_offset + (uint)*(ushort *)&node->right;
    return;
  }
  pcVar1 = sym->type;
  pcVar4->type = pcVar1;
  iVar5 = type_size(pcVar1);
  init_emit_initializer_expression(pcVar4,(c1_conversion *)node2);
  g_init_offset = g_init_offset + iVar5;
  return;
}

