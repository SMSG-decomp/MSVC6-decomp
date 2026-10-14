void stmt_warn_switch_default
               (c1_flow_state *prev_case,c1_flow_state *sw,c1_flow_state *case_rec,
               void **subject_slot)

{
  void *pvVar1;
  bool bVar2;
  c1_u8 cVar3;
  int *piVar4;
  char cStack00000013;
  c1_flow_state *in_stack_00000014;
  void *in_stack_00000028;
  
  diag_warning(3,0x41);
  pvVar1 = case_rec->subject;
  while (pvVar1 != (void *)0x0) {
    sw->word14 = (int)pvVar1;
    case_rec->subject = prev_case;
    prev_case = case_rec;
    case_rec = (c1_flow_state *)sw->word14;
    pvVar1 = ((c1_flow_state *)sw->word14)->subject;
  }
  case_rec->subject = prev_case;
  *subject_slot = sw->next;
  sw->next = in_stack_00000014;
  in_stack_00000014->prev = sw;
  if ((sw->flags & 0x10) != 0) {
    if (sw->word1c == 0) {
      piVar4 = (int *)sw->word14;
      bVar2 = false;
      cStack00000013 = '\0';
      for (; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[4]) {
        if (*piVar4 == 0x37) {
          if (piVar4[5] == 0) {
            bVar2 = true;
          }
          else if (piVar4[5] == 1) {
            cStack00000013 = '\x01';
          }
          else {
            diag_warning(1,0x328);
          }
        }
      }
      if ((((sw->flags & 1) != 0) && (bVar2)) && (cStack00000013 != '\0')) {
        diag_warning(1,0x329);
        return;
      }
    }
    else if ((*(byte *)(sw->word1c + 2) & 4) == 0) {
      diag_warning(4,0x40);
    }
    else {
      piVar4 = (int *)sw->word14;
      if (piVar4 != (int *)0x0) {
        do {
          if (*piVar4 == 0x37) {
            symtab_iterator_init
                      ((c1_symtab_iter *)&stack0x00000018,*(c1_symtab **)(sw->word1c + 0x28));
            do {
              cVar3 = symtab_iterator_next((c1_symtab_iter *)&stack0x00000018);
              if (cVar3 == '\0') {
                diag_warning(4,0x3f,piVar4[5]);
                break;
              }
            } while (*(int *)((int)in_stack_00000028 + 0x28) != piVar4[5]);
          }
          piVar4 = (int *)piVar4[4];
          if (piVar4 == (int *)0x0) {
            return;
          }
        } while( true );
      }
    }
  }
  return;
}

