c2_tuple * __fastcall cleanup_marker_tuple(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  c2_tuple *t_00;
  
  t_00 = t->next;
  if (g_fg_keep_markers == 0) {
    switch(t->op) {
    case 0x1b4:
      if ((t_00 != (c2_tuple *)0x0) && (t_00->op == 0x1ab)) {
        pcVar3 = t_00;
        for (pcVar2 = t_00->next; pcVar2 != (c2_tuple *)0x0; pcVar2 = pcVar2->next) {
          if (pcVar2->op != 0x1ab) {
            if ((pcVar2->op != 0x18c) || (pcVar3->op != 0x1ab)) {
LAB_1070476a:
              if (((pcVar2 != (c2_tuple *)0x0) && (pcVar2->kind == '\x16')) && (pcVar2->op == 0x1b5)
                 ) {
                while ((t_00->op == 0x1ab || (t_00->op == 0x18c))) {
                  pcVar3 = t_00->next;
                  tuple_unlink_free(t_00);
                  t_00 = pcVar3;
                }
              }
              break;
            }
            pcVar3 = (pcVar3->u20).default_label;
            while( true ) {
              if (pcVar3 == (c2_tuple *)0x0) goto LAB_1070476a;
              if (((pcVar3->op == 0x1ac) && (pcVar1 = pcVar3->src, pcVar1->kind == '\a')) &&
                 ((pcVar1->u18).reg == (c2_symbol *)0x0 && pcVar1->tag == 0)) break;
              pcVar3 = pcVar3->next;
            }
          }
          pcVar3 = pcVar2;
        }
      }
    case 0x1b5:
      if ((t->u14).arg != (void *)0x0) {
        if ((1 << (t->prev->kind & 0x1f) & 0xa0000U) != 0) {
          tuple_move_before(t->prev,t);
        }
        return t_00;
      }
    case 0x1b6:
      tuple_unlink_free(t);
      return t_00;
    }
  }
  return (c2_tuple *)0x0;
}

