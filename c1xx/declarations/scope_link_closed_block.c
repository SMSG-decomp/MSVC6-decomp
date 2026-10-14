void __thiscall scope_link_closed_block(c1_scope_stack *stack,c1xx_scope *block)

{
  c1xx_scope *pcVar1;
  c1xx_scope *pcVar2;
  c1xx_scope *pcVar3;
  c1xx_scope *pcVar4;
  
  if (block == (c1xx_scope *)0x0) {
    return;
  }
  pcVar2 = stack->closed_blocks;
  if (pcVar2 == (c1xx_scope *)0x0) goto LAB_10429d9f;
  pcVar3 = (c1xx_scope *)0x0;
  do {
    pcVar4 = pcVar2;
    pcVar1 = pcVar4;
    if (block->kind < pcVar4->kind) goto joined_r0x10429d8a;
    pcVar2 = pcVar4->outer;
    pcVar3 = pcVar4;
  } while (pcVar2 != (c1xx_scope *)0x0);
LAB_10429d9a:
  if (pcVar4 != (c1xx_scope *)0x0) {
    pcVar4->outer = block;
    block->outer = pcVar2;
    return;
  }
LAB_10429d9f:
  stack->closed_blocks = block;
  block->outer = pcVar2;
  return;
joined_r0x10429d8a:
  while ((pcVar4 = pcVar3, pcVar2 = pcVar1, pcVar2 != (c1xx_scope *)0x0 && (pcVar2->parent != block)
         )) {
    pcVar3 = pcVar2;
    pcVar1 = pcVar2->outer;
  }
  goto LAB_10429d9a;
}

