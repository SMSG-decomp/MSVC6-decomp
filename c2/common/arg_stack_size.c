uint32_t __fastcall arg_stack_size(c2_node *t)

{
  for (; t->op == 0x15a; t = (c2_node *)t[1].rank_or_prev) {
  }
  if ((t->op == 400) && (*(short *)&t[2].next == 0x184)) {
    return g_default_stack_align + -1 +
           *(int *)(*(int *)(*(int *)(*(int *)(**(int **)&t[1].kind + 0x14) + 0x14) + 0x18) + 0x18)
           & ~(g_default_stack_align - 1U);
  }
  return g_default_stack_align + -1 + (t->type & 0xfff) & ~(g_default_stack_align - 1U);
}

