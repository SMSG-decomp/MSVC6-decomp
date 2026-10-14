c1_lookup_entry * __thiscall lookup_check_ambiguous_symbol(c1_lookup_result *result,char report)

{
  c1_symbol *pcVar1;
  bool bVar2;
  bool bVar3;
  c1_lookup_entry *pcVar4;
  byte bVar5;
  c1_lookup_entry *pcVar6;
  c1_symbol *pcVar7;
  
  pcVar4 = result->head;
  if (pcVar4 == (c1_lookup_entry *)0x0) {
    return (c1_lookup_entry *)0x0;
  }
  if (pcVar4 == result->tail) {
    return pcVar4;
  }
  pcVar7 = (c1_symbol *)0x0;
  bVar2 = false;
  bVar3 = false;
  pcVar6 = pcVar4;
  if (pcVar4 != (c1_lookup_entry *)0x0) {
    do {
      pcVar1 = pcVar6->sym;
      bVar5 = pcVar1->kind & 0x1f;
      if (((((bVar5 == 0x10) || (bVar5 == 7)) || (bVar5 == 6)) ||
          (((bVar5 == 0x11 || (bVar5 == 8)) || (bVar5 == 0x1b)))) ||
         ((bVar5 == 0x1a &&
          (((bVar5 = **(byte **)pcVar1->type & 0x1f, bVar5 == 0x10 || (bVar5 == 7)) ||
           ((bVar5 == 6 || (((bVar5 == 0x11 || (bVar5 == 8)) || (bVar5 == 0x1b)))))))))) {
        if (bVar3) goto LAB_10493459;
        bVar2 = true;
      }
      else {
        if (bVar2) {
LAB_10493459:
          if (report == '\0') {
            return (c1_lookup_entry *)0x0;
          }
          diag_error(0x368,pcVar4->sym->name);
          return result->head;
        }
        if (pcVar7 == (c1_symbol *)0x0) {
          bVar3 = true;
          pcVar7 = pcVar1;
        }
        else {
          if (pcVar1 != pcVar7) goto LAB_10493459;
          bVar3 = true;
        }
      }
      pcVar6 = pcVar6->next;
    } while (pcVar6 != (c1_lookup_entry *)0x0);
    if (pcVar7 != (c1_symbol *)0x0) {
      return pcVar4;
    }
  }
  pcVar4 = sym_new_kind1b(result);
  return pcVar4;
}

