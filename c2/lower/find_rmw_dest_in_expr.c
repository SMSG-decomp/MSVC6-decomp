int __fastcall find_rmw_dest_in_expr(c2_node *node,int under_sub)

{
  uint32_t uVar1;
  c2_operand *pcVar2;
  int iVar3;
  
  if (((1 << (node->kind & 0x1f) & 0xffeU) == 0) ||
     ((((node->kind == 1 && (*(char *)(node[1].op + 4) == '\x03')) &&
       (node = *(c2_node **)(node[1].op + 0x14), (c2_tuple *)node != (c2_tuple *)0x0)) &&
      ((((c2_tuple *)node)->src != (c2_operand *)0x0 &&
       (((c2_tuple *)node)->src->next != (c2_operand *)0x0)))))) {
    uVar1 = ((c2_tuple *)node)->op;
    if (uVar1 == 0x16d) {
      under_sub = 1;
    }
    if ((g_rmw_match_op == uVar1) || ((g_rmw_match_op == 0x16d && (uVar1 == 0x16e)))) {
      if ((uVar1 == 0x175) ||
         (((uVar1 == 0x16e ||
           (pcVar2 = ((c2_tuple *)node)->src->next, g_rmw_store->type != pcVar2->type)) ||
          (iVar3 = operand_compare(g_rmw_dest_operand,pcVar2), iVar3 != 0)))) {
        if ((g_rmw_store->type != ((c2_tuple *)node)->src->type) ||
           (iVar3 = operand_compare(g_rmw_dest_operand,((c2_tuple *)node)->src), iVar3 != 0)) {
          pcVar2 = ((c2_tuple *)node)->src;
          iVar3 = find_rmw_dest_in_expr((c2_node *)pcVar2,under_sub);
          if (iVar3 != 0) {
            return 1;
          }
          if (((c2_tuple *)node)->op == 0x175) {
            return 0;
          }
          if (((c2_tuple *)node)->op == 0x16e) {
            return 0;
          }
          iVar3 = find_rmw_dest_in_expr((c2_node *)pcVar2->next,under_sub);
          if (iVar3 == 0) {
            return 0;
          }
          return 1;
        }
        g_rmw_found_operand = ((c2_tuple *)node)->src;
      }
      else {
        g_rmw_found_operand = ((c2_tuple *)node)->src->next;
      }
      g_rmw_found_tuple = (c2_tuple *)node;
      g_rmw_found_negated = under_sub;
      return 1;
    }
  }
  return 0;
}

