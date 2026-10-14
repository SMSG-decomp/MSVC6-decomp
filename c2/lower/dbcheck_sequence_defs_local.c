uint32_t __fastcall dbcheck_sequence_defs_local(c2_tuple *t,c2_tuple *t2)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  int iVar4;
  
  pcVar1 = t2->next;
  g_dbcheck_pending_defs = (c2_symbol_cell *)0x0;
  do {
    if (t == pcVar1) {
      return 1;
    }
    if ((t->flags & 1) == 0) {
joined_r0x1078df87:
      if (g_dbcheck_pending_defs != (c2_symbol_cell *)0x0) {
        return 0;
      }
    }
    else {
      for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        if ((pcVar2->flags & 0x10) == 0) {
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\dbcheck.c",0x5e);
        }
        if ((((1 << (pcVar2->kind & 0x1f) & 6U) != 0) && (pcVar2->sym->def != (c2_tuple *)0x0)) &&
           (iVar4 = dbcheck_pop_pending_def(pcVar2->sym), iVar4 == 0)) {
          return 0;
        }
      }
      for (pcVar2 = t->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        if ((pcVar2->flags & 0x10) == 0) {
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\dbcheck.c",0x69);
        }
        if ((1 << (pcVar2->kind & 0x1f) & 6U) != 0) {
          pcVar3 = pcVar2->sym->def;
          if (pcVar3 != (c2_tuple *)0x0) {
            if (pcVar3 != t) {
              ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\dbcheck.c",0x6b);
            }
            dbcheck_push_def(pcVar2->sym);
          }
        }
      }
      if ((1 << (t->kind & 0x1f) & 0xa0000U) != 0) goto joined_r0x1078df87;
    }
    t = t->next;
  } while( true );
}

