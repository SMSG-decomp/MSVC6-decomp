void __fastcall inline_drop_scope_end_marker(c2_tuple *t,c2_tuple *body)

{
  c2_operand *pcVar1;
  uint32_t uVar2;
  c2_tuple *pcVar3;
  
  if (g_opt_global != 0) {
    while ((body != (c2_tuple *)0x0 &&
           ((((body->flags & 1) == 0 || (body->flags12 != '\0')) ||
            ((pcVar1 = body->dst, pcVar1 != (c2_operand *)0x0 &&
             (((1 << (pcVar1->kind & 0x1f) & 6U) != 0 && (pcVar1->sym->def != (c2_tuple *)0x0)))))))
           )) {
      body = body->next;
    }
    uVar2 = t->op;
    while (uVar2 != 0x1b1) {
      pcVar3 = t->next;
      if (t->op == 0x1b5) {
        tuple_unlink(t);
        tuple_insert_after(body,t);
        body = t;
      }
      t = pcVar3;
      uVar2 = pcVar3->op;
    }
  }
  return;
}

