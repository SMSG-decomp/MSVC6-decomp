void __cdecl tmpl_merge_default_arguments(c1_arg_list *defaults,c1_symbol *tmpl)

{
  byte bVar1;
  c1_arg_item *pcVar2;
  c1_arg_item *pcVar3;
  c1_arg_list *defaults_00;
  int *piVar4;
  c1_arg_list *pcVar5;
  c1_arg_item *pcVar6;
  
  piVar4 = tmpl_default_arguments_lookup(tmpl);
  if (piVar4 == (int *)0x0) {
    tmpl_set_default_arguments(defaults,tmpl);
    return;
  }
  pcVar2 = (c1_arg_item *)*piVar4;
  pcVar3 = defaults->first;
  defaults_00 = (c1_arg_list *)0x0;
  pcVar5 = (c1_arg_list *)g_arenas[0].cur;
  do {
    g_arenas[0].cur = (c1_u8 *)pcVar5;
    if (pcVar2 == (c1_arg_item *)0x0) {
      if (pcVar3 != (c1_arg_item *)0x0) {
        defaults_00->last->next = pcVar3;
        pcVar3->prev = defaults_00->last;
        defaults_00->last = pcVar3;
        bVar1 = pcVar3->kind;
joined_r0x104b77cf:
        if ((bVar1 & 8) != 0) {
          defaults_00->flags = defaults_00->flags | 1;
        }
      }
LAB_104b77d5:
      tmpl_set_default_arguments(defaults_00,tmpl);
      return;
    }
    if (pcVar3 == (c1_arg_item *)0x0) {
      if (pcVar2 == (c1_arg_item *)0x0) goto LAB_104b77d5;
      defaults_00->last->next = pcVar2;
      pcVar2->prev = defaults_00->last;
      defaults_00->last = pcVar2;
      bVar1 = pcVar2->kind;
      goto joined_r0x104b77cf;
    }
    if (((pcVar2->kind & 3) == 2) || ((pcVar3->kind & 3) != 2)) {
      pcVar6 = pcVar3;
      if (defaults_00 != (c1_arg_list *)0x0) {
        defaults_00->last->next = pcVar3;
        pcVar3->prev = defaults_00->last;
        defaults_00->last = pcVar3;
        bVar1 = pcVar3->kind;
        goto joined_r0x104b786b;
      }
      g_arenas[0].cur = (c1_u8 *)(pcVar5 + 1);
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      if (pcVar5 == (c1_arg_list *)0x0) goto LAB_104b77e8;
      pcVar5->first = pcVar3;
      pcVar5->last = pcVar3;
      pcVar5->flags = (pcVar5->flags ^ pcVar3->kind >> 3 & 1) & 1 ^ pcVar5->flags;
    }
    else {
      pcVar6 = pcVar2;
      if (defaults_00 == (c1_arg_list *)0x0) {
        g_arenas[0].cur = (c1_u8 *)(pcVar5 + 1);
        if (g_arenas[0].end < g_arenas[0].cur) {
          arena_grow(g_arenas);
        }
        if (pcVar5 == (c1_arg_list *)0x0) {
LAB_104b77e8:
          pcVar5 = (c1_arg_list *)0x0;
        }
        else {
          pcVar5->first = pcVar2;
          pcVar5->last = pcVar2;
          pcVar5->flags = (pcVar5->flags ^ pcVar2->kind >> 3 & 1) & 1 ^ pcVar5->flags;
        }
      }
      else {
        defaults_00->last->next = pcVar2;
        pcVar2->prev = defaults_00->last;
        defaults_00->last = pcVar2;
        bVar1 = pcVar2->kind;
joined_r0x104b786b:
        pcVar5 = defaults_00;
        if ((bVar1 & 8) != 0) {
          defaults_00->flags = defaults_00->flags | 1;
        }
      }
    }
    pcVar2 = pcVar2->next;
    pcVar3 = pcVar3->next;
    pcVar6->next = (c1_arg_item *)0x0;
    defaults_00 = pcVar5;
    pcVar5 = (c1_arg_list *)g_arenas[0].cur;
  } while( true );
}

