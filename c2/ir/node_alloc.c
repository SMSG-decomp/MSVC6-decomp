c2_node * __fastcall node_alloc(uint8_t kind)

{
  uint size_00;
  c2_node *node;
  uint uVar1;
  uint32_t size;
  uint32_t *fill;
  
  size_00 = g_node_kind_sizes[kind];
  node = g_node_free_lists[size_00];
  if (node != (c2_node *)0x0) {
    g_node_free_lists[size_00] = node->next;
    fill = (uint32_t *)node;
    for (uVar1 = size_00 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      ((c2_node *)fill)->next = (c2_node *)0x0;
      fill = &((c2_node *)fill)->op;
    }
    for (size = size_00 & 3; size != 0; size = size - 1) {
      *(undefined1 *)fill = 0;
      fill = (uint32_t *)((int)fill + 1);
    }
    node->kind = kind;
    return node;
  }
  node = arena_alloc(1,size_00);
  node->kind = kind;
  return node;
}

