c2_operand * __fastcall reader_pop_owned_operand(c2_reader_cell **stack)

{
  c2_operand *pcVar1;
  c2_tuple *node;
  
  node = reader_pop(stack);
  pcVar1 = node->src;
  node->src = (c2_operand *)0x0;
  pcVar1->flags = pcVar1->flags & 0xef;
  node_free((c2_node *)node);
  return pcVar1;
}

