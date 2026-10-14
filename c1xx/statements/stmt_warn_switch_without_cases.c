void stmt_warn_switch_without_cases(void)

{
  void **subject_slot;
  c1_flow_state *pcVar1;
  c1_flow_state *case_rec;
  void *pvVar2;
  int iVar3;
  bool bVar4;
  c1_flow_state *pcVar5;
  bool bVar6;
  c1_flow_state *pcVar7;
  c1_flow_state *sw;
  c1_u8 cVar8;
  int *piVar9;
  c1_symtab_iter local_14;
  
  if (g_flow_state_abandoned == '\0') {
    stmt_switch_body_end_flow_state();
    if (g_flow_state_top != (c1_flow_state *)0x0) {
      if (g_flow_state_top->kind == 0x31) {
        g_flow_switch_record = g_flow_switch_record->subject;
        func_flow_state_pop_record();
        diag_warning(3,0x3c);
        return;
      }
      if (g_flow_state_top->kind == 0x33) {
        return;
      }
    }
    local_14.entry = (c1_symtab_entry *)0x0;
    local_14.next_bucket = 0;
    local_14.tab = (c1_symtab *)0x36;
    local_14.key = (void *)0x0;
    func_check_flow_state_complexity((c1_u8 *)&local_14,0x10);
    sw = g_flow_switch_record;
    pcVar7 = g_flow_state_top;
    pcVar1 = g_flow_switch_record->subject;
    subject_slot = &g_flow_switch_record->subject;
    case_rec = (c1_flow_state *)g_flow_switch_record->word14;
    g_flow_switch_record = pcVar1;
    if (case_rec == (c1_flow_state *)0x0) {
      diag_warning(3,0x3c);
    }
    else {
      if ((case_rec->subject == (void *)0x0) && (case_rec->kind == 0x38)) {
        stmt_warn_switch_default((c1_flow_state *)0x0,sw,case_rec,subject_slot);
        return;
      }
      pvVar2 = case_rec->subject;
      pcVar1 = (c1_flow_state *)0x0;
      while (pcVar5 = case_rec, pvVar2 != (void *)0x0) {
        sw->word14 = (int)pvVar2;
        pcVar5->subject = pcVar1;
        case_rec = (c1_flow_state *)sw->word14;
        pcVar1 = pcVar5;
        pvVar2 = ((c1_flow_state *)sw->word14)->subject;
      }
      pcVar5->subject = pcVar1;
    }
    *subject_slot = sw->next;
    sw->next = pcVar7;
    pcVar7->prev = sw;
    if ((sw->flags & 0x10) != 0) {
      iVar3 = sw->word1c;
      if (iVar3 == 0) {
        bVar4 = false;
        bVar6 = false;
        for (piVar9 = (int *)sw->word14; piVar9 != (int *)0x0; piVar9 = (int *)piVar9[4]) {
          if (*piVar9 == 0x37) {
            iVar3 = piVar9[5];
            if (iVar3 == 0) {
              bVar4 = true;
            }
            else if (iVar3 == 1) {
              bVar6 = true;
            }
            else {
              diag_warning(1,0x328,iVar3);
            }
          }
        }
        if ((((sw->flags & 1) != 0) && (bVar4)) && (bVar6)) {
          diag_warning(1,0x329);
          return;
        }
      }
      else if ((*(byte *)(iVar3 + 2) & 4) == 0) {
        diag_warning(4,0x40,iVar3);
      }
      else {
        piVar9 = (int *)sw->word14;
        if (piVar9 != (int *)0x0) {
          do {
            if (*piVar9 == 0x37) {
              symtab_iterator_init(&local_14,*(c1_symtab **)(sw->word1c + 0x28));
              do {
                cVar8 = symtab_iterator_next(&local_14);
                if (cVar8 == '\0') {
                  diag_warning(4,0x3f,piVar9[5],sw->word1c);
                  break;
                }
              } while (*(int *)((int)local_14.value + 0x28) != piVar9[5]);
            }
            piVar9 = (int *)piVar9[4];
            if (piVar9 == (int *)0x0) {
              return;
            }
          } while( true );
        }
      }
    }
  }
  return;
}

