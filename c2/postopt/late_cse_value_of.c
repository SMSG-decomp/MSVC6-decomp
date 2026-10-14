c2_operand * __fastcall late_cse_value_of(c2_tuple *t,c2_symbol **reg)

{
  uint8_t uVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  
  switch(t->op) {
  case 1:
    if (t->dst->kind == '\x01') {
      pcVar3 = t->src;
      uVar1 = pcVar3->kind;
      if ((uVar1 == '\a') || (uVar1 == '\x03')) {
        *reg = (c2_symbol *)t->dst->u18;
        return pcVar3;
      }
    }
    break;
  case 0xc:
    if (((t->dst->kind == '\x01') && (t->prev->op == 0xd)) &&
       (pcVar3 = t->prev->src, pcVar3->kind == '\a')) {
      *reg = (c2_symbol *)t->dst->u18;
      return pcVar3;
    }
    break;
  case 0x2f:
    pcVar3 = t->src;
    if (((pcVar3->kind == '\x01') && (pcVar2 = pcVar3->next, pcVar2->kind == '\a')) &&
       ((t->next->op == 0xf && (((char)t->next->type == '\x02' && ((t->flags & 4) == 0)))))) {
      *reg = (c2_symbol *)pcVar3->u18;
      return pcVar2;
    }
    break;
  case 0x33:
    pcVar3 = t->src;
    if ((((pcVar3->kind == '\x01') && (pcVar2 = pcVar3->next, pcVar2->kind == '\x01')) &&
        (((pcVar3->u18).reg == (pcVar2->u18).reg ||
         (((pcVar2->sym->cls == '\r' &&
           (pcVar2 = (pcVar2->sym->u28).const_operand, pcVar2->kind == '\a')) &&
          ((pcVar2->u18).reg == (c2_symbol *)0x0)))))) &&
       (((t->next->op == 0xf && ((char)t->next->type == '\x02')) && ((t->flags & 4) == 0)))) {
      *reg = (pcVar3->u18).reg;
      return g_late_cse_int_zero;
    }
    break;
  case 0x34:
    pcVar3 = t->src;
    if (((pcVar3->kind == '\x01') && (pcVar3->next->kind == '\x01')) &&
       ((pcVar3->u18).reg == (pcVar3->next->u18).reg)) {
      pcVar3 = g_late_cse_int_zero;
      *reg = (c2_symbol *)t->dst->u18;
      return pcVar3;
    }
  }
  return (c2_operand *)0x0;
}

