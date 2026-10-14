int __fastcall widen_iv_subfield_uses(c2_loop *loop)

{
  int iVar1;
  uint uVar2;
  c2_block *pcVar3;
  uint uVar4;
  c2_operand *node;
  c2_tuple *t;
  int local_8;
  
  pcVar3 = loop->first;
  iVar1 = 0;
  local_8 = 0;
  if (pcVar3 != loop->last->next) {
    do {
      t = pcVar3->head->next;
      if (t != pcVar3->end) {
        do {
          if ((t->flags & 1) != 0) {
            node = t->src;
            uVar4 = 0;
            if (node != (c2_operand *)0x0) {
              do {
                if ((node->kind == '\x02') && (node->sym != (c2_symbol *)0x0)) {
                  uVar2 = replace_iv_subfield_use(node,t);
                  uVar4 = uVar4 | uVar2;
                }
                node = node->next;
              } while (node != (c2_operand *)0x0);
              if (uVar4 != 0) {
                enter_tuple_in_expression_table(t,0);
                local_8 = 1;
              }
            }
          }
          t = t->next;
          iVar1 = local_8;
        } while (t != pcVar3->end);
      }
      pcVar3 = pcVar3->next;
    } while (pcVar3 != loop->last->next);
  }
  return iVar1;
}

