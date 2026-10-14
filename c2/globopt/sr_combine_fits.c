int __fastcall sr_combine_fits(uint16_t type,int op,c2_operand *a,c2_operand *b,c2_loop *loop)

{
  uint32_t a_00;
  c2_operand *pcVar1;
  c2_node *node;
  c2_node *node_00;
  int iVar2;
  
  pcVar1 = sr_materialize_operand_in_preheader(a,loop);
  node = node_clone((c2_node *)pcVar1);
  pcVar1 = sr_materialize_operand_in_preheader(b,loop);
  node_00 = node_clone((c2_node *)pcVar1);
  iVar2 = types_compatible(type,node->type);
  if ((iVar2 != 0) && (iVar2 = types_compatible(type,node_00->type), iVar2 != 0)) {
    if (op == 0x16d) {
      if (((node->kind == '\a') || (node->kind == '\x03')) &&
         ((node_00->kind == '\a' || (node_00->kind == '\x03')))) goto LAB_1076389b;
    }
    else if ((op != 0x16f) ||
            (((node->kind == '\a' && (node_00->kind == '\a')) &&
             (a_00._0_1_ = node_00[1].kind, a_00._1_1_ = node_00[1].flags,
             a_00._2_2_ = node_00[1].type,
             iVar2 = mul_overflows(a_00,*(int *)&node[1].kind + 1,(uint)((type & 0xf000) == 0x2000),
                                   type & 0xfff), iVar2 == 0)))) {
LAB_1076389b:
      node_free(node);
      node_free(node_00);
      return 1;
    }
  }
  node_free(node);
  node_free(node_00);
  return 0;
}

