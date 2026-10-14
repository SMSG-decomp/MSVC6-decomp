void __fastcall split_mark_symbol_in_chain(void *piece,c2_symbol *s)

{
  uint32_t n;
  
  if (((s->u30).order_prev != (c2_symbol *)0x0) && (s->cls != '\r')) {
    if ((s->u34).parent != (c2_symbol *)0x0) {
      s = (s->u34).parent;
    }
    n = ((s->u30).ra)->id;
    do {
      bitset_set(*(c2_bitset **)((int)piece + 0x38),n);
      piece = *(void **)((int)piece + 8);
    } while (piece != (void *)0x0);
  }
  return;
}

