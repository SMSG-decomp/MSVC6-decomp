void __fastcall remove_register_uses(c2_function *fn,c2_symbol *reg)

{
  c2_tuple *pcVar1;
  c2_tuple *t;
  c2_operand *pcVar2;
  
  pcVar1 = fn->cfg->first->head;
joined_r0x1073fd56:
  do {
    do {
      t = pcVar1;
      if (t == (c2_tuple *)0x0) {
        return;
      }
      pcVar1 = t->next;
    } while ((t->flags & 1) == 0);
    for (pcVar2 = t->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
      if ((pcVar2->kind == '\x01') && (((pcVar2->u18).reg)->storage == reg)) {
        tuple_unlink_free(t);
        goto joined_r0x1073fd56;
      }
    }
    for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
      if ((pcVar2->kind == '\x01') && (((pcVar2->u18).reg)->storage == reg)) {
        pcVar2 = tuple_replace_src_with_base_copy(t,pcVar2,pcVar2->sym);
      }
    }
  } while( true );
}

