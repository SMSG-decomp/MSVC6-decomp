void __cdecl stmt_emit_condition(c1_node *node,c1_node *n,uint jump_if_true)

{
  c1_u16 cVar1;
  c1_u32 cVar2;
  c1_type *pcVar3;
  byte bVar4;
  c1_u8 cVar5;
  c1_node *pcVar6;
  c1_type *pcVar7;
  c1_conversion *conv;
  c1_type local_10;
  
  while( true ) {
    cVar1 = node->type->code;
    if (((cVar1 != 0x80c) && (cVar1 != 0x80e)) && (node->op == 0xe8)) {
      node = property_build_access('\x01',node,(c1_node *)0x0);
    }
    cVar1 = node->type->code;
    if (((cVar1 == 0x80c) || (cVar1 == 0x80e)) &&
       (node = expr_resolve_function_address((c1_type *)0x0,node), node == (c1_node *)0x0)) {
      diag_error(0x236);
      return;
    }
    if (((byte)node->type->code >> 6 & 1) != 0) {
      diag_error(0xb4);
    }
    bVar4 = node->kind & 7;
    if ((bVar4 == 3) || (bVar4 == 5)) {
      diag_warning(4,0x7f);
    }
    conv = (c1_conversion *)g_arenas[5].cur;
    cVar2 = g_tree_op_to_il_op[node->op];
    if (cVar2 != 0x1a) break;
    node = node->left;
    jump_if_true = (uint)(jump_if_true == 0);
  }
  if (cVar2 == 0x1b) {
    pcVar6 = n;
    if (jump_if_true == 0) {
      pcVar6 = label_new(*(int *)((int)n->left + 0x24));
    }
    stmt_emit_condition(node->left,pcVar6,1);
    stmt_emit_condition(node->right,n,jump_if_true);
    if (jump_if_true == 0) {
      label_emit_definition(pcVar6);
    }
  }
  else {
    if (cVar2 != 0x1c) {
      if ((node->type->code & 0x200) != 0) {
        g_arenas[5].cur = g_arenas[5].cur + 0x50;
        if (g_arenas[5].end < g_arenas[5].cur) {
          arena_grow(g_arenas + 5);
        }
        pcVar3 = g_type_bool;
        if (conv == (c1_conversion *)0x0) {
          conv = (c1_conversion *)0x0;
        }
        else {
          cVar5 = node->op;
          conv->op = cVar5;
          switch(cVar5) {
          case 'd':
            cVar5 = '\x04';
            break;
          default:
            cVar5 = '\x02';
            break;
          case 't':
            cVar5 = '\x01';
            break;
          case 200:
            cVar5 = '\x06';
            break;
          case 0xd6:
            cVar5 = '\a';
            break;
          case 0xdd:
            cVar5 = '\b';
            break;
          case 0xde:
            cVar5 = '\t';
          }
          *(c1_u8 *)((int)conv + 1) = cVar5;
          *(c1_u8 *)((int)conv + 2) = '\0';
          *(c1_node **)((int)conv + 4) = node;
          if (node == (c1_node *)0x0) {
            type_descriptor_clear(&local_10);
            local_10.code = 0x80f;
            local_10.flags = 0;
            local_10.extra.cls = (c1_symbol *)0x0;
            pcVar7 = type_intern(&local_10);
            *(c1_type **)((int)conv + 8) = pcVar7;
            *(c1_type **)((int)conv + 0xc) = pcVar3;
            conv_compute_conversion(conv);
          }
          else {
            *(c1_type **)((int)conv + 8) = node->type;
            *(c1_type **)((int)conv + 0xc) = pcVar3;
            conv_compute_conversion(conv);
          }
        }
        if ((conv->flags4e & 1) == 0) {
          diag_begin_global(g_token_position);
          diag_error(0x1c3,node->type);
          conv_report_cannot_convert(conv,'\0');
          diag_end_global();
          return;
        }
        node = conv_apply_conversion(conv,(c1_node *)0x0);
      }
      il_emit_pragma_or_segment_record(0x24);
      il_emit_expression_tree(node);
      il_emit_tuple((jump_if_true != 0) + 0x38,n);
      return;
    }
    pcVar6 = n;
    if (jump_if_true != 0) {
      pcVar6 = label_new(*(int *)((int)n->left + 0x24));
    }
    stmt_emit_condition(node->left,pcVar6,0);
    stmt_emit_condition(node->right,n,jump_if_true);
    if (jump_if_true != 0) {
      label_emit_definition(pcVar6);
      return;
    }
  }
  return;
}

