c1_node * __cdecl expr_build_conditional(c1_node *node,c1_node *node2,c1_node *node3)

{
  c1_type *type;
  c1_node *pcVar1;
  c1_node *right;
  char cVar2;
  
  if (((node != (c1_node *)0x0) && (node2 != (c1_node *)0x0)) && (node3 != (c1_node *)0x0)) {
    if (node->op == 0x98) {
      diag_error(0x113,node->left);
    }
    else {
      pcVar1 = node;
      if ((((node->op != 0xe8) ||
           (pcVar1 = property_build_access('\x01',node,(c1_node *)0x0), pcVar1 != (c1_node *)0x0))
          && ((node2->op != 0xe8 ||
              (node2 = property_build_access('\x01',node2,(c1_node *)0x0), node2 != (c1_node *)0x0))
             )) && ((node3->op != 0xe8 ||
                    (node3 = property_build_access('\x01',node3,(c1_node *)0x0),
                    node3 != (c1_node *)0x0)))) {
        node2 = expr_check_type_as_expression_4(0x36,node2);
        node3 = expr_check_type_as_expression_4(0x36,node3);
        if ((node2 != (c1_node *)0x0) && (node3 != (c1_node *)0x0)) {
          if ((((node2->flags & 1) == 0) && ((node2->type->code & 0xfff) != 0x10)) ||
             (((node3->flags & 1) == 0 && ((node3->type->code & 0xfff) != 0x10)))) {
            node._0_1_ = 0;
          }
          else {
            node._0_1_ = 1;
          }
          if (((node2->flags & 4) == 0) || ((node3->flags & 4) == 0)) {
            cVar2 = '\0';
          }
          else {
            cVar2 = '\x01';
          }
          type = conv_check_conditional_operands('6',&node2,&node3);
          pcVar1 = conv_convert_expression('V',g_type_bool,pcVar1,'\x02','\0');
          pcVar1 = fold_static_const_member(pcVar1);
          if ((((type != (c1_type *)0x0) && (node2 != (c1_node *)0x0)) && (node3 != (c1_node *)0x0))
             && (pcVar1 != (c1_node *)0x0)) {
            if ((((pcVar1->kind & 7) == 3) && ((node2->kind & 7) == 3)) && ((node3->kind & 7) == 3))
            {
              if (pcVar1->left != (void *)0x0 || pcVar1->right != (void *)0x0) {
                return node2;
              }
              return node3;
            }
            eh_mark_state_nodes_in_tree(node2);
            eh_mark_state_nodes_in_tree(node3);
            right = tree_new_node('6',node2,node3,type);
            pcVar1 = tree_new_node('V',pcVar1,right,type);
            if (((node2->type->code & 0xfff) == 0x11) && ((node3->type->code & 0xfff) == 0x11)) {
              pcVar1 = tree_new_cast(node2->type,pcVar1);
            }
            pcVar1->flags = pcVar1->flags & 0xfa ^ (byte)node | cVar2 << 2;
            return pcVar1;
          }
        }
      }
    }
  }
  return (c1_node *)0x0;
}

