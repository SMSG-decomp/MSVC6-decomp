void __fastcall delete_block_tuples(c2_block *b)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *node;
  c2_list_cell *cell;
  c2_list_cell *prev_cell;
  
  pcVar1 = b->end;
  node = b->head->next;
  do {
    if (node == pcVar1) {
      return;
    }
    pcVar2 = node->next;
    if ((g_resimplify_list != (c2_list_cell *)0x0) && ((node->flags & 1) != 0)) {
      prev_cell = (c2_list_cell *)0x0;
      for (cell = g_resimplify_list; cell != (c2_list_cell *)0x0; cell = cell->next) {
        if ((cell->u04).tuple == node) {
          if (prev_cell == (c2_list_cell *)0x0) {
            g_resimplify_list = cell->next;
          }
          else {
            prev_cell->next = cell->next;
          }
          break;
        }
        prev_cell = cell;
      }
    }
    switch(node->kind) {
    case '\x11':
      branch_free(node);
      break;
    default:
      if (node->op != 0x16c) {
        tuple_unlink_free(node);
      }
      break;
    case '\x13':
      switch_free(node);
      break;
    case '\x17':
    case '\x18':
    case '\x19':
      break;
    case '\x1a':
      if (node->dst == (c2_operand *)0x0) {
        label_delete(node);
      }
    }
    node = pcVar2;
  } while( true );
}

