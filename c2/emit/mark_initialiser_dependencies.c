int __fastcall mark_initialiser_dependencies(c2_fe_symbol *s)

{
  c2_fe_symbol *s_00;
  int iVar1;
  c2_init *pcVar2;
  
  if ((s->cls == '\x01') && ((s->attrs & 0x480) != 0)) {
    pcVar2 = (s->u32).inits;
    if (pcVar2 == (c2_init *)0x0) {
      pcVar2 = data_def_find_by_id(s->id);
      (s->u32).inits = pcVar2;
    }
    for (pcVar2 = pcVar2->next; pcVar2 != (c2_init *)0x0; pcVar2 = pcVar2->next) {
      if (pcVar2->kind == 2) {
        s_00 = fe_symbol_lookup_id((pcVar2->u08).address.target_id);
        if (s_00 == (c2_fe_symbol *)0x0) {
          return 0;
        }
        if (((s_00->cls == '\x04') || (s_00->cls == '\x01')) && ((s_00->storage & 0x1000) != 0)) {
          s_00 = (c2_fe_symbol *)fe_symbol_resolve_redirect((int)s_00);
        }
        if ((s_00->flags31 & 4) != 4) {
          s_00->flags31 = s_00->flags31 | 4;
          iVar1 = mark_initialiser_dependencies(s_00);
          if (iVar1 == 0) {
            s_00->flags31 = s_00->flags31 & 0xfb;
            return 0;
          }
          s_00->flags31 = s_00->flags31 & 0xfb;
          note_symbol_referenced(s_00);
          if (((s_00->cls == '\x04') && ((s_00->storage & 0x4000) != 0)) &&
             ((s_00->storage & 0x1000) == 0)) {
            s_00->fn_flags = s_00->fn_flags | 0x20;
          }
        }
      }
    }
  }
  return 1;
}

