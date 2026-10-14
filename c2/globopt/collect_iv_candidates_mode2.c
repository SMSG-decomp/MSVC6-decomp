c2_list_cell * __cdecl collect_iv_candidates_mode2(c2_loop *loop)

{
  uint32_t uVar1;
  c2_tuple *v;
  c2_block *pcVar2;
  
  pcVar2 = loop->first;
  if (pcVar2 != loop->last->next) {
    do {
      v = pcVar2->head->next;
      if (v != pcVar2->end) {
        do {
          if (((v->op == 0x17d) && ((1 << (byte)(v->type >> 0xc) & 0xeU) != 0)) &&
             (((uVar1 = is_induction_variable_operand(v->src), uVar1 != 0 &&
               (uVar1 = is_loop_invariant_operand(v->src->next), uVar1 != 0)) ||
              ((uVar1 = is_loop_invariant_operand(v->src), uVar1 != 0 &&
               (uVar1 = is_induction_variable_operand(v->src->next), uVar1 != 0)))))) {
            iv_worklist_push(v);
          }
          v = v->next;
        } while (v != pcVar2->end);
      }
      pcVar2 = pcVar2->next;
    } while (pcVar2 != loop->last->next);
    return g_iv_worklist;
  }
  return g_iv_worklist;
}

