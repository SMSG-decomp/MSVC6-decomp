int __fastcall tuples_equal(c2_tuple *a,c2_tuple *b)

{
  int iVar1;
  c2_tuple *label_a;
  c2_tuple *label_b;
  
  if (a->op == b->op) {
    if (a->kind == '\x16') {
      switch(*(undefined1 *)(a->op + 0x10786a1d)) {
      case 0:
        return 0;
      case 1:
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\fg.c",0x161c);
      case 2:
        return 1;
      }
    }
    switch(a->kind) {
    default:
      if (((((a->type ^ b->type) & 0xfff) == 0) &&
          (iVar1 = operand_lists_equal_skipping_memeffects(a->dst,b->dst), iVar1 != 0)) &&
         (iVar1 = operand_lists_equal_skipping_memeffects(a->src,b->src), iVar1 != 0)) {
        return 1;
      }
      break;
    case '\x0e':
      if (((((a->type ^ b->type) & 0xfff) == 0) &&
          (iVar1 = operand_lists_equal_skipping_memeffects(a->dst,b->dst), iVar1 != 0)) &&
         ((iVar1 = operand_lists_equal_skipping_memeffects(a->src,b->src), iVar1 != 0 &&
          ((a->u20).cond_cells == (b->u20).cond_cells)))) {
        return 1;
      }
      break;
    case '\x11':
      if (((char)a->type == (char)b->type) &&
         (iVar1 = operand_lists_equal_skipping_memeffects(a->src,b->src), iVar1 != 0)) {
        return 1;
      }
      if (((((char)a->type == (char)b->type) && (a->src->kind == '\x04')) &&
          (label_a = *(c2_tuple **)((int)&a->src->sym->u30 + 2), label_a != (c2_tuple *)0x0)) &&
         (((b->src->kind == '\x04' &&
           (label_b = *(c2_tuple **)((int)&b->src->sym->u30 + 2), label_b != (c2_tuple *)0x0)) &&
          ((label_a->next == label_b || (label_b->next == label_a)))))) {
        return 1;
      }
      break;
    case '\x13':
      break;
    }
  }
  return 0;
}

