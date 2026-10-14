c2_operand * __fastcall find_next_reader_of(c2_tuple *t,c2_operand *op,c2_tuple **out)

{
  c2_symbol *sym;
  c2_operand *pcVar1;
  
  sym = op->sym;
  do {
    if ((t->flags & 1) != 0) {
      pcVar1 = find_src_symbol_ref(t,sym);
      if (pcVar1 != (c2_operand *)0x0) {
        *out = t;
        return pcVar1;
      }
    }
    t = t->next;
  } while( true );
}

