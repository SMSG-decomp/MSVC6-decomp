void __fastcall cxx_eh_funclet_ref_released(c2_tuple *t)

{
  c2_eh_state *pcVar1;
  c2_function *pcVar2;
  uint uVar3;
  int iVar4;
  c2_eh_state *pcVar5;
  uint uVar6;
  
  uVar6 = 1;
  pcVar1 = ((t->u20).eh_construct)->object;
  if ((pcVar1 != (c2_eh_state *)0x0) && (pcVar2 = pcVar1->funclet, pcVar2 != (c2_function *)0x0)) {
    iVar4 = pcVar2->funclet_refs + -1;
    pcVar2->funclet_refs = iVar4;
    if (iVar4 == 0) {
      node_list_free((c2_node *)pcVar2->cfg->first->head);
    }
    pcVar5 = g_eh_object_records;
    if (g_eh_object_records != (c2_eh_state *)0x0) {
      do {
        uVar3 = pcVar5->flags;
        if ((((uVar3 & 0xff) == 6) || ((uVar3 & 0xff) == 7)) || (pcVar5 != pcVar1)) {
          uVar6 = uVar6 & uVar3 >> 10 & 1;
        }
        else {
          pcVar5->flags = uVar3 | 0x400;
        }
        pcVar5 = pcVar5->next;
      } while (pcVar5 != (c2_eh_state *)0x0);
      if (uVar6 == 0) {
        return;
      }
    }
    uVar6 = g_cur_function->flags;
    g_cur_function->flags = uVar6 & 0xffff7fff;
    if ((uVar6 & 0x10000) == 0) {
      g_frame_eh_record = (c2_fe_symbol *)0x0;
      g_eh_record_pushed = 0;
    }
  }
  return;
}

