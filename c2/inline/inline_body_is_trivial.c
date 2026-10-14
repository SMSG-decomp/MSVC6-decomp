int __fastcall inline_body_is_trivial(c2_tuple *t)

{
  int iVar1;
  c2_tuple *pcVar2;
  
  pcVar2 = t->next;
  iVar1 = 1;
  if (pcVar2->kind != '\x18') {
    while (pcVar2 != t) {
      if ((pcVar2->flags & 1) != 0) {
        if (pcVar2->op != 0x186) break;
        pcVar2 = *(c2_tuple **)((int)&pcVar2->src->sym->u30 + 2);
      }
      pcVar2 = pcVar2->next;
      if (pcVar2->kind == '\x18') {
        return iVar1;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}

