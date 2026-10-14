int __fastcall is_rematerializable_def(c2_tuple *t)

{
  c2_operand *n;
  int iVar1;
  
  if (t->op == 0x163) {
    return 0;
  }
  if ((t->flags12 & 2) == 0) {
    if (t->dst->next != (c2_operand *)0x0) {
      return 0;
    }
    iVar1 = node_has_side_effects((c2_node *)t->dst);
    if (iVar1 == 0) {
      n = t->src;
      while( true ) {
        if (n == (c2_operand *)0x0) {
          return 1;
        }
        iVar1 = node_has_side_effects((c2_node *)n);
        if ((iVar1 != 0) ||
           ((n->kind == '\x01' &&
            (((((n->u18).reg)->cls != '\x02' || ((n->flags11 & 0x10) != 0)) ||
             ((((n->u18).reg)->flags5 & 0x10) != 0)))))) break;
        n = n->next;
      }
    }
    return 0;
  }
  return 0;
}

