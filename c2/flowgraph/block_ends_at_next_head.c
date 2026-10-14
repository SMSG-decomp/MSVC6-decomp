int __fastcall block_ends_at_next_head(c2_tuple *t)

{
  return (uint)(((t->u20).eh_try)->catch_rec == ((t->u20).eh_try)->try_block->catches);
}

