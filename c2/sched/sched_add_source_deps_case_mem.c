void sched_add_source_deps_case_mem(c2_operand *opnd,c2_sched_node *n,c2_tuple *t)

{
  sched_memory_deps_on_stores(opnd,n,0x20);
  sched_add_source_deps_part(opnd);
  return;
}

