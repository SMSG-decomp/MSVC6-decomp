c1_node * __cdecl
expr_build_call_with_temporaries_retype(c1_symbol *fn,c1_node *node,c1_type *ret_type)

{
  c1_u8 *pcVar1;
  void **old_head;
  
  node->type = ret_type;
  pcVar1 = g_arenas[0].cur;
  if ((g_opt_Ct != '\0') && (g_inline_level != 0)) {
    g_arenas[0].cur = g_arenas[0].cur + 8;
    old_head = (void **)((g_current_function->tail).fn.record)->unk14;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    *(c1_symbol **)pcVar1 = fn;
    *(void ***)(pcVar1 + 4) = old_head;
    ((g_current_function->tail).fn.record)->unk14 = (c1_u32)pcVar1;
  }
  return node;
}

