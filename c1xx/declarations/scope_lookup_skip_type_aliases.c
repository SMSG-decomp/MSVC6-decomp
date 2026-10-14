c1_symbol * __cdecl scope_lookup_skip_type_aliases(c1_sym_link *chain,void *name)

{
  c1_symbol *pcVar1;
  c1_symbol *pcVar2;
  byte bVar3;
  
  while( true ) {
    if (chain == (c1_sym_link *)0x0) {
      return (c1_symbol *)0x0;
    }
    if (chain->name == name) break;
    chain = chain->next;
  }
  pcVar2 = (c1_symbol *)&chain[-1].position;
  if ((chain[-1].position & 0x1f) != 0x1a) {
    return pcVar2;
  }
  if (g_current_scope->keep_aliases != '\0') {
    return pcVar2;
  }
  pcVar1 = ((chain->type).alias)->target;
  bVar3 = pcVar1->kind & 0x1f;
  if (bVar3 == 0x10) {
    return pcVar2;
  }
  if (bVar3 == 7) {
    return pcVar2;
  }
  if (bVar3 == 6) {
    return pcVar2;
  }
  if (bVar3 == 0x11) {
    return pcVar2;
  }
  if (bVar3 == 8) {
    return pcVar2;
  }
  if (bVar3 == 0x1b) {
    return pcVar2;
  }
  if (bVar3 == 0x1a) {
    bVar3 = **(byte **)pcVar1->type & 0x1f;
    if (bVar3 == 0x10) {
      return pcVar2;
    }
    if (bVar3 == 7) {
      return pcVar2;
    }
    if (bVar3 == 6) {
      return pcVar2;
    }
    if (bVar3 == 0x11) {
      return pcVar2;
    }
    if (bVar3 == 8) {
      return pcVar2;
    }
    if (bVar3 == 0x1b) {
      return pcVar2;
    }
  }
  do {
    pcVar2 = *(c1_symbol **)pcVar2->type;
  } while ((pcVar2->kind & 0x1f) == 0x1a);
  return pcVar2;
}

