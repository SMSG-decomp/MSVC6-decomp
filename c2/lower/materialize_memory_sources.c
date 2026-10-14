void __fastcall materialize_memory_sources(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  
  pcVar1 = t->src;
  if (pcVar1->kind == '\x06') {
    pcVar2 = tuple_new_unary_temp(1,pcVar1->type,pcVar1,tuple_insert_before,t);
    tuple_replace_src(t,t->src,pcVar2->dst);
  }
  pcVar1 = t->src->next;
  if (pcVar1->kind == '\x06') {
    pcVar2 = tuple_new_unary_temp(1,pcVar1->type,pcVar1,tuple_insert_before,t);
    tuple_replace_src(t,t->src->next,pcVar2->dst);
  }
  return;
}

