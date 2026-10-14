c1_decl_state * __thiscall
decl_state_snapshot(c1_decl_state *rec,c1_scope_stack *stack,c1_decl_state *next,char copy)

{
  c1_u8 *pcVar1;
  uint uVar2;
  byte bVar3;
  
  rec->current = stack->current;
  rec->depth = stack->depth;
  rec->qual_class = stack->qual_class;
  rec->access_op = stack->access_op;
  rec->reported = stack->reported;
  rec->qualified = stack->qualified;
  rec->keep_aliases = stack->keep_aliases;
  rec->kept = copy;
  rec->next = next;
  pcVar1 = g_arenas[8].cur;
  if ((rec->depth == 0) || (copy == '\0')) {
    rec->contexts = (c1xx_scope **)0x0;
  }
  else {
    g_arenas[8].cur = g_arenas[8].cur + (uint)rec->depth * 4;
    if (g_arenas[8].end < g_arenas[8].cur) {
      arena_grow(g_arenas + 8);
    }
    bVar3 = 1;
    rec->contexts = (c1xx_scope **)pcVar1;
    _copy = 1;
    if (rec->depth != '\0') {
      do {
        uVar2 = _copy;
        bVar3 = bVar3 + 1;
        _copy = (uint)bVar3;
        rec->contexts[uVar2 - 1] = stack->contexts[uVar2];
      } while (bVar3 <= rec->depth);
      return rec;
    }
  }
  return rec;
}

