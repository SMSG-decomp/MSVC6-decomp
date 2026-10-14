void __fastcall insert_branch_value_facts(c2_function *fn)

{
  c2_tuple *t;
  uint32_t uVar1;
  c2_block *block;
  
  block = (c2_block *)fn;
  for (t = fn->cfg->first->head; t != (c2_tuple *)0x0; t = t->next) {
    if (t->kind == '\x19') {
      block = (t->u14).block;
    }
    uVar1 = t->op;
    if (((uVar1 == 0x17d) || (uVar1 == 0x18d)) || (uVar1 == 0x1ab)) {
      insert_branch_value_facts_one(fn,t,block);
    }
  }
  return;
}

