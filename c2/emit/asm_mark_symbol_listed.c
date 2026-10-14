void __fastcall asm_mark_symbol_listed(c2_fe_symbol *s)

{
  if ((s->flags31 & 4) != 0) {
    s->flags31 = s->flags31 | 2;
  }
  return;
}

