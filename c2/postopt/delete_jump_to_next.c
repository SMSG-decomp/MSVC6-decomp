int __fastcall delete_jump_to_next(c2_tuple *jmp,c2_tuple **next)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  bool bVar3;
  c2_tuple *t;
  c2_tuple **ppcVar4;
  
  bVar3 = false;
  if ((jmp->flags & 8) == 0) {
    pcVar1 = jmp->next;
    ppcVar4 = next;
    for (pcVar2 = pcVar1; pcVar2 != (c2_tuple *)0x0; pcVar2 = pcVar2->next) {
      if ((bVar3) || (pcVar2->op != 0x18c)) {
        if ((pcVar2->flags & 1) != 0) {
          return 0;
        }
      }
      else {
        ppcVar4 = (c2_tuple **)0x1;
      }
      if (pcVar2->kind == '\x1a') {
        if (pcVar2 == *(c2_tuple **)((int)&jmp->src->sym->u30 + 2)) {
          branch_delete(jmp);
          if (ppcVar4 != (c2_tuple **)0x0) {
            while (t = pcVar1, t != pcVar2) {
              pcVar1 = t->next;
              if (t->op == 0x18c) {
                if ((next != (c2_tuple **)0x0) && (*next == t)) {
                  *next = (*next)->next;
                }
                tuple_unlink_free(t);
              }
            }
          }
          return 1;
        }
        if (*(int *)&pcVar2->src[1].type != 0) {
          bVar3 = true;
        }
      }
    }
  }
  return 0;
}

