void __fastcall insert_branch_value_facts_late(c2_function *fn)

{
  c2_tuple *t;
  c2_block *block;
  
  block = (c2_block *)fn;
  for (t = fn->cfg->first->head; t != (c2_tuple *)0x0; t = t->next) {
    if (t->kind == '\x19') {
      block = (t->u14).block;
    }
    if ((t->op == 0x17d) || (t->op == 0x1ab)) {
      insert_branch_value_facts_late_one(fn,t,block);
    }
  }
  return;
}

