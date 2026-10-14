char __thiscall ovl_candidate_remove(c1_ovl_resolution *ctx,c1_ovl_candidate *cand,c1_node *node)

{
  cand->flags = cand->flags | 0x40;
  if (ctx->head == cand) {
    ctx->head = cand->next;
  }
  if (cand->next != (c1_ovl_candidate *)0x0) {
    cand->next->prev = cand->prev;
  }
  if (cand->prev != (c1_ovl_candidate *)0x0) {
    cand->prev->next = cand->next;
  }
  if ((cand->flags & 0x80) == 0) {
    ctx->live = ctx->live + -1;
  }
  if (ctx->live != 0) {
    return '\0';
  }
  ovl_report_call_failure(ctx,cand,node);
  return '\x01';
}

