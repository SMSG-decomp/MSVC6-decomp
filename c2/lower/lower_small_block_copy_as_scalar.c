c2_tuple * __fastcall lower_small_block_copy_as_scalar(c2_tuple *anchor)

{
  uint32_t uVar1;
  c2_symbol *pcVar2;
  c2_tuple *t;
  
  uVar1 = anchor->op;
  anchor->op = 0x145;
  t = tuple_new((uVar1 == 0x16b) + 0x15a,anchor->type,anchor->dst,anchor->src,tuple_insert_after,
                anchor);
  if (((1 << (anchor->dst->kind & 0x1f) & 6U) != 0) &&
     (pcVar2 = anchor->dst->sym, pcVar2->def != (c2_tuple *)0x0)) {
    pcVar2->def = t;
  }
  lower_tuple(t);
  return t->next;
}

