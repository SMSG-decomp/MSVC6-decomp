void __thiscall tmpl_work_queue_add_item(void *queue,c1_symbol *sym,int *args)

{
  byte bVar1;
  c1_tmpl_work_item *pcVar2;
  c1_arg_list *pcVar3;
  c1_u8 *pcVar4;
  
  pcVar2 = tmpl_work_queue_find(queue,sym);
  pcVar4 = g_arenas[0].cur;
  if (pcVar2 != (c1_tmpl_work_item *)0x0) {
    pcVar2->armed = '\x01';
    return;
  }
  bVar1 = sym->kind & 0x1f;
  if ((bVar1 == 7) || (bVar1 == 8)) {
    g_arenas[0].cur = g_arenas[0].cur + 0x28;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    if (pcVar4 != (c1_u8 *)0x0) {
      *(c1_symbol **)(pcVar4 + 4) = sym;
      pcVar4[8] = '\x01';
      pcVar4[0xc] = '\0';
      pcVar4[0xd] = '\0';
      pcVar4[0xe] = '\0';
      pcVar4[0xf] = '\0';
      *(undefined ***)pcVar4 = &PTR__purecall_104cf058;
      pcVar4[0x1c] = '\0';
      pcVar4[0x1d] = '\0';
      pcVar4[0x1e] = '\0';
      pcVar4[0x1f] = '\0';
      *(int *)(pcVar4 + 0x24) = g_token_position;
      *(undefined ***)pcVar4 = &PTR_tmpl_function_item_run_104cf050;
      if (args == (int *)0x0) {
        pcVar4[0x10] = '\0';
        pcVar4[0x11] = '\0';
        pcVar4[0x12] = '\0';
        pcVar4[0x13] = '\0';
        pcVar4[0x18] = '\0';
        pcVar4[0x19] = '\0';
        pcVar4[0x1a] = '\0';
        pcVar4[0x1b] = '\0';
        pcVar4[0x20] = '\0';
        pcVar4[0x21] = '\0';
        pcVar4[0x22] = '\0';
        pcVar4[0x23] = '\0';
        pcVar4[0x14] = '\0';
        pcVar4[0x15] = '\0';
        pcVar4[0x16] = '\0';
        pcVar4[0x17] = '\0';
      }
      else {
        *(int *)(pcVar4 + 0x10) = *args;
        *(int *)(pcVar4 + 0x18) = args[7];
        *(int *)(pcVar4 + 0x20) = args[8];
        pcVar3 = arena_alloc(g_arenas,0xc);
        if (pcVar3 == (c1_arg_list *)0x0) {
          pcVar4[0x14] = '\0';
          pcVar4[0x15] = '\0';
          pcVar4[0x16] = '\0';
          pcVar4[0x17] = '\0';
        }
        else {
          pcVar3 = eh_handler_list_copy(pcVar3,(c1_arg_list *)args[4]);
          *(c1_arg_list **)(pcVar4 + 0x14) = pcVar3;
        }
      }
      goto LAB_104253c2;
    }
  }
  else {
    g_arenas[0].cur = g_arenas[0].cur + 0x10;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    if (pcVar4 != (c1_u8 *)0x0) {
      *(c1_symbol **)(pcVar4 + 4) = sym;
      pcVar4[8] = '\x01';
      pcVar4[0xc] = '\0';
      pcVar4[0xd] = '\0';
      pcVar4[0xe] = '\0';
      pcVar4[0xf] = '\0';
      *(undefined ***)pcVar4 = &PTR_tmpl_instance_members_run_104c4c44;
      goto LAB_104253c2;
    }
  }
  pcVar4 = (c1_u8 *)0x0;
LAB_104253c2:
  if (*(int *)queue != 0) {
    *(c1_u8 **)(*(int *)((int)queue + 4) + 0xc) = pcVar4;
    *(c1_u8 **)((int)queue + 4) = pcVar4;
    return;
  }
  *(c1_u8 **)queue = pcVar4;
  *(c1_u8 **)((int)queue + 4) = pcVar4;
  return;
}

