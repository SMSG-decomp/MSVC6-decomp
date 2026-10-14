void clear_expression_hash(void)

{
  c2_operand *node;
  c2_operand *pcVar1;
  c2_cse_expr **bucket;
  c2_cse_expr *entry;
  
  bucket = g_expr_hash;
  do {
    for (entry = *bucket; entry != (c2_cse_expr *)0x0; entry = entry->next) {
      node = entry->operands;
      (entry->sym->u18).expr = (c2_cse_expr *)0x0;
      while (node != (c2_operand *)0x0) {
        pcVar1 = node->next;
        node_free((c2_node *)node);
        node = pcVar1;
      }
    }
    bucket = bucket + 1;
  } while ((int)bucket < 0x10799610);
  return;
}

