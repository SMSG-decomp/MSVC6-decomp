c1_symbol * __thiscall block_scope_find_name(c1_sym_list *list,int name)

{
  c1_sym_link *pcVar1;
  c1_symbol *pcVar2;
  c1_symbol *pcVar3;
  byte bVar4;
  
  pcVar1 = list->head;
  while( true ) {
    if (pcVar1 == (c1_sym_link *)0x0) {
      return (c1_symbol *)0x0;
    }
    if (pcVar1->name == (fe_name *)name) break;
    pcVar1 = pcVar1->next;
  }
  pcVar3 = (c1_symbol *)&pcVar1[-1].position;
  if ((pcVar1[-1].position & 0x1f) != 0x1a) {
    return pcVar3;
  }
  if (g_current_scope->keep_aliases != '\0') {
    return pcVar3;
  }
  pcVar2 = ((pcVar1->type).alias)->target;
  bVar4 = pcVar2->kind & 0x1f;
  if (bVar4 == 0x10) {
    return pcVar3;
  }
  if (bVar4 == 7) {
    return pcVar3;
  }
  if (bVar4 == 6) {
    return pcVar3;
  }
  if (bVar4 == 0x11) {
    return pcVar3;
  }
  if (bVar4 == 8) {
    return pcVar3;
  }
  if (bVar4 == 0x1b) {
    return pcVar3;
  }
  if (bVar4 == 0x1a) {
    bVar4 = **(byte **)pcVar2->type & 0x1f;
    if (bVar4 == 0x10) {
      return pcVar3;
    }
    if (bVar4 == 7) {
      return pcVar3;
    }
    if (bVar4 == 6) {
      return pcVar3;
    }
    if (bVar4 == 0x11) {
      return pcVar3;
    }
    if (bVar4 == 8) {
      return pcVar3;
    }
    if (bVar4 == 0x1b) {
      return pcVar3;
    }
  }
  do {
    pcVar3 = *(c1_symbol **)pcVar3->type;
  } while ((pcVar3->kind & 0x1f) == 0x1a);
  return pcVar3;
}

