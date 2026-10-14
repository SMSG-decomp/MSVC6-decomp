void sched_add_source_deps_part(c2_operand *opnd)

{
  if (opnd->next == (c2_operand *)0x0) {
    return;
  }
  (*sched_add_source_deps_jump_table[opnd->next->kind - 1])();
  return;
}

