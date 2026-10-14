void __thiscall invert_branch_after_repair(c2_block *from,c2_function *fn)

{
  c2_loop *pcVar1;
  c2_block *pcVar2;
  c2_block *pcVar3;
  
  pcVar3 = invert_branch_over_jump_swap(from,fn);
  pcVar1 = pcVar3->loop;
  pcVar3 = from->next;
  pcVar2 = pcVar1->last;
  pcVar3->loop = pcVar1;
  if (pcVar2 == from) {
    pcVar1->last = pcVar3;
  }
  return;
}

