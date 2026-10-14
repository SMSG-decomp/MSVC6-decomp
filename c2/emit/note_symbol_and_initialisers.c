void __fastcall note_symbol_and_initialisers(c2_fe_symbol *s)

{
  c2_fe_symbol *s_00;
  c2_init *pcVar1;
  
  if (((s->flags31 & 1) != 1) && ((s->flags31 & 2) != 2)) {
    note_symbol_referenced(s);
    if (s->cls == '\x01') {
      if ((s->attrs & 0x480) != 0) {
        pcVar1 = (s->u32).inits;
        if (pcVar1 == (c2_init *)0x0) {
          pcVar1 = data_def_find_by_id(s->id);
          (s->u32).inits = pcVar1;
        }
        for (pcVar1 = pcVar1->next; pcVar1 != (c2_init *)0x0; pcVar1 = pcVar1->next) {
          if (pcVar1->kind == 2) {
            s_00 = fe_symbol_lookup_id((pcVar1->u08).address.target_id);
            if (((s_00->cls == '\x04') || (s_00->cls == '\x01')) && ((s_00->storage & 0x1000) != 0))
            {
              s_00 = (c2_fe_symbol *)fe_symbol_resolve_redirect((int)s_00);
            }
            if ((s_00->flags31 & 4) == 0) {
              note_symbol_and_initialisers(s_00);
            }
          }
        }
      }
    }
    else if (((s->cls == '\x04') && ((s->storage & 0x4000) != 0)) && ((s->storage & 0x1000) == 0)) {
      s->fn_flags = s->fn_flags | 0x20;
      return;
    }
  }
  return;
}

