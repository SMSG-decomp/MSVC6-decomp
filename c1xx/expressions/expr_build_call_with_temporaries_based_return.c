c1_node * __cdecl expr_build_call_with_temporaries_based_return(c1_symbol *fn,c1_node *node)

{
  c1_u8 *pcVar1;
  c1_node *pcVar2;
  uint *old_head;
  
  pcVar2 = expr_based_pointer_fixup(node);
  pcVar1 = g_arenas[0].cur;
  if ((g_opt_Ct != '\0') && (g_inline_level != 0)) {
    g_arenas[0].cur = g_arenas[0].cur + 8;
    old_head = (uint *)((g_current_function->tail).fn.record)->unk14;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    *(c1_symbol **)pcVar1 = fn;
    *(uint **)(pcVar1 + 4) = old_head;
    ((g_current_function->tail).fn.record)->unk14 = (c1_u32)pcVar1;
  }
  return pcVar2;
}

