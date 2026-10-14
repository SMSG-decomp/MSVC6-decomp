void __fastcall number_compare_expression(c2_tuple *t)

{
  c2_tuple *pcVar1;
  uint32_t op;
  c2_symbol *pcVar2;
  c2_operand *a;
  c2_operand *b;
  c2_operand *local_4;
  
  local_4 = (c2_operand *)t;
  pcVar1 = find_next_use_of_symbol((c2_node *)t,t->dst->sym,&local_4);
  if ((pcVar1 != (c2_tuple *)0x0) && (pcVar1->kind == '\x11')) {
    a = t->src;
    b = a->next;
    op = expr_table_dispatch_by_kind((uint8_t)pcVar1->type);
    pcVar2 = cse_find_or_make(op,t->type,a,b);
    (t->u14).expr = pcVar2;
  }
  return;
}

