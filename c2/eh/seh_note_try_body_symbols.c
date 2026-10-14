void __fastcall seh_note_try_body_symbols(c2_tuple *t)

{
  uint32_t uVar1;
  c2_operand *pcVar2;
  c2_symbol *s;
  
  uVar1 = t->op;
  do {
    if (uVar1 == 0x19a) {
      return;
    }
    if ((t->flags & 1) != 0) {
      for (pcVar2 = t->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        if (pcVar2->kind == '\x02') {
          s = pcVar2->sym;
LAB_10760175:
          if ((s != (c2_symbol *)0x0) && (s->cls != '\x03')) {
            seh_note_symbol_in_try_scope(s);
          }
        }
        else if (pcVar2->kind == '\x06') {
          s = pcVar2->base_sym;
          goto LAB_10760175;
        }
      }
    }
    t = t->next;
    uVar1 = t->op;
  } while( true );
}

