void free_late_cse_constants(void)

{
  c2_operand *pcVar1;
  c2_const_operand *node;
  
  node = g_late_cse_int_zero;
  while (node != (c2_const_operand *)0x0) {
    pcVar1 = node->next;
    node_free((c2_node *)node);
    node = pcVar1;
  }
  return;
}

