void __fastcall objless_mark_symbol_emitted(c2_fe_symbol *s)

{
  if ((s->cls == '\x01') || (s->cls == '\x04')) {
    s->flags31 = s->flags31 | 1;
  }
  return;
}

