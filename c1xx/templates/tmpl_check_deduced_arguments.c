char __fastcall tmpl_check_deduced_arguments(uint *deduction)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  ushort *puVar4;
  c1_deferred_action *pcVar5;
  void *value;
  c1_deferred_action *pcVar6;
  uint uVar7;
  int local_18;
  uint local_14;
  byte cursor [4];
  uint *cell;
  void *value_2;
  
  local_18 = 0;
  local_14 = 0;
  iVar3 = *(int *)deduction[4];
  pcVar6 = (c1_deferred_action *)g_arenas[5].cur;
joined_r0x104a92ba:
  if (iVar3 == 0) {
    g_arenas[5].cur = (c1_u8 *)pcVar6;
    return local_18 == 0;
  }
  g_arenas[5].cur = (c1_u8 *)pcVar6;
  if ((*(byte *)(iVar3 + 0xc) & 3) != 0) goto LAB_104a930b;
  puVar4 = *(ushort **)(iVar3 + 0x10);
  if (puVar4 == (ushort *)0x0) {
    g_arenas[5].cur = (c1_u8 *)&pcVar6->detail;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (pcVar6 != (c1_deferred_action *)0x0) {
      if (deduction[3] <= local_14) {
        diag_fatal(1,"..\\Cxx\\dymto.inl",0x1c0);
      }
      uVar7 = 0;
      if (deduction[2] == 0) {
        value = (void *)0x0;
      }
      else {
        value = *(void **)(deduction[2] + 4);
      }
      list_cursor_init(cursor,value);
      do {
        if (cell == (uint *)0x0) {
LAB_104a93c9:
          diag_fatal(1,"..\\Cxx\\dymto.inl",0x1cc);
        }
        if (uVar7 == local_14) goto LAB_104a9412;
        uVar7 = uVar7 + 1;
        if (cell == (uint *)0x0) goto LAB_104a93c9;
        cell = (uint *)cell[1];
      } while( true );
    }
    pcVar6 = (c1_deferred_action *)0x0;
    goto LAB_104a93f5;
  }
  cVar1 = (char)*puVar4;
  while (cVar1 < '\0') {
    puVar4 = *(ushort **)(puVar4 + 2);
    cVar1 = (char)*puVar4;
  }
  if ((*puVar4 & 0x300) != 0) {
    bVar2 = *(byte *)(*(int *)(puVar4 + 4) + 3);
    if ((bVar2 & 8) == 0) goto LAB_104a930b;
    if ((bVar2 & 1) == 0) {
      diag_error(0x396,*(int *)(puVar4 + 4));
      pcVar5 = g_deferred_actions_head;
      pcVar6 = g_deferred_actions_tail;
    }
    else {
      diag_error(0x397);
      pcVar5 = g_deferred_actions_head;
      pcVar6 = g_deferred_actions_tail;
    }
    goto LAB_104a9307;
  }
  goto LAB_104a930b;
LAB_104a9412:
  value_2 = (void *)*cell;
  pcVar6->sym = (c1_symbol *)*deduction;
  pcVar6->next = (c1_deferred_action *)0x0;
  pcVar6->arg = value_2;
  pcVar6->vtbl = &PTR_tmpl_deferred_report_c2783_104ceeac;
LAB_104a93f5:
  pcVar5 = pcVar6;
  if (g_deferred_actions_head != (c1_deferred_action *)0x0) {
    g_deferred_actions_tail->next = pcVar6;
    pcVar5 = g_deferred_actions_head;
  }
LAB_104a9307:
  g_deferred_actions_tail = pcVar6;
  g_deferred_actions_head = pcVar5;
  local_18 = local_18 + 1;
LAB_104a930b:
  iVar3 = *(int *)(iVar3 + 4);
  local_14 = local_14 + 1;
  pcVar6 = (c1_deferred_action *)g_arenas[5].cur;
  goto joined_r0x104a92ba;
}

