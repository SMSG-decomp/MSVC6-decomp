int __fastcall alias_offset_through_base(c2_symbol *s,c2_operand *mem)

{
  byte bVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  
  if (((1 << (mem->base->kind & 0x1f) & 6U) == 0) ||
     (pcVar2 = mem->base->sym->def, pcVar2 == (c2_tuple *)0x0)) {
    return 0;
  }
  if (pcVar2->op == 0x15b) {
    if ((pcVar2->src->kind == '\x06') && ((pcVar2->src->u18).reg == s)) {
      return 0;
    }
  }
  else if (pcVar2->op == 0x16d) {
    pcVar3 = pcVar2->src;
    bVar1 = pcVar3->kind;
    if (bVar1 == 7) {
      pcVar4 = pcVar3->next;
      bVar1 = pcVar4->kind;
      if (((1 << (bVar1 & 0x1f) & 6U) == 0) ||
         (pcVar2 = pcVar4->sym->def, pcVar2 == (c2_tuple *)0x0)) {
        if ((bVar1 == 2) && (pcVar4->sym == s)) {
          return (int)(pcVar3->u18).reg;
        }
        if ((bVar1 == 6) && ((pcVar4->u18).reg == s)) {
          return (int)(pcVar3->u18).reg;
        }
      }
      else if (((pcVar2->op == 0x15b) && (pcVar2->src->kind == '\x06')) &&
              ((pcVar2->src->u18).reg == s)) {
        return (int)(pcVar3->u18).reg;
      }
    }
    else {
      pcVar4 = pcVar3->next;
      if (pcVar4->kind == '\a') {
        if (((1 << (bVar1 & 0x1f) & 6U) == 0) ||
           (pcVar2 = pcVar3->sym->def, pcVar2 == (c2_tuple *)0x0)) {
          if ((bVar1 == 2) && (pcVar3->sym == s)) {
            return (int)(pcVar4->u18).reg;
          }
          if ((bVar1 == 6) && ((pcVar3->u18).reg == s)) {
            return (int)(pcVar4->u18).reg;
          }
        }
        else if (((pcVar2->op == 0x15b) && (pcVar2->src->kind == '\x06')) &&
                ((pcVar2->src->u18).reg == s)) {
          return (int)(pcVar4->u18).reg;
        }
      }
    }
  }
  return -1;
}

