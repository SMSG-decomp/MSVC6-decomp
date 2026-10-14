void __fastcall arena_reset_to_base(c1_arena *a)

{
  a->committed = 0;
  a->cur = a->base;
  a->end = a->base;
  a->unk18 = 0;
  return;
}

